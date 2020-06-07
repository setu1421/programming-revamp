#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// Using comparison class and stable sort (stable sort uses merge sort)
// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/monk-and-modulo-based-sorting/description/
#define ll long long int

// comparison class
class cmp {
    ll param;
public:
    cmp(ll p) {
        param = p;
    }
    bool operator()(ll a, ll b){
        return (a%param) < (b%param);
    }
};

int main()
{
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w",stdout);
   int n;
   ll num, k;
   vector<ll>v;

   cin>>n>>k;
   for(int i = 0; i < n; i++)
   {
       cin>>num;
       v.push_back(num);
   }

   stable_sort(v.begin(), v.end(), cmp(k));

   for(int i = 0; i < n; i++)
   {
       if(i == 0)
       {
           cout<<v[i];
       } else
       {
           cout<<" " << v[i];
       }
   }
   cout<<endl;
}
