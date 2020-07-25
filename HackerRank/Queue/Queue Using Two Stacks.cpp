#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingStack
{
public:
    stack<T>s1;
    stack<T>s2;

    void enqueue(T value)
    {
        s1.push(value);
    }

    void dequeue()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    T queueFront()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

int main()
{
    int q, option;
    long long num;
    QueueUsingStack<long long> Q;

    cin>>q;

    for(int i = 0; i < q; i++)
    {
        cin>>option;

        if(option == 1)
        {
            cin>> num;

            Q.enqueue(num);
        } else if(option == 2)
        {
            Q.dequeue();
        } else
        {
            cout<<Q.queueFront()<<endl;
        }
    }
}
