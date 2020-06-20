#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>S;
        vector<string>res;
        int j = 0, target_n = target.size();
        for(int i = 1; i <= n && j < target_n; i++)
        {
            S.push(i);
            res.push_back("Push");

            if(S.top() < target[j])
            {
                S.pop();
                res.push_back("Pop");
            } else if(S.top() == target[j])
            {
                j++;
            }
        }
            return res;
    }
};
