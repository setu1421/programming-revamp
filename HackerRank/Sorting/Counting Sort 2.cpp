#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerrank.com/challenges/countingsort2/problem

void countingSort(vector<int>arr, int n)
{
    int max_elem = 99;
    vector<int>freq(max_elem + 1);

    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for(int i = 0; i <= max_elem; i++)
    {

    }

    for(int i = 0; i <= max_elem; i++)
    {
        if(freq[i] != 0)
        {
            int frequency = freq[i];

            for(int j = 0; j < frequency; j++)
            {
                cout<<i<<" ";
            }
        }
    }

}

int main()
{
    int n,num;
    cin>>n;

    vector<int>arr;

    for(int i = 0; i < n; i++)
    {
        cin>>num;
        arr.push_back(num);
    }

    countingSort(arr, n);

    return 0;
}
