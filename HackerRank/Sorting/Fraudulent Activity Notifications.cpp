#include <bits/stdc++.h>
using namespace std;

// Counting sort as the k value is very less than n
#define MAXD 201

vector<int>count_arr(MAXD);

int findMedianValue(int x)
{
    int counter = 0;

    // Try finding till we get the mid count index in the whole count array
    for(int i = 0; i < MAXD; i++)
    {
        counter += count_arr[i];

        if(counter >= x)
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    int n, k, num, notice_count = 0;
    float median_value;
    cin>>n>>k;

    vector<int>arr(n);

    for(int i = 0; i < n; i++)
    {
       cin>>num;

       if(i >= k)
       {
          if(k % 2 == 0)
          {
              median_value = (findMedianValue(k/2) + findMedianValue(k/2 + 1)) / 2.0;
          } else
          {
              median_value = findMedianValue(k/2 + 1);
          }

          if(num >= (2.0 * median_value))
          {
              notice_count++;
          }

          // Remove the new old one out of the sliding window
          count_arr[arr[i-k]]--;
       }

       arr[i] = num;
       count_arr[num]++;
    }


    cout<<notice_count<<endl;
}
