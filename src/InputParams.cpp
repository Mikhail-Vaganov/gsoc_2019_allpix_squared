#include <string>
#include <iostream>
#include <stdexcept>

#include "InputParams.hpp"

namespace framework
{

int InputParams::parse_integer_input_argument(char *carg)
{
    std::string arg(carg);
    try
    {
        std::size_t pos;
        int value = std::stoul(arg, &pos);
        if (pos < arg.size())
            std::cerr << "Trailing characters after number: " << arg << std::endl;

        return value;
    }
    catch (std::invalid_argument const &ex)
    {
        std::cerr << "Invalid number: " << arg << std::endl;
        throw;
    }
    catch (std::out_of_range const &ex)
    {
        std::cerr << "Number is out of range: " << arg << std::endl;
        throw;
    }
}

InputParams::InputParams(int argc, char **args) : number_of_iteration(_number_of_iteration),
                                                  number_of_workers(_number_of_workers),
                                                  main_prng_seed(_main_prng_seed)
{

    if (argc > 1)
    {
        int arg_value = parse_integer_input_argument(args[1]);
        if (arg_value > 0)
        {
            _number_of_iteration = arg_value;
        }
        else
        {
            std::cerr << "Number of interation should be a positive integer" << std::endl;
            std::cerr << "Number of interation was set to 1" << std::endl;
        }
    }

    if (argc > 2)
    {
        int arg_value = parse_integer_input_argument(args[2]);
        if (arg_value > 0)
        {
            _number_of_workers = arg_value;
        }
        else
        {
            std::cerr << "Number of workers should be a positive integer" << std::endl;
            std::cerr << "Number of workers was set to 1" << std::endl;
        }
    }

    if (argc > 3)
    {
        int arg_value = parse_integer_input_argument(args[3]);
        _main_prng_seed = arg_value;
    }
}

} // namespace framework