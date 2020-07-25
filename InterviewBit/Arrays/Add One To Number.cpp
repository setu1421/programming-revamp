#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ret;
    int carry = 0, n = A.size();

    for(int i = n - 1; i >= 0; i--)
    {
        if(i == n - 1)
        {
            carry = 1;
        }

        int add = A[i] + carry;
        A[i] = add % 10;
        carry = add / 10;
    }

    bool found_first_non_zero = false;

    if(carry)
    {
        ret.push_back(carry);
        found_first_non_zero = true;
    }


    for(int i = 0; i < n; i++)
    {
        if(A[i] != 0)
        {
            found_first_non_zero = true;
        }

        if(found_first_non_zero)
        {
            ret.push_back(A[i]);
        }
    }

    return ret;
}
