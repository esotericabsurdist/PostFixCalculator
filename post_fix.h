//
//  post_fix.h
//  Post Fix Calculator
//
//  Created by Robert Mitchell on 3/24/15. 
//  Copyright (c) 2015 Robert Mitchell. All rights reserved.
//

#ifndef __Post_Fix_Calculator__post_fix__
#define __Post_Fix_Calculator__post_fix__

#include <stdio.h>
#include <stack>
#include <string>
#include <cmath>
#include <iostream>

class post_fix
{
private:
    /*      members     */
    std::stack<float> stack;
    std::string expression;

    /* Helper functions */
    void push_value();
    void perform_operation();
    bool is_digit_or_decimal(char c);
    bool is_operator(char c);
    bool is_space(char c);
    bool is_dollar_sign(char c);
    void empty_stack();
    /* - - - - - - - - -*/
public:

    post_fix();
    ~post_fix();
    float compute(std::string ex);
};

#endif /* defined(__Post_Fix_Calculator__post_fix__) */
