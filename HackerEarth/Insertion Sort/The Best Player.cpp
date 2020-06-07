#include <bits/stdc++.h>

using namespace std;

// https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/the-best-player-1/
// Insertion Sort
void placePairBySorting(vector< pair<string, long> >&arr, int indx)
{
    pair<string, long> value;
    int hole = indx;
    value = arr[indx];

    while(hole > 0)
    {
        if(arr[hole-1].second < value.second)
        {
            arr[hole] = arr[hole - 1];
            hole = hole - 1;
        } else if(arr[hole-1].second == value.second)
        {
            if(strcmp(arr[hole-1].first.c_str(), value.first.c_str()) > 0)
            {
                arr[hole] = arr[hole - 1];
                hole = hole - 1;
            } else
            {
                break;
            }
        } else
        {
            break;
        }
    }

    arr[hole] = value;

}

int main()
{
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);

   int n, m, value;
   string name;
   cin>>n>>m;

   vector< pair<string, long> > arr(n);

   for(int i = 0; i < n; i++)
   {
       cin>> name >> value;

       if(i != 0)
       {
           arr[i] = make_pair(name, value);
           placePairBySorting(arr, i);
       } else
       {
           arr[i] = make_pair(name, value);
       }
   }

   for(int i = 0; i < m; i++)
   {
       cout<<arr[i].first<< endl;
   }


}
