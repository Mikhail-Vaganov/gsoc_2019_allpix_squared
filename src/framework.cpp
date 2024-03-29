#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <future>
#include <random>
#include <queue>

#include "Module.hpp"
#include "Deposition.hpp"
#include "ConcurrentQueue.hpp"
#include "Reporter.hpp"
#include "Event.hpp"
#include "ModuleSet.hpp"
#include "InputParams.hpp"
#include "ThreadPool.hpp"

using namespace framework;

int main(int argc, char **args)
{
    InputParams params(argc, args);

    Reporter reporter;
    reporter.start();

    std::mt19937_64 mt(params.main_prng_seed);
    ModuleSet ms;

    ThreadPool tp(params.number_of_workers);

    std::vector<std::thread> tt;

    for(int i=0; i<params.number_of_iteration; i++)
    {
        Event e(ms, mt());
        std::packaged_task<std::string()> task(e);
        reporter.push(task.get_future());
        tp.submit(move(task));
    }

    reporter.wait_for_count_reached_value(params.number_of_iteration);
    //while (reporter.get_count()!=params.number_of_iteration )
      //  std::this_thread::yield();

    return 0;
}
