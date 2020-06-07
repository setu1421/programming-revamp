#include<bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/quicksort1/problem
void printArray(vector<int>&v, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout<< v[i];
        } else
        {
            cout<<" " <<v[i];
        }

    }
    cout<<endl;
}
int do_partition(vector<int>&v, int low, int high, int n)
{
    int pivot_value = v[high];
    int pivot_index = low;

    for(int i = low; i < high; i++)
    {
        if(v[i] < pivot_value)
        {
            swap(v[i], v[pivot_index]);
            pivot_index++;
        }
    }
    swap(v[pivot_index], v[high]);

    printArray(v, n);

    return pivot_index;
}

void quick_sort(vector<int>&v, int low, int high, int n)
{
    if(low < high)
    {
        int pivot_index = do_partition(v, low, high, n);
        quick_sort(v, low, pivot_index - 1, n);
        quick_sort(v, pivot_index + 1, high, n);
    }
}


int main() {
    int n, num;
    cin>>n;

    vector<int>v;

    for(int i = 0; i < n; i++)
    {
       cin>> num;
       v.push_back(num);
    }

    quick_sort(v, 0, n-1, n);
    return 0;
}
