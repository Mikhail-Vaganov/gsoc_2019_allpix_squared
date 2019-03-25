#include "Reporter.hpp"

#include <iostream>
#include <string>
#include <mutex>

namespace framework
{

Reporter::Reporter() : active(false), done(false), count(0), count_limit(-1)
{
}

Reporter::~Reporter()
{
    stop();

    for(int i=0; i < reporting_threads.size(); i++)
    if(reporting_threads[i].joinable())
        reporting_threads[0].join();
}

void Reporter::start()
{
    reporting_threads.push_back(std::thread([this]() {
        active = true;

        while (!done)
        {
            std::future<std::string> fut;

            if (this->result_queue.try_pop(fut))
            {
                std::lock_guard<std::mutex> locker(cout_mutex);
                std::cout << fut.get() << std::endl;
                count++;
                if (count == count_limit)
                    coun_reached_value.notify_all();
            }
            else
            {
                std::this_thread::yield();
            }
        }

        active = false;
    }));
}

void Reporter::stop()
{
    done = true;
}

void Reporter::push(std::future<std::string> future_message)
{
    result_queue.push(move(future_message));
}

bool Reporter::queue_is_empty()
{
    std::lock_guard<std::mutex> locker(cout_mutex);
    return result_queue.empty();
}

int Reporter::get_count()
{
    return count;
}

void Reporter::wait_for_count_reached_value(int value)
{
    std::unique_lock<std::mutex> locker(cout_mutex);
    
    count_limit = value;
    
    if (count >= count_limit)
        return;
    else 
        coun_reached_value.wait(locker, [this, value]() { return count >= value; });
    
    locker.unlock();
}

}; // namespace framework