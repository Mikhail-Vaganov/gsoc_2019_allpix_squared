#ifndef MODULE_SET_H
#define MODULE_SET_H

#include "Module.hpp"
#include "Deposition.hpp"
#include "Propagation.hpp"

#include <vector>
#include <memory>
#include <iostream>

namespace framework
{
    class ModuleSet
    {
        private:
            std::vector<std::shared_ptr<Module>> modules;
        
        public:
            ModuleSet()
            {
                modules.push_back(std::make_shared<Deposition>());
                modules.push_back(std::make_shared<Propagation>());
            }

            const vector<std::shared_ptr<Module>> get_modules()
            {
                return modules;
            }

            std::shared_ptr<Module> operator[](int i)
            {
                return modules[i];
            }

            int size()
            {
                return modules.size();
            }
    };
}
#endif 