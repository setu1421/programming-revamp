#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/sort-it-out/

void bubbleSort(vector<int>&index_arr, vector<int>&arr, int n)
{
    bool already_sorted = true;
    for(int step = 0; step < n - 1; step++)
    {
        for(int i = 0; i < n-step-1; i++)
        {
           if(arr[i] > arr[i+1])
           {
               int temp = arr[i];
               arr[i] = arr[i+1];
               arr[i+1] = temp;

               //swap the index as well
               int temp_index = index_arr[i];
               index_arr[i] = index_arr[i+1];
               index_arr[i+1] = temp_index;

               already_sorted = false;
           }
        }

       // If already sorted, then no need to sort again. Otherwise Time Limit will be exceeded for big input.
       if(already_sorted)
       {
           break;
       }
    }
}

int main()
{

   int n;
   scanf("%d", &n);
   vector<int>arr(n);
   vector<int>index_arr(n);

   for(int i = 0; i < n; i++)
   {
       scanf("%d", &arr[i]);
       index_arr[i] = i;
   }

   bubbleSort(index_arr, arr, n);

   for(int i = 0; i < n; i++)
   {
       if(i == 0)
       {
           printf("%d", index_arr[i]);
       } else
       {
          printf(" %d", index_arr[i]);
       }

   }
   printf("\n");
}
