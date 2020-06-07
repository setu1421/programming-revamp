#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerrank.com/challenges/insertion-sort/problem

// Inversion Count using merge sort -> O(nlogn)
// If we use Binary Indexed Tree (BIT) -> O(n)

#define ll long long int

// counter needs to long long otherwise WA
ll counter = 0;

void merge_array(vector<ll>&arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ll>L(n1);
    vector<ll>R(n2);

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] > R[j])
        {
            /*If any number of the left array is greater than any number in the right array,
              then as the left array is sorted, numbers right to the comparison number of left array will
              be greater than the number in the right array as well.
              For Example:
              (3,4)  (1,2)
              if 3 is greater than 1, then 4 will also be greater than 1. So, inversion count will be 2 here.
            */
            counter += (n1 - i);
            arr[k++] = R[j++];
        } else
        {
            arr[k++] = L[i++];
        }
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }

    while(j < n2)
    {
        arr[k++] = R[j++];
    }

    L.clear();
    R.clear();
}

void merge_sort(vector<ll>&arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge_array(arr, left, mid, right);
    }
}


int main()
{
    int t,n;
    ll num;
    vector<ll>arr;

    cin>>t;

    while(t--)
    {
        cin>>n;

        for(int i = 0; i < n; i++)
        {
            cin>>num;
            arr.push_back(num);
        }

        merge_sort(arr, 0, n-1);

        cout<<counter<<endl;

        arr.clear();
        counter = 0;
    }

    return 0;
}
