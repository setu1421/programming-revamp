#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/card-game-1-44e9f4e7/

#define ll long long int

int main()
{
   int n, m;
   ll num, sum = 0LL, max_val = LONG_LONG_MIN;
   cin>>n;
   vector<ll>v;

   for(int i = 0; i < n; i++)
   {
       cin>>num;
       v.push_back(num);
   }

   sort(v.begin(), v.end());

   cin>>m;

   for(int i = 0; i < m; i++)
   {
      cin>>num;

      if(num > max_val)
      {
          max_val = num;
      }
   }

   max_val++;

   for(int i = 0; i < n; i++)
   {
       if(v[i] > (max_val))
       {
           break;
       } else
       {
           sum += (max_val) - v[i];
       }
   }

   cout<<sum<<endl;
}
