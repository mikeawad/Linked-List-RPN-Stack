/*---------------------------------------------------------------------
                  Driver program to test the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LStack.h"
#include <string>

using namespace std;



int main()
{
    Stack RpnStack;
    string postFixExp;
    char token;
    int var1, var2;

    cout << "Enter post fix expression: ";
    cin >> postFixExp;

    for (int i = 0; i < postFixExp.length(); i++)
    {
        token = postFixExp[i];

        switch (token)
        {
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            RpnStack.push(token - 48);
            break;
        case '+':case '-':case '*':case '/':
            var1 = RpnStack.top();
            RpnStack.pop();
            var2 = RpnStack.top();
            RpnStack.pop();

            if (token == '+')
                RpnStack.push(var2 + var1);
            else if (token == '-')
                RpnStack.push(var2 - var1);
            else if (token == '*')
                RpnStack.push(var2 * var1);
            else if (token == '/')
                RpnStack.push(var2 / var1);
            break;

        }

    }
    cout << endl << "Value for expression entered is: " << RpnStack.top() << endl;
    return 0;
}
