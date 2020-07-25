#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A){
    int n = A.size();
    int current_start = -1, current_end = -1, prev_start = -1, prev_end = -1;
    long long current_sum = 0, prev_sum = INT_MIN;

    vector<int>res;

    for(int i = 0; i < n; i++)
    {
        current_sum = 0;
        current_start = -1;
        current_end = -1;

        while(i < n && A[i] >= 0)
        {
            current_sum += A[i];

            if(current_start == -1)
            {
                current_start = i;
                current_end = i;
            } else
            {
                current_end++;
            }

            i++;
        }

        // Compare with previous subarray
        if((current_sum > prev_sum) || ((current_sum == prev_sum) && (current_end - current_start > prev_end - prev_start)))
        {
            prev_sum = current_sum;
            prev_start = current_start;
            prev_end = current_end;
        }
    }

    // Extra check whether all the numbers are negative or not
    if(prev_start != -1)
    {
        for(int i = prev_start; i <= prev_end; i++)
        {
            res.push_back(A[i]);
        }
    }
}
