#include <bits/stdc++.h>
using namespace std;

// Using Stack
// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
       stack<char>s1, s2;

       for(int i = 0; i < S.length(); i++)
       {
           if(S[i] == '#' && !s1.empty())
           {
               s1.pop();
           } else if(S[i] != '#')
           {
               s1.push(S[i]);
           }
       }

       for(int i = 0; i < T.length(); i++)
       {
           if(T[i] == '#' && !s2.empty())
           {
               s2.pop();
           } else if(T[i] != '#')
           {
               s2.push(T[i]);
           }
       }

       bool res = true;

       if(s1.size() != s2.size())
       {
           res = false;
       } else
       {
           while(!s1.empty())
           {
               if(s1.top() != s2.top())
               {
                   res = false;
                   break;
               } else
               {
                   s1.pop();
                   s2.pop();
               }
           }
       }

       return res;
    }
};

// Using Two Pointers
// Time Complexity: O(m+n)
// Space Complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
       int i = S.length() - 1;
       int j = T.length() - 1;
       int skipS = 0, skipT = 0;

       while(i >= 0 || j >= 0)
       {
           while(i >= 0)
           {
               if(S[i] == '#')
               {
                   skipS++;
                   i--;
               } else if(skipS > 0)
               {
                   skipS--;
                   i--;
               } else
               {
                   break;
               }
           }

            while(j >= 0)
            {
                if(T[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if(skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            if(i >= 0 && j >= 0 && S[i] != T[j])
            {
                return false;
            }

            if((i >= 0) != (j >= 0))
            {
                return false;
            }

            i--;
            j--;
       }

       return true;
    }
};
