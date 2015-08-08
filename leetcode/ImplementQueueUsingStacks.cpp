//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (empty()) return;
        else if (!_stack2.empty()) _stack2.pop();
        else {
            while (!_stack1.empty()) {
                _stack2.push(_stack1.top());
                _stack1.pop();
            }
            _stack2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (empty()) return 0;
        else if (!_stack2.empty()) return _stack2.top();
        else {
            while (!_stack1.empty()) {
                _stack2.push(_stack1.top());
                _stack1.pop();
            }
            return _stack2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (_stack1.empty() && _stack2.empty()) return true;
        else return false;
    }

private:
    stack<int> _stack1;
    stack<int> _stack2;
};