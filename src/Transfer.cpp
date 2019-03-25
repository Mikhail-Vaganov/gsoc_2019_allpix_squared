#include "Transfer.hpp"

#include <iostream>

namespace framework
{
    Transfer::Transfer()
    {
        name = "Transfer";
    };

    Transfer::Transfer(int innerPrngSeed) : Module(innerPrngSeed)
    {
        name = "Transfer";
    };

} // namespace framework