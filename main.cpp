//
//  main.cpp
//  Post Fix Calculator
//
//  Created by Robert Mitchell on 3/24/15.
//  Copyright (c) 2015 Robert Mitchell. All rights reserved.
//

#include <iostream>
#include "post_fix.h"

int main(int argc, const char * argv[])
{

    std::string ex; // expression
    post_fix pfix;

    while (true)
    {
        getline(std::cin, ex);
        std::cout << "\n" << pfix.compute(ex) << "\n\n";
    }
    return 0;
}
