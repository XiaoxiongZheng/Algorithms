//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
#include <queue>

using namespace std;


class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!_queue1.empty()) {
            _queue2.push(_queue1.front());
            _queue1.pop();
        }
        _queue1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!_queue1.empty()) _queue1.pop();
        int cnt = _queue2.size();
        if (cnt != 0) {
            while (cnt-- > 1) {
                _queue2.push(_queue2.front());
                _queue2.pop();
            }
            _queue1.push(_queue2.front());
            _queue2.pop();
        }
    }

    // Get the top element.
    int top() {
        if (!_queue1.empty())
            return _queue1.front();
        else return 0;
    }

    // Return whether the stack is empty.
    bool empty() {
        if (_queue1.empty() && _queue2.empty()) return true;
        else return false;
    }

private:
    queue<int> _queue1;
    queue<int> _queue2;
};