// Similar problem like allocate books (binary_search)

#include<bits/stdc++.h>
using namespace std;

int parataCount(int rank, int low, int high, long long time)
{
    int ans = 0;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if((long long) rank * ((mid * (mid + 1)) / 2) <= time)
        {
            ans = max(ans, mid);
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }

    return ans;
}

bool prepareParataPossible(vector<int> &ranks, int L, int P, long long time)
{
    int count = 0;

    for(int i = 0; i < L; i++)
    {
        count += parataCount(ranks[i], 0, P, time);

        if(count >= P)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, P, L, R;

    cin>>t;

    while(t--)
    {
        cin>>P>>L;
        vector<int> ranks(L);

        for(int i = 0; i < L; i++)
        {
            cin>>ranks[i];
        }
        sort(ranks.begin(), ranks.end());

        long long low = 0, high = ((long long) ranks[L - 1] * ((long long) (P * (P + 1)) / 2)), ans = INT_MAX;

        // if only one maker is present
        if(L == 1)
        {
            cout<<high<<endl;
            continue;
        }

        while(low <= high)
        {
            long long mid = low + (high - low) / 2;

            bool isPossible = prepareParataPossible(ranks, L, P, mid);

            if(isPossible)
            {
                ans = min(ans, mid);
                high = mid - 1;
            } else
            {
                low = mid + 1;
            }
        }

        cout<<ans<<endl;
    }
}
