#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/monk-and-modulo-based-sorting/description/
#define ll long long int

void merge_array(vector<ll>&v, ll mod_val, int left, int mid, int right)
{
   int n1 = mid - left + 1;
   int n2 = right - mid;

   vector<ll>L(n1);
   vector<ll>R(n2);

   for(int i = 0; i < n1; i++)
   {
       L[i] = v[left + i];
   }
   for(int i = 0; i < n2; i++)
   {
       R[i] = v[mid + i + 1];
   }

   int i = 0, j =0, k = left;

   while(i < n1 && j < n2)
   {
       if((L[i] % mod_val) <= (R[j] % mod_val))
       {
          v[k++] = L[i++];
       } else
       {
           v[k++] = R[j++];
       }
   }

   while(i < n1)
   {
       v[k++] = L[i++];
   }

   while(j < n2)
   {
       v[k++] = R[j++];
   }

   L.clear();
   R.clear();
}

void merge_sort(vector<ll>&v, ll k, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;

        merge_sort(v, k, left, mid);
        merge_sort(v, k, mid+1, right);
        merge_array(v, k, left, mid, right);
    }
}

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

   merge_sort(v, k, 0, v.size() - 1);

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
