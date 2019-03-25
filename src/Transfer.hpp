#ifndef TRANSFER_H
#define TRANSFER_H

#include "Module.hpp"

namespace framework
{
    class Transfer : public Module
    {
        public:
            Transfer(int innerPrngSeed);
            Transfer();
    };
} // namespace framework
#endif