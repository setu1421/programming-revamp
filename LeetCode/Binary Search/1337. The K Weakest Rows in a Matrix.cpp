#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int mat_length = mat.size();
       vector<pair<int, int>>res;
       vector<int>final_res;

       for(int i = 0; i < mat_length; i++)
       {
           int ret = countWeakness(mat[i]);

           res.push_back(make_pair(ret, i));
       }

       sort(res.begin(), res.end());

       for(int i = 0; i < k; i++)
       {
           final_res.push_back(res[i].second);
       }

       return final_res;
    }

    int countWeakness(vector<int>&arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans_index = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(arr[mid] == 1)
            {
                ans_index = mid;
                low = mid + 1;
            } else if(arr[mid] == 0)
            {
                high = mid - 1;
            }
        }

        return (ans_index == -1) ? 0 : ans_index + 1;
    }
};
