//
//  main.cpp
//  CS250_ProgramFour
//
//  Created by Charlotte Luquer on 11/21/24.
//

#include <iostream>
#include "SpecialStack.h"
using namespace std;

int main()
{
    SpecialStack one, two, three, four;

    try {
       cout << "Stack one"  << endl;
       one.push(41);
       one.push(66);
       one.push(91);
       one.push(88);
       one.push(33);
       one.popEven();
       one.printStack();
    }
    catch (int e) {
       cout << "Unable to complete operations" << endl << endl;
    }

    try {
       cout << "Stack two" << endl;
       two.push(1);
       two.push(9);
       two.push(6);
       two.push(2);
       two.push(8);
       two.push(6);
       two.push(4);
       two.popOdd();
       two.printStack();
    }
    catch (int e) {
       cout << "Unable to complete operations" << endl << endl;
    }

    try {
        cout << "Stack three" << endl;
        three.popEven();
        three.printStack();
     }
    catch (int e) {
       cout << "Unable to complete operations" << endl << endl;
    }

    try {
       cout << "Stack four" << endl;
       four.pop();
       four.printStack();
    }
    catch (int e) {
       cout << "Unable to complete operations" << endl << endl;
    }
    return 0;
}
