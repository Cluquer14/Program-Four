//
//  SpecialStack.h
//  CS250_ProgramFour
//
//  Created by Charlotte Luquer on 11/24/24.
//
//  Description: This program defines a SpecialStack class and allows the removal of the most recent even or odd number while handling exceptions.
//

#ifndef SpecialStack_h
#define SpecialStack_h
#include <stack>
#include <iostream>
#include <stdexcept>

class SpecialStack {
private:
    std::stack<int> mainStack;

public:
    void push(int value) {
        mainStack.push(value);
    }
    void pop() {
        if (mainStack.empty()) {
            throw std::underflow_error("Stack is empty, cannot pop.");
        }
        mainStack.pop();
    }
    int peek() const {
        if (mainStack.empty()) {
            throw std::underflow_error("Stack is empty, cannot peek.");
        }
        return mainStack.top();
    }
    bool empty() const {
        return mainStack.empty();
    }
    void printStack() const {
        if (mainStack.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::stack<int> temp = mainStack;
        std::stack<int> reversed;

        while (!temp.empty()) {
            reversed.push(temp.top());
            temp.pop();
        }

        while (!reversed.empty()) {
            std::cout << reversed.top() << std::endl;
            reversed.pop();
        }
    }
    void popOdd() {
        if (mainStack.empty()) {
            throw std::underflow_error("Stack is empty, cannot popOdd.");
        }

        std::stack<int> temp;
        bool found = false;
        while (!mainStack.empty()) {
            if (mainStack.top() % 2 != 0 && !found) {
                mainStack.pop();
                found = true;
                break;
            } else {
                temp.push(mainStack.top());
                mainStack.pop();
            }
        }
        while (!temp.empty()) {
            mainStack.push(temp.top());
            temp.pop();
        }
        if (!found) {
            throw std::logic_error("No odd number found to pop.");
        }
    }
    void popEven() {
        if (mainStack.empty()) {
            throw std::underflow_error("Stack is empty, cannot popEven.");
        }
        std::stack<int> temp;
        bool found = false;
        while (!mainStack.empty()) {
            if (mainStack.top() % 2 == 0 && !found) {
                mainStack.pop();
                found = true;
                break;
            } else {
                temp.push(mainStack.top());
                mainStack.pop();
            }
        }
        while (!temp.empty()) {
            mainStack.push(temp.top());
            temp.pop();
        }
        if (!found) {
            throw std::logic_error("No even number found to pop.");
        }
    }
};

#endif
