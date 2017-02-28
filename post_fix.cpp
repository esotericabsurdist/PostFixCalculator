//
//  post_fix.cpp
//  Post Fix Calculator
//
//  Created by Robert Mitchell on 3/24/15.
//  Copyright (c) 2015 Robert Mitchell. All rights reserved.
//

#include "post_fix.h"


post_fix::post_fix(){}
post_fix::~post_fix(){}

//=============================================================
float post_fix::compute(std::string ex)
/* Recieves: post fix expression as a std::string value.
   Returns: result of expression.
*/
{
    empty_stack(); // make sure no remnants from old calculations.
    this->expression = ex;

    while(true)
    {
        if(is_space(expression.at(0))) // Erase the space.
        {
            expression.erase(0,1);
        }
        if(is_dollar_sign(expression.at(0))) // If we hit a dollar sign return.
        {
            return stack.top();
        }
        else if(is_digit_or_decimal(expression.at(0))) // If it's a value, push it onto the stack.
        {
            push_value();
        }
        else if(is_operator(expression.at(0))) // If it's an operator, perform the operation on the stack.
        {
            perform_operation();
        }
    }

    return stack.top();
}
//=============================================================
void post_fix::push_value()
{
    std::string sub_str = "";

    /* Build substring "sub_string" representing integer value */
    for(int i = 0; is_digit_or_decimal(expression.at(i)); i++)
    {
        sub_str += expression.at(i);
    }

    int sub_str_length = (int)sub_str.length();

    /* value  will be pushed onto stack */
    float value = std::stof(sub_str); // convert substring.

    /* Neat: For each digit in str_int multiple by 10^n where n is the place value.
     eg. tens n = 1, hundreds n = 2, ect.  */
    /* for(int n = sub_str_length; n > 0; n--)
    {
        int temp_value = ((int)sub_str.at(sub_str_length-n))- 48; // single digit value. eg ASCII '3' becomes (int) 3
        int place_value = n-1; // Note: hundreds place has three digits, but as a power of ten: 10^(n-1) --> 10^(3-1)
        value += ((temp_value)*pow(10, (double)(place_value))); // Bam!
    }*/

    /* Push value onto stack */
    stack.push(value);


    /* Subtract substring from front of expression */
    expression.erase((size_t)0, sub_str_length);

}
//=============================================================
void post_fix::perform_operation()
{
    float temp_result = 0;
    float left_operand = 0;
    float right_operand = 0;

    if(expression.at(0) == 42)
    {
        left_operand += stack.top();
        stack.pop();
        right_operand += stack.top();
        stack.pop();

        temp_result = left_operand * right_operand;
    }
    else if(expression.at(0) == 43)
    {
        left_operand += stack.top();
        stack.pop();
        right_operand += stack.top();
        stack.pop();

        temp_result = left_operand + right_operand;
    }
    else if(expression.at(0) == 45)
    {
        right_operand += stack.top();
        stack.pop();
        left_operand += stack.top();
        stack.pop();

        temp_result = left_operand - right_operand;
    }
    else if(expression.at(47) == 47)
    {
        right_operand += stack.top();
        stack.pop();
        left_operand += stack.top();
        stack.pop();

        temp_result = left_operand / right_operand;
    }

    // Push result onto stack
    stack.push(temp_result);

    // Erase operator
    expression.erase(0, 1);
}
//=============================================================
bool post_fix::is_digit_or_decimal(char c)
{
    if(((c >= 48) && (c <= 57)) || c == 46)
        return true;
    else
        return false;
}
//=============================================================
bool post_fix::is_operator(char c)
{
    if(c == 42 )// 42 == *
        return true;
    else if( c == 43 )// 43 == +
        return true;
    else if( c == 45 )// 45 == -
        return true;
    else if( c == 47 )// 47 == /
        return true;
    else
        return false;
}
//=============================================================
bool post_fix::is_space(char c)
{
    if(c == 32) // 32 == space
        return true;
    else
        return false;
}
//=============================================================
bool post_fix::is_dollar_sign(char c)
{
    if(c == 36) // 36 == $
        return true;
    else
        return false;
}
//=============================================================
void post_fix::empty_stack()
{
    while(!stack.empty())
    {
        stack.pop();
    }
}
//=============================================================
