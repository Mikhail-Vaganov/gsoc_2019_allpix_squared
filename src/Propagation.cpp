#include "Propagation.hpp"

#include <iostream>

namespace framework
{
    Propagation::Propagation()
    {
        name = "Propagation";
    };

    Propagation::Propagation(int innerPrngSeed) : Module(innerPrngSeed)
    {
        name = "Propagation";
    };

} // namespace framework