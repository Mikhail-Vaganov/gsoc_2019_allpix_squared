#include "Module.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <string>

namespace framework
{
    Module::Module():name("Module"){};

    Module::Module(int innerPrngSeed)
    {
        prng.seed(innerPrngSeed);
        name = "Module";
    }

    Module::~Module() {}

    std::string Module::run(int innerPrngSeed)
    {
        int first_random_number;
        int second_random_number;

        {
            std::lock_guard<std::mutex> locker(mt);
            prng.seed(innerPrngSeed);
            first_random_number = prng();
            second_random_number = prng();
        }

        return name + "\t" + std::to_string(first_random_number) + "\t" + std::to_string(second_random_number) + "\n";
    }
}; // namespace framework