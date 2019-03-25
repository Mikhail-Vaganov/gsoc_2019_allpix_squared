#ifndef DIGITIZER_H
#define DIGITIZER_H

#include "Module.hpp"

namespace framework
{
    class Digitizer : public Module
    {
        public:
            Digitizer(int innerPrngSeed);
            Digitizer();
    };
} // namespace framework
#endif