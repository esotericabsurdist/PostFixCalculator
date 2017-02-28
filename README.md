# Post Fix Calculator
This is a post fix calculator, also called a Reverse Polish Notation Calculator
or RPN. It utilizes a stack. It supports integers and decimals. Its supported
operations are:
multiplication: *
division: /
addition: +
subtraction: -


##Compilation:
```
g++ main.cpp post_fix.cpp
```


##Example:
To use, terminate each expression with a delimiting '$' character.
```
23.1 2 * 3 + 4 4 - + $

49.2

4 2 + $

6
```
