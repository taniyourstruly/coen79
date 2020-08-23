//
//  random.cpp
//  
//
//  Created by Tania Pham on 4/16/20.
//

#include <stdio.h>
#include <iostream>
#include "random.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2
{
    void rand_gen::set_seed(int newSeed)
    {
        seed = newSeed; //setter method to access seed variable
    }
    int rand_gen::next()
    {
        seed = (multiplier*seed+increment)%mod;
        return seed; //getter method to return value of seed
    }
    void rand_gen::print_info()
    {
        cout << "Seed: " << seed << endl;
        cout << "Multiplier: " << multiplier << endl;
        cout << "Increment: " << increment << endl;
        cout << "Mod: " << mod << endl;
    }
}
