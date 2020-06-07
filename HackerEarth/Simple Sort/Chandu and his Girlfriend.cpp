#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend/description/?layout=old

#define ll long long int

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
       int n;
       ll num;
       vector<ll>v;

       cin>>n;
       for(int i = 0; i < n; i++)
       {
           cin>>num;
           v.push_back(num);
       }

       // This sort takes O(nlogn) times.
       sort(v.rbegin(), v.rend());

       for(int i = 0; i < n; i++)
       {
           if(i == 0)
           {
               cout<<v[i];
           } else
           {
               cout<< " " <<v[i];
           }

       }

       cout<<endl;

       v.clear();
    }
}
