#include <random>
#include <string>

#include "Event.hpp"
#include "Deposition.hpp"

namespace framework
{

    std::string Event::operator()()
    {
        std::string result_of_event_simulation;
        for(int i=0; i<this->module_set.size(); i++) 
        {
            result_of_event_simulation += module_set[i]->run(main_seed);
        }
        return result_of_event_simulation;
    }

    Event::Event(ModuleSet& ms, int seed) : module_set(ms), main_seed(seed){ }

}; // namespace framework