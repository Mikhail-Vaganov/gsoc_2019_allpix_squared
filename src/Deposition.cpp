#include "Deposition.hpp"

#include <iostream>

namespace framework
{
    Deposition::Deposition()
    {
        name = "Deposition";
    };

    Deposition::Deposition(int innerPrngSeed) : Module(innerPrngSeed)
    {
        name = "Deposition";
    };

} // namespace framework