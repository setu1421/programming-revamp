#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int, int> mp;
        stack<int>st;

        for(int i = 0; i < nums2.size(); i++)
        {
            // If the next element is greater than the stack top, then
            // We will set the next greater element of the stacked element with this next element
            // And will pop until the stack top is greater than the next element
            while(!st.empty() && st.top() < nums2[i])
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            // Finally the next element will pushed to stack.
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++)
        {
            if(mp.count(nums1[i]) > 0)
            {
                res.push_back(mp[nums1[i]]);
            } else
            {
                res.push_back(-1);
            }
        }

        return res;
    }
};
