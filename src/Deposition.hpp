#ifndef DEPOSITION_H
#define DEPOSITION_H

#include "Module.hpp"

namespace framework
{
    class Deposition : public Module
    {
        public:
            Deposition(int innerPrngSeed);
            Deposition();
    };
} // namespace framework
#endif