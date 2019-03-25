#include "Propagation.hpp"

#include <iostream>

using namespace std;

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