#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        int gridLength = grid.size();

        for(int i = 0; i < gridLength; i++)
        {
            counter += BinarySearch(grid[i]);
        }

        return counter;
    }

    int BinarySearch(vector<int>&arr)
    {
       int n = arr.size();
       int low = 0;
       int high = n - 1;
       int ansIndex = -1;

       while(low <= high)
       {
           int mid = low + (high - low) / 2;

           if(arr[mid] < 0)
           {
               ansIndex = mid;
               high = mid - 1;
           } else
           {
               low = mid + 1;
           }
       }

       return (ansIndex == -1) ? 0: (n-ansIndex);
    }
};
