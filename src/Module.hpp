#ifndef A2DD_H
#define A2DD_H

#include <random>
#include <mutex>
#include <string>

namespace framework
{
    class Module
    {
        protected:
            std::mt19937_64 prng;
            std::string name;
            std::mutex mt;
        public:
            Module();
            Module(int innerPrngSeed);
            virtual ~Module();
            virtual std::string run(int innerPrngSeed);
    };
};

#endif