vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int D, M;
    long long sum = 0, sumN, sumSq = 0, sumSqN;
    
    int n = A.size();
    
    sumN = (long long) ((long long) n * (long long) (n + 1)) / 2;
    sumSqN = (long long) ((long long) n * (long long) (n + 1) * ((long long) (2 * n) + 1)) / (long long) 6;
    
    for(int i = 0; i < n; i++)
    {
        sum += (long long) A[i];
        sumSq += (long long) pow(A[i], 2);
    }
    
    D = (((long long) (sumSq - sumSqN) / (long long) (sum - sumN)) + (long long) (sum - sumN)) / (long long) 2;
    M = D - sum + sumN;
    
    vector<int>res;
    
    res.push_back(D);
    res.push_back(M);
    
    return res;
    
}
