#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerrank.com/challenges/countingsort4/problem

void countingSort(vector<pair<int, string>>arr, int n, int max_elem)
{
    vector<int>freq(max_elem + 1);
    vector<pair<int, string>>sorted(n);

    for(int i = 0; i < n; i++)
    {
        freq[arr[i].first]++;
    }

    for(int i = 1; i <= max_elem; i++)
    {
        freq[i] += freq[i-1];
    }

    int mid = n/2;

    // Picking element from the end and placing in the sorted array to keep the relative order of the element
    for(int i = n-1; i >= 0; i--)
    {
        // if the element is in the second half, original value will be present
        if(i >= mid)
        {
           sorted[freq[arr[i].first] - 1] = arr[i];
        }
        // if the element is in the second half, original value will be replaced by dash
        else
        {
            sorted[freq[arr[i].first] - 1] = make_pair(arr[i].first, "-");
        }

        freq[arr[i].first]--;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<sorted[i].second<<" ";
    }
}

int main()
{
    int n,num, max_elem = INT_MIN;
    string str;
    cin>>n;

    vector<pair<int, string>>arr;

    for(int i = 0; i < n; i++)
    {
        cin>>num>>str;
        arr.push_back(make_pair(num, str));
        max_elem = max(max_elem, num);
    }

    countingSort(arr, n, max_elem);

    return 0;
}
