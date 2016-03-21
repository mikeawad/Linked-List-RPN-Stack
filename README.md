Do Programming Problem 12 at the end of Chapter 7 in the Nyhoff textbook (page 387-388). You do not have to print the trace - just print the value of the expression.

I just want you to implement the basic algorithm described on page 373 of your textbook. You must include all error-checking described in the algorithm in the book. If an error is detected, print an appropriate error message, discard the rest of the expression, and ask the user if they want another expression.

To simplify the input, you can assume that all operands are non-negative single-digit integers. You may want to allow the user to type blanks between all operators and operands. In other words, the user might input "2 3 +" or "23+".

Use the linked-list version of the Stack class from Figure 7.12 of the textbook. Source code for examples in the textbook can be found at the author's web site and under the Examples link:

http://cs.calvin.edu/books/c++/ds/2e/

The source code for Figure 7.12 is here:

http://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap07/Figure7.12/

Your driver program should have a loop that allows the user to evaluate multiple expressions. For example, your output might look like:

Enter postfix expression:2 3 4 + *
The value of the expression is 14
More expressions (Y or N)? Y
Enter postfix expression:5 2 + 2 /
The value of the expression is 3
More expressions (Y or N)? N

Hints:

The user should enter an expression on a single line. You can either read the line one character at a time, or you can read the line into a string and then process the string one character at a time.
The tokens on a line are the operators '+', '-', '*', '/' and the digits '0' - '9'. One way to convert a character that is a digit to an integer is:
char token;
int value;
if ( token is an operand ) 
    value = token - 48; // the ASCII code for '0' is 48, '1' is 49, etc.
