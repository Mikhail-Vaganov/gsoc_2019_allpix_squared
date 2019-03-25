#ifndef REPORTER_H
#define REPORTER_H

#include "ConcurrentQueue.hpp" 

#include <future>
#include <string>
#include <condition_variable>
#include <mutex>

namespace framework
{
    class Reporter
    {
        private:
            std::atomic<bool> active;
            ConcurrentQueue<std::future<std::string>> result_queue;
            std::atomic<bool> force_stop;
            std::mutex cout_mutex;
            std::atomic<int> count;
            std::atomic<int> count_limit;
            std::condition_variable coun_reached_value;
        public:
            Reporter();
            void start();
            void stop();
            void push(std::future<std::string> future_message);
            ~Reporter();
            bool queue_is_empty();
            int get_count();
            void wait_for_count_reached_value(int value);
    };
}
#endif