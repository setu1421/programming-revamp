#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>Q1;
    queue<int>Q2;

    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        Q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int qSize = Q1.size();
        for(int i = 0; i < qSize - 1; i++)
        {
            Q2.push(Q1.front());
            Q1.pop();
        }

        int topElem = Q1.front();
        Q1.pop();

        qSize = Q2.size();
        for(int i = 0; i < qSize; i++)
        {
            Q1.push(Q2.front());
            Q2.pop();
        }

        return topElem;
    }

    /** Get the top element. */
    int top() {
        return Q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
       return Q1.empty();
    }
};
