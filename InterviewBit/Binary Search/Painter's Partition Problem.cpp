// https://www.youtube.com/watch?v=9BnC7orwkNA&t=719s
// Time Complexity: sizeof(C) * log(10^6 * 10^5)
#define M 10000003

int findPaintersRequired(long long painterTime, vector<int> &C)
{
    int count = 0;
    long long sum;

    for(int i = 0; i < C.size(); i++)
    {
        sum = 0ll; count++;
        while(sum + C[i] <= painterTime)
        {
            sum += C[i];
            i++;
        }
        i--;
    }

    return count;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long ans = INT_MAX;
    int n = C.size();
    long long low = INT_MIN; long long high = 0;
    
    for(int i = 0; i < n; i++)
    {
        // minimum time required if each board is assinged to each painter
        low = max(low, (long long) C[i]);
        // maxium time required if each board is assinged to only one painter
        high += C[i];
    }
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        
        int painters_req = findPaintersRequired(mid, C);
        // If more painters required, then more time should be given to allocated A painters.
        if(painters_req > A)
        {
            low = mid + 1;
        } else 
        {
			// Keep the minimum painters as the answer and search if A painters can do in more less time.
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    
    return (ans * (long long) B) % M;
    
}

// Another approach: DP approach (https://www.youtube.com/watch?v=zNVT8SnGRig&t=983s)
