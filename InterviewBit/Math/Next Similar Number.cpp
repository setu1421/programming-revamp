int findFirstDigitPlace(int *arr, int n)
{
    int indx = -1;

    for(int i = n - 2; i >=0; i--)
    {
        if(arr[i] < arr[i + 1])
        {
            indx = i;
            break;
        }
    }

    return indx;
}

int findNextGreaterDigitPlace(int *arr, int value, int start, int end)
{
    int swapValue = INT_MAX;
    int swapIndx = -1;
    for(int i = start; i < end; i++)
    {
        if(arr[i] > value && arr[i] <= swapValue)
        {
            swapValue = arr[i];
            swapIndx = i;
        }
    }

    return swapIndx;
}

void reverseArray(int *arr, int start, int end)
{
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

string Solution::solve(string A) {
    int n = A.size();
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = A[i] - '0';
    }

    int firstIndx = findFirstDigitPlace(arr, n);
    // if already the highest number, then return -1
    if(firstIndx == -1)
    {
        return "-1";
    }

    // Find the place immediate largest value of firstIndx from it's right and the index to swap
    int secondIndx = findNextGreaterDigitPlace(arr, arr[firstIndx], firstIndx + 1, n);
    // Swap the first value with the immediate greater value
    swap(arr[firstIndx], arr[secondIndx]);
    // Finally sort the sub array after the first index.
    reverseArray(arr, firstIndx + 1, n - 1);

    string res = "";

    for(int i = 0; i < n; i++)
    {
        res += to_string(arr[i]);
    }

    return res;
}
