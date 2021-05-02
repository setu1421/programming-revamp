// similar to allocate books - binary_search problem

#include<bits/stdc++.h>
using namespace std;

bool findChooppedWoods(vector<long long> &heights, long long N, long long sawHeight, long long M)
{
    long long total = 0;

    for(long long i = 0; i < N; i++)
    {
        if(heights[i] > sawHeight)
        {
            total += (heights[i] - sawHeight);

            if(total >= M)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long N, M, low = 0ll, high = INT_MIN, ans = INT_MIN;
    vector<long long> heights;

    scanf("%lld %lld" , &N,&M);

    for(long long i = 0; i < N; i++)
    {
        long long h;

        scanf("%lld" , &h);
        heights.push_back(h);
        high = max(high, h);
    }

    while(low <= high)
    {
        long long mid = low + (high - low) / 2;

        bool isValid = findChooppedWoods(heights, N, mid, M);

        if(isValid)
        {
            ans = max(ans, mid);
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }

    printf("%lld\n" , ans);;
}
