#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0;
        int high = A.size() - 1;

        while(low <= high)
        {
            if(low == high)
            {
                return low;
            }
            int mid = low + (high - low) / 2;

            if(A[mid] > A[mid + 1] && A[mid] > A[mid - 1])
            {
                return mid;
            } else if(A[low] < A[mid])
            {
                if(A[mid] < A[mid + 1])
                {
                    low = mid ;
                } else if(A[mid] < A[mid - 1])
                {
                    high = mid;
                }
            } else
            {
                high = mid;
            }
        }

        return 0;
    }
};
