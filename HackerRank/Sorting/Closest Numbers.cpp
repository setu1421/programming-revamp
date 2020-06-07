#include<bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/closest-numbers/problem

#define ll long long int

void printArray(vector<ll>&v, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout<< v[i];
        } else
        {
            cout<<" " <<v[i];
        }

    }
    cout<<endl;
}

void find_closest_numbers(vector<ll>&v, int n)
{
    vector<ll>result;

    ll min_diff = LONG_LONG_MAX;

    for(int i = 1; i < n; i++)
    {
        ll diff = v[i] - v[i-1];
        if(diff < min_diff)
        {
            min_diff = diff;
            result.clear();
            result.push_back(v[i-1]);
            result.push_back(v[i]);
        } else if (diff == min_diff)
        {
            result.push_back(v[i-1]);
            result.push_back(v[i]);
        }
    }

    printArray(result, result.size());
}


int main() {
    int n; ll num;
    cin>>n;

    vector<ll>v;

    for(int i = 0; i < n; i++)
    {
       cin>> num;
       v.push_back(num);
    }

    sort(v.begin(), v.end());

    find_closest_numbers(v, v.size());

    return 0;
}
