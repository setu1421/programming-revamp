// Let's say, we have points: (1, 1), (2, 2), (1, 0) (3, 3)
// Now, when we are taking (2, 2) as reference point and calculating slope with (1, 0) and (3, 3), 
// we are not taking (1, 1) into consideration in the inner loop. This is because, when we had taken (1, 1) as
// reference point, we already counted the same slope points ( (1, 1,), (2, 2) and (3, 3) ). 
// So, if we don't consider (1, 1) for (2, 2), it won't matter.

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    // If only two or less points present, then return n.
    if(n <= 2) return n;
    
    int global_max = 0;
    unordered_map<double, int>mp;
    // looping for each point 
    for(int i = 0; i < n; i++)
    {
        int curr_max = 0, same_points = 0, vertical_points = 0;
		// looping from i + 1 to ignore same pair again
        for(int j = i + 1; j < n; j++)
        {
            // If both points are equal then just increase overlapPoint count. 
            if(A[i] == A[j] && B[i] == B[j])
            {
                same_points++;
            } // If x co-ordinate is same, then both points are vertical to each other.
			else if(A[i] == A[j])
            {
                vertical_points++;
                curr_max = max(curr_max, vertical_points);
            } 
			else
            {
                double slope = (double)(((B[j] - B[i]) * 1.0) / ((A[j] - A[i]) * 1.0));
				// increasing the frequency of current slope in map 
                mp[slope]++;
                curr_max = max(curr_max, mp[slope]);
            }
        }
        // updating global maximum by current point's maximum
        global_max = max(global_max, curr_max + same_points + 1);
        mp.clear();
    }
    
    return global_max;
}

// Using double precision can be sometimes problematic because of rounding. So, it is better to hash the slope value in pairs.
// unordered_map does not support hasing pair. So, we will create our own hash struct for pairs.

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();

    if(n <= 2) return n;

    int global_max = 0;
    unordered_map<pair<int, int>, int, hash_pair>mp;

    for(int i = 0; i < n; i++)
    {
        int curr_max = 0, same_points = 0, vertical_points = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(A[i] == A[j] && B[i] == B[j])
            {
                same_points++;
            } else if(A[i] == A[j])
            {
                vertical_points++;
                curr_max = max(curr_max, vertical_points);
            } else
            {
                int yDiff = B[j] - B[i];
                int xDiff = A[j] - A[i];
                // GCD is being used to shred off extra multiples for the slope.
                int g = __gcd(yDiff, xDiff);
                yDiff /= g;
                xDiff /= g;

                mp[make_pair(yDiff, xDiff)]++;
                curr_max = max(curr_max, mp[make_pair(yDiff, xDiff)]);
            }

        }

        global_max = max(global_max, curr_max + same_points + 1);
        mp.clear();
    }

    return global_max;
}
