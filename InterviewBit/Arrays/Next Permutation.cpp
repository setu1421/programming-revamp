void reverse_array(vector<int> &A, int start, int end)
{
    while(start < end)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

int findNextGreaterValueIndex(vector<int> &A, int start, int end, int value)
{
    int swapValue = INT_MAX;
    int swapIndex = - 1;
    for(int i = start; i <= end; i++)
    {
        if(A[i] > value && A[i] < swapValue)
        {
            swapValue = A[i];
            swapIndex = i;
        }
    }

    return swapIndex;
}

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int i = n - 1;

    while(i > 0 && A[i - 1] >= A[i])
    {
        i--;
    }

    // Already in descending order
    if(i == 0)
    {
        reverse_array(A, 0, n - 1);
    } else
    {
        // At first reverse the section
        reverse_array(A, i, n - 1);
        int swapIndex = findNextGreaterValueIndex(A, i, n - 1, A[i - 1]);
        swap(A[swapIndex], A[i - 1]);
    }

    return A;
}
