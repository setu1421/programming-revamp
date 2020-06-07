#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/shubham-and-xor-8526868e/
// Complexity: O(n)
int main()
{
    int n, value;
    cin>>n;
    unordered_map<long long int, int> mp;

    long long ans = 0;

    for(int i = 0; i < n; i++)
    {
        cin>>value;
        //save the number of occurrences of a particular value
        mp[value]++;
        int c = mp[value];

        // Remove the previously calculated (N-1)C2.
        ans -= (1ll) * (c-1) * (c-2) / 2;
        // Add the newly calculated NC2.
        ans += (1ll) * (c) * (c-1) / 2;
    }

    cout<<ans<<endl;
}
