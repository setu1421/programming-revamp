#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it = s.begin();

        for(char c: t)
        {
            if(it == s.end())
            {
                break;
            }
            if(c == *it)
            {
                it++;
            }
        }

        return it == s.end();
    }
};
