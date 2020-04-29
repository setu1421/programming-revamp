#include <bits/stdc++.h>

using namespace std;

// Problem link: https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/practice-problems/algorithm/the-rise-of-the-weird-things-1/
void insertion_sort(int n, vector<int>&arr)
{
    int value, hole;
    bool breakFlag;

    for(int i = 1; i < n; i++)
    {
        breakFlag = false;
        value = arr[i];
        hole = i;

        while(hole > 0 && !breakFlag)
        {
            // If the selected value is odd
            if(value%2 != 0)
            {
                // if we find any even value left of the hole, we will not proceed further.
                if(arr[hole-1]%2 == 0)
                {
                    breakFlag = true;
                } else
                {
                    // if we find value greater than current hole, we will replace the left hole value to the current one.
                    // Otherwise, we will not proceed further
                    if(arr[hole-1] > value)
                    {
                        arr[hole] = arr[hole-1];
                        hole = hole - 1;
                    } else
                    {
                        breakFlag = true;
                    }
                }
            } else
            {
                // If we find any odd number before the even number, we will simply move the hole at the left.
                //Otherwise, compare the values at the left.
                if(arr[hole-1]%2 == 0)
                {
                    // if we find value greater than current hole, we will replace the left hole value to the current one.
                    // Otherwise, we will not proceed further
                    if(arr[hole-1] > value)
                    {
                        arr[hole] = arr[hole-1];
                        hole = hole - 1;
                    } else
                    {
                        breakFlag = true;
                    }
                } else
                {
                    arr[hole] = arr[hole-1];
                    hole = hole - 1;
                }
            }
        }

        arr[hole] = value;
    }
}

int main()
{
    int n, sum = 0, odd_index = 0;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    insertion_sort(n, arr);

    // printing the even numbers
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            sum += arr[i];
            if(i != 0)
            {
                cout<<" "<<arr[i];
            } else
            {
                cout<<arr[i];
            }
        } else
        {
            if(i != 0)
            {
              cout<<" "<<sum;
            }
            sum = 0;
            odd_index = i;
            break;
        }
    }

    // printing the odd numbers
    if(arr[odd_index]%2 != 0)
    {
        for(int i = odd_index; i < n; i++)
        {
            sum += arr[i];
            if(i != 0)
            {
                cout<<" "<<arr[i];
            } else
            {
                cout<<arr[i];
            }
        }
    }

    cout<<" "<<sum<<endl;

    return 0;
}
