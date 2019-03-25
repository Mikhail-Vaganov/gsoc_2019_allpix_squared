#include "Digitizer.hpp"

#include <iostream>

namespace framework
{
    Digitizer::Digitizer()
    {
        name = "Digitizer";
    };

    Digitizer::Digitizer(int innerPrngSeed) : Module(innerPrngSeed)
    {
        name = "Digitizer";
    };

} // namespace framework