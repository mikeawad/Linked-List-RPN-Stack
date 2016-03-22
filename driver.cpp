/*---------------------------------------------------------------------
                  Driver program to test the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LStack.h"
#include <string>

using namespace std;



int main()
{
    
    string postFixExp;                                      // user expresssion entry
    char token, anotherExp;
    int var1, var2, i, lastItem;
    bool malform;



    do
    {
        Stack RpnStack;                                     // object decleration inside loop to 'reconstruct' object each time
        malform = false;                                     // boolean for unexpected characters
        cout << "Enter post fix expression: ";
        getline(cin, postFixExp);                           // get user expression
        i = 0;
        
        // this loop itereates over the lenght of the user entered expression and while a malform flag isn't rasised
        while(malform == false && i < postFixExp.length())
        {
            token = postFixExp[i];

            switch (token)
            {
            case ' ':
                break;

                case '0':case '1':case '2':case '3':case '4':   // this will handle the operaand digit cases
                case '5':case '6':case '7':case '8':case '9':
                    RpnStack.push(token - 48);
                    break;

                case '+':case '-':case '*':case '/':            // this will hand the opeartor cases
                    var1 = RpnStack.top();
                    RpnStack.pop();
                    
                    if (RpnStack.empty())                       // check for stack less than two items
                    {
                        cout << "Error --> Stack does not contain two items -- Malformed expression." << endl;
                        malform = true;
                        break;
                    }
                    
                    else
                    {
                        var2 = RpnStack.top();
                        RpnStack.pop();
                    }

                    if (token == '+')
                        RpnStack.push(var2 + var1);
                    else if (token == '-')
                        RpnStack.push(var2 - var1);
                    else if (token == '*')
                        RpnStack.push(var2 * var1);
                    else if (token == '/')
                        if (var1 == 0)                          // check for zero denominator
                        {
                            cout << "Error --> Cannot divide by zero." << endl;
                            malform = true;
                            break;
                        }
                    else
                    {
                        RpnStack.push(var2 / var1);
                    }
                    break;
                    
                default: //default case
                    cout << "Error: --> Malformed Expression encountered" << endl;
                    malform = true;
                    break;
            }
            i++;

        }
        lastItem = RpnStack.top();
        RpnStack.pop();
        
        if (malform == false && !RpnStack.empty())
        {
            cout << endl << "Value for expression entered is: " << lastItem << endl;
        }

        cout << endl << "More Expressions (y - yes : any other key to quit)? ";
        cin.get(anotherExp);
        cin.ignore();
        cout << endl << "--------------------------------------" << endl;
    }while (anotherExp == 'y' || anotherExp == 'Y');
    return 0;
}


