#include <bits/stdc++.h>
using namespace std;

int multiply(int x, int arr[], int res_size)
{
    int carry = 0;

    for(int i = 0; i < res_size; i++)
    {
        int prod = x * arr[i] + carry;
        arr[i] = prod % 10;
        carry = prod / 10;
    }

    while(carry)
    {
        arr[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }

    return res_size;
}

string solve(int A) {
    int arr[500], res_size = 1;
    string res = "";

    arr[0] = 1;

    for(int x = 2; x <= A; x++)
    {
        res_size = multiply(x, arr, res_size);
    }

    for(int i = res_size - 1; i >= 0; i--)
    {
        res.push_back(arr[i] + '0');
    }

    return res;
}
