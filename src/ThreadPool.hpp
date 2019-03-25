#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>
#include <atomic>
#include <future>
#include <string>

#include "ConcurrentQueue.hpp"
#include "JoinThreads.hpp"

namespace framework
{
class ThreadPool
{

    std::atomic_bool done;
    ConcurrentQueue<std::packaged_task<std::string()>> work_queue;
    std::vector<std::thread> threads;
    JoinThreads joiner;
    void worker_thread()
    {
        while (!done)
        {
            std::packaged_task<std::string()> task;
            if (work_queue.try_pop(task))
            {
                task();
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }

  public:
    ThreadPool() : done(false), joiner(threads)
    {
        unsigned const thread_count = std::thread::hardware_concurrency();
        initialize(thread_count);
    }

    ThreadPool(int thread_count) : done(false), joiner(threads)
    {
        initialize(thread_count);
    }

    ~ThreadPool()
    {
        done = true;
    }

    void submit(std::packaged_task<std::string()> task)
    {
        work_queue.push(move(task));
    }

  private:
    void initialize(int thread_count)
    {
        try
        {
            for (unsigned i = 0; i < thread_count; ++i)
            {
                threads.push_back(
                    std::thread(&ThreadPool::worker_thread, this));
            }
        }
        catch (...)
        {
            done = true;
            throw;
        }
    }
}; 
} // namespace framework

#endif