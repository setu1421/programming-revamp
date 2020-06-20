#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
       string res = "";
       stack<char>st;

       for(int i = 0; i < S.length(); i++)
       {
           if(S[i] == '(')
           {
               if(st.size() > 0)
               {
                   res += S[i];
               }

               st.push(S[i]);
           } else
           {
               if(st.size() > 1)
               {
                   res += S[i];
               }

               st.pop();
           }
       }

       return res;
    }
};
