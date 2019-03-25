#include "Module.hpp"
#include <iostream>
#include <thread>
#include <string>

using namespace std;

namespace framework
{
    Module::Module():name("Module"){};

    Module::Module(int innerPrngSeed)
    {
        prng.seed(innerPrngSeed);
        name = "Module";
    }

    Module::~Module() {}

    string Module::run(int innerPrngSeed)
    {
        int first_random_number;
        int second_random_number;

        {
            lock_guard<mutex> locker(mt);
            prng.seed(innerPrngSeed);
            first_random_number = prng();
            second_random_number = prng();
        }

        return name + " " + std::to_string(first_random_number) + " " + std::to_string(second_random_number) + "\n";
    }
}; // namespace framework