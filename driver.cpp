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
    char token, anotherExp;
    int var1, var2;
    bool badVal;



    do
    {
        badVal = false;                                  // boolean for unexpected characters
        cout << "Enter post fix expression: ";
        getline(cin, postFixExp);                        // get user expression
        for (int i = 0; i < postFixExp.length(); i++)    // loop over length of user expression
        {
            token = postFixExp[i];

            switch (token)
            {
            case ' ':
                break;

                case '0':case '1':case '2':case '3':case '4':
                case '5':case '6':case '7':case '8':case '9':
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
                default:
                    cout << "Malformed Expression encountered";
                    badVal = true;
                    break;
            }

        }
        if (badVal == false)
            cout << endl << "Value for expression entered is: " << RpnStack.top() << endl;

        cout << endl << "More Expressions (Y - Yes : any other key to quit)? ";
        cin.get(anotherExp);
        cin.ignore();
        cout << endl << "--------------------------------------" << endl;
    }while (anotherExp == 'y' || anotherExp == 'Y');
    return 0;
}


