#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include "Module.hpp"
#include <random>

using namespace std;


int main()
{
    mt19937 mt(1);
    
    for(int i=0; i<100; i++)
    {
        cout << "Random number: " << mt() << "\n";
    }

    vector<std::thread> workers;   // t starts running
    
    for(int i = 0; i<100; i++)
    {
        workers.push_back(std::thread([i]()
        {
            std::cout << i << "  ";
        }));
    }
    

    std::for_each(workers.begin(), workers.end(), [](std::thread &t){
        t.join();
    });
    std::cout << "main thread\n";
    return 0;
}