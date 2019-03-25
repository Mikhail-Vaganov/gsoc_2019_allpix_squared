#include "Reporter.hpp"

#include <iostream>
#include <string>
#include <mutex>

namespace framework
{

Reporter::Reporter() : active(false), force_stop(false), count(0), count_limit(-1)
{
}

Reporter::~Reporter()
{
    stop();
}

void Reporter::start()
{
    std::thread report_writer([this]() {
        active = true;

        while (1)
        {
            auto fut = this->result_queue.wait_and_pop();

            std::lock_guard<std::mutex> locker(cout_mutex);
            std::cout << fut->get() << std::endl;
            count++;
            if (count == count_limit)
                coun_reached_value.notify_all();
        }

        active = false;
    });
    report_writer.detach();
}

void Reporter::stop()
{
    force_stop = true;
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