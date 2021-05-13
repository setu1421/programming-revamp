int Solution::solve(vector<int> &A) {
    int n = A.size();
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        // (i + 1) denotes number of sets of subarray containing that number
        // (n - i) denotes number of times that number present in the subarray set
        int freq = (i + 1) * (n - i);
        // If odd number of occurence, then we have to xor again.
        // As 3^3 = 0, 3^3^3 = 3
        if(freq % 2)
        {
            res = res ^ A[i];
        }
    }
    
    return res;
}
/*
(i + 1) denotes number of sets of subarray containing that number
(n - i) denotes number of times that number present in the subarray set

Let's say A = [3, 4, 5]

The sets will be:
set of 3 | set of 4 | set of 5 |
3        | 4        | 5        |
3, 4     | 4, 5     |          | 
3, 4, 5  |          |          |

For 4, it is present in two sets. (set of 3 and set of 4) = 2 (i + 1)
For 4, it appears two times in each set = 2 (n - i)
Total appearance = (n - i) (i + 1)

*/