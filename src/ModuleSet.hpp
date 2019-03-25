#ifndef MODULE_SET_H
#define MODULE_SET_H

#include "Module.hpp"

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
            ModuleSet();
            const std::vector<std::shared_ptr<Module>> get_modules();
            std::shared_ptr<Module> operator[](int i);
            int size();
    };
}
#endif