#include "ModuleSet.hpp"

#include "Module.hpp"
#include "Deposition.hpp"
#include "Propagation.hpp"
#include "Transfer.hpp"
#include "Digitizer.hpp"

#include <vector>
#include <memory>
#include <iostream>

namespace framework
{
    ModuleSet::ModuleSet()
    {
        modules.push_back(std::make_shared<Deposition>());
        modules.push_back(std::make_shared<Propagation>());
        modules.push_back(std::make_shared<Transfer>());
        modules.push_back(std::make_shared<Digitizer>());
    }

    const std::vector<std::shared_ptr<Module>> ModuleSet::get_modules()
    {
        return modules;
    }

    std::shared_ptr<Module> ModuleSet::operator[](int i)
    {
        return modules[i];
    }

    int ModuleSet::size()
    {
        return modules.size();
    }

} // namespace framework