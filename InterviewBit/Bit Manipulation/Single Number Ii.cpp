int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int res = 0;
    
    for(int i = 0; i < 32; i++)
    {
        int countOne = 0;
		// Count the number of one's in that particular bit.
        for(int j = 0; j < n; j++)
        {
            if((1 << i) & A[j])
            {
                countOne++;
            }
        }
        // As each same number will contribute multiple of three ones or zeros.
		// So, if we find extra 1 or 0 (3n + 1), then we can take that bit and build the single number
        if(countOne % 3 == 1)
        {
            res += pow(2, i);
        }
    }
    
    return res;
}

// Another Approach: Without going though all 32 bits.
// Time Complexity: O(n)
// https://www.youtube.com/watch?v=3gJxLkPPW6M&t=1818s
int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int tn = INT_MAX, tnp1 = 0, tnp2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        int cmtn = (A[i] & tn);
        int cmtnp1 = (A[i] & tnp1);
        int cmtnp2 = (A[i] & tnp2);
        
        tn = (tn & ~cmtn);
        tnp1 = (tnp1 | cmtn);
        
        tnp1 = (tnp1 & ~cmtnp1);
        tnp2 = (tnp2 | cmtnp1);
        
        tnp2 = (tnp2 & ~cmtnp2);
        tn = (tn | cmtnp2);
    }
    
    return tnp1;
}

