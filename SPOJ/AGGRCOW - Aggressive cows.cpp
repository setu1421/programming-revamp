#include<bits/stdc++.h>
using namespace std;
 
int findRequiredCows(vector<long long> &stall, int n, int gap, int C)
{
    int cows = 1;
    long long pos = stall[0];
 
    for(int i = 0; i < n; i++)
    {
        if(stall[i] - pos >= gap)
        {
            cows++;
            pos = stall[i];
            if(cows == C)
            {
                return 1;
            }
        }
    }
 
    return 0;
}
 
int main()
{
    int t, N, C;
    long long pos;
 
    cin>>t;
 
    while(t--)
    {
        cin>>N>>C;
 
        vector<long long>stall(N);
        for(int i = 0; i < N; i++)
        {
            cin>>pos;
            stall[i] = pos;
        }
 
        sort(stall.begin(), stall.end());
 
        long long low = 0, high = stall[N - 1], ans = INT_MIN;
 
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
 
            bool canbePlaced = findRequiredCows(stall, N, mid, C);
 
            if(!canbePlaced)
            {
                high = mid - 1;
            } else
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
        }
 
        cout<<ans<<endl;
    }
}