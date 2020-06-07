#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> res;

        int low = 1;
        int high = z;

        while(low <= z && high > 0)
        {
            int output = customfunction.f(low, high);

            if(output == z)
            {
               res.push_back({low, high});
               low++;
               high--;
            } else if(output < z)
            {
                low++;
            } else
            {
                high--;
            }
        }

        return res;
    }
};
