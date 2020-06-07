#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/min-max-difference/description/
//Time Complexity O(n^2)
void bubbleSort(vector<int>&arr, int n)
{
    for(int step = 0; step < n - 1; step++)
    {
        for(int i = 0; i < n - step - 1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

}

int main()
{
   int m, n, t, i, j, min_sum, max_sum;
   cin>>t;
   while(t-- > 0)
   {
       min_sum = 0, max_sum = 0;
       cin>> n >> m;
       vector<int>arr(n);
       int diff = n - m;

       for(i = 0; i < n; i++)
       {
           cin>> arr[i];
       }

       bubbleSort(arr, n);

       for(i = 0, j = n-1; i < diff; i++, j--)
       {
           min_sum += arr[i];
           max_sum += arr[j];
       }

       cout<<max_sum - min_sum<<endl;

       arr.clear();
   }
}
