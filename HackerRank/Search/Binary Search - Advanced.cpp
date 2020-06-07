#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/binary-search-advanced/problem

int findFirstOrLastOccurrence(int *arr, int n, int x, bool firstOccurrence)
{
    int low =  0;
    int high = n-1;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == x)
        {
            ans = mid;

            if(firstOccurrence)
            {
               high = mid - 1;
            }else
            {
                low = mid + 1;
            }
        }// Searching in the right section
        else if(arr[mid] < x)
        {
            low = mid + 1;
        } // Searching in the left section
        else
        {
            high = mid - 1;
        }
    }

    return ans;

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, key, firstOccurrence = -1, lastOccurrence = -1, frequency = 0;
    cin>>n;

    int arr[n+1];

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cin>>key;

    firstOccurrence = findFirstOrLastOccurrence(arr, n, key, true);
    if(firstOccurrence != -1)
    {
        lastOccurrence = findFirstOrLastOccurrence(arr, n, key, false);
        frequency = (lastOccurrence - firstOccurrence) + 1;
    }


    cout<< firstOccurrence << " " << lastOccurrence << " " << frequency << endl;


    return 0;
}
