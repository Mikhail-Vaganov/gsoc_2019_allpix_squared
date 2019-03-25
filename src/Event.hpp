#ifndef EVENT_H
#define EVENT_H

#include <random>
#include <future>
#include <string>

#include "ModuleSet.hpp"

namespace framework
{
    class Event
    {
        private:

            ModuleSet& module_set;
            int main_seed;

        public:

            string operator()();
            Event(ModuleSet& ms, int main_seed);
    };
} // namespace framework
#endif