#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>st;
        string res = "";

        for(int i = 0; i < S.length(); i++)
        {
            if(!st.empty() && S[i] == st.top())
            {
              st.pop();
            } else
            {
                st.push(S[i]);
            }
        }

        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

       return res;
    }
};

// Solution Without Stack

class Solution {
public:
    string removeDuplicates(string S) {
        string a;
        for (auto& c : S)
            if (a.size() && a.back() == c) a.pop_back();
            else a.push_back(c);
        return a;
    }
};
