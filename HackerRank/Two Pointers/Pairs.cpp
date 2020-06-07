#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerrank.com/challenges/pairs/problem

#define ll long long int

// Two pointers approach -> O(n)
int find_pairs(vector<ll>&v, int n, ll k)
{
   int i = 0, j = 1;
   int counter = 0;

   while(j < n)
   {
       ll diff = v[j] - v[i];
       // if the difference matches, then we are moving for next set of pairs
       if(diff == k)
       {
           counter++;
           i++;
           j++;
       }
       // If the difference between two elements is greater than k,
       //then we are moving from the first element to get closer difference with the second element
       else if(diff > k)
       {
           i++;
       }
       // If the difference between two elements is less than k,
       //then we are moving from the second element to get closer difference with the first element
       else
       {
           j++;
       }
   }

   return counter;
}

int main()
{
    int n;
    ll num, k;
    vector<ll>v;

    cin>>n>>k;

    for(int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int res = find_pairs(v, n, k);

    cout<<res<<endl;
}


// Another Solution: (Using Hash Table)
unordered_set<int> s;

int main()
{
    int n, k, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        s.insert(val);
    }
    int ans = 0;
    // for each integer N, check whether the original array contains N-K and N+K. In fact,
    // we can iterate over each number N in the original array and check whether N+K exists in the same array
    for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        if (s.find(*it + k) != s.end())
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
