#include "Reporter.hpp"

#include <iostream>
#include <string>
#include <mutex>

namespace framework
{

Reporter::Reporter() : active(false), force_stop(false)
{
}

Reporter::~Reporter()
{
    stop();
}

void Reporter::start()
{
    //auto h = result_queue.empty();

    std::thread report_writer([this]() {
        active = true;

        while (1)
        {
            auto fut = this->result_queue.wait_and_pop();

            std::lock_guard<std::mutex> locker(cout_mutex);
            std::cout << fut->get() << std::endl;
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

}; // namespace framework