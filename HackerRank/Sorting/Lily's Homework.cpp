#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/lilys-homework/problem

#define ll long long int

int findMinSwaps(vector<pair<ll,int>>&arr, int n, bool reverse_sort)
{
   int counter = 0;

   // Sort the array first.
   if(reverse_sort)
   {
       sort(arr.rbegin(), arr.rend());
   } else
   {
       sort(arr.begin(), arr.end());
   }


   for(int i = 0; i < n; i++)
   {
       // If the element is already placed in correct position, then continue with next element
       if(arr[i].second == i)
       {
           continue;
       }

       // swap the element with it's respective index
       swap(arr[i], arr[arr[i].second]);

       // Check again whether the place of the element is in correct position or not after swapping
       // If not, then we will swap again for that element
       if(arr[i].second != i)
       {
           --i;
       }

       // Increment the counter for each swap
       counter++;
   }

   return counter;
}

int main()
{
   int n;
   ll num;
   vector<pair<ll,int>>arr;

   cin>>n;

   for(int i = 0; i < n; i++)
   {
      cin>>num;
      arr.push_back(make_pair(num, i));
   }

   int ret = min(findMinSwaps(arr, n, false), findMinSwaps(arr, n, true));

   cout<<ret<<endl;
}
