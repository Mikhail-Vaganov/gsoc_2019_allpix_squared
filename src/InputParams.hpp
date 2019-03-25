#ifndef INPUT_PARAMS_H
#define INPUT_PARAMS_H

namespace framework
{
    class InputParams
    {

    public:
        InputParams(int argc, char **args);
        const unsigned int &number_of_iteration;
        const unsigned int &number_of_workers;
        const int &main_prng_seed;

    private:
        unsigned int _number_of_iteration = 1;
        unsigned int _number_of_workers = 1;
        int _main_prng_seed = 1;

        int parse_integer_input_argument(char *carg);
    };
} // namespace framework
#endif