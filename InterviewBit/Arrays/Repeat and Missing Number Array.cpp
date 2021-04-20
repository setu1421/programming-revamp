/*
    Sum(Actual) = Sum(1...N) + A - B

    Sum(Actual) - Sum(1...N) = A - B. 

    Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2

    Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N)) ( A + B). 
	
	(A + B) + (A - B) = (((Sum(Actual Squares) - Sum(1^2 ... N^2)) / (Sum(Actual) - Sum(1...N))) +  (Sum(Actual) - Sum(1...N)))
	A = (((Sum(Actual Squares) - Sum(1^2 ... N^2)) / (Sum(Actual) - Sum(1...N))) +  (Sum(Actual) - Sum(1...N))) / 2
*/
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


// Another Solution: Using duplicate number finding approach.

int findDuplicateNumber(vector<int> A, int n)
{
    for(int i = 0; i < n; i++)
    {
        int mark_value = abs(A[i]);
        if(A[mark_value - 1] > 0)
        {
            A[mark_value - 1] = -A[mark_value - 1];
        } else
        {
            return mark_value;
        }
    }
    
    return -1;
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0, sumN;
    long long n = A.size();
    
    for(int i = 0; i < n; i++)
    {
        sum = (long long) sum + A[i];
    }
    
    sumN = (long long) (n * (n + 1)) / 2ll;
    
    int duplicateNumber = findDuplicateNumber(A, n);
    int missingNumber = sumN + duplicateNumber - sum;
    
    vector<int>res;
    
    res.push_back(duplicateNumber);
    res.push_back(missingNumber);
    
    return res;
    
}

