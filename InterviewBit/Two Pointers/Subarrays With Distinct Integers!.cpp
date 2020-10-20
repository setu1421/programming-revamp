int findCountofSubArrayForAtMostB(vector<int> &A, int B)
{
    int n = A.size();
    int i = 0, j = 0, count = 0;
    unordered_map<int, int>mp;
    mp[A[0]]++;

    while(i < n && j < n)
    {
        if(mp.size() <= B)
        {
            count += (j - i + 1);
            j++;
            mp[A[j]]++;
        }

        if(mp.size() > B)
        {
            mp[A[i]]--;
            if(mp[A[i]] == 0)
            {
                mp.erase(A[i]);
            }
            i++;
        }
    }

    return count;
}

int Solution::solve(vector<int> &A, int B) {
    // Find subarrays with at most B distinct elements
    // Find subarrays with at most B - 1 distinct element
    int countwithAtMostB = findCountofSubArrayForAtMostB(A, B);
    int countwithAtMostBMinus1 = findCountofSubArrayForAtMostB(A, B - 1);
    // subtracting will give all the subarrays with exact B distinct elements
    return countwithAtMostB - countwithAtMostBMinus1;
}
