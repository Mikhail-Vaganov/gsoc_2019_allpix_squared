#ifndef A2DD_H
#define A2DD_H

#include <random>

using namespace std;

namespace framework
{
    class Module
    {
        protected:
            mt19937_64 prng;
            string name;
            mutex mt;
        public:
            Module();
            Module(int innerPrngSeed);
            virtual ~Module();
            virtual string run(int innerPrngSeed);
    };
};

#endif