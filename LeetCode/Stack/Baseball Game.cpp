#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int counter = 0;
        stack<int>st;

        for(int i = 0; i < ops.size(); i++)
        {
            if(ops[i] == "C")
            {
                counter -= st.top();
                st.pop();
            } else if(ops[i] == "D")
            {
                int value = 2 * st.top();
                st.push(value);
                counter += value;
            } else if(ops[i] == "+")
            {
                int lastElem2 = st.top();
                st.pop();
                int lastElem1 = st.top();

                st.push(lastElem2);
                int value = lastElem1 + lastElem2;
                st.push(value);
                counter += value;
            } else
            {
                int value = stoi(ops[i]);
                st.push(value);
                counter += value;
            }
        }

        return counter;
    }
};
