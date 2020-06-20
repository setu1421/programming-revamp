#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1, s2;

    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
       s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // Copying into another stack
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Get the top of second stack which is the first element in queue
        int first_elem = s2.top();
        s2.pop();

        // Copying to the original stack
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

       return first_elem;
    }

    /** Get the front element. */
    int peek() {
        // Copying into another stack
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Get the top of second stack which is the first element in queue
        int first_elem = s2.top();

        // Copying to the original stack
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

       return first_elem;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
       return s1.empty();
    }
};
