#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "Module.hpp"

namespace framework
{
    class Propagation : public Module
    {
        public:
            Propagation(int innerPrngSeed);
            Propagation();
    };
} // namespace framework
#endif