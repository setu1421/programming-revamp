#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

//https://www.hackerrank.com/challenges/find-the-median/problem

int main()
{
    int n, num, mid_indx;
    vector<int>v;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    mid_indx = n/2;

    cout<<v[mid_indx]<<endl;

    return 0;
}
