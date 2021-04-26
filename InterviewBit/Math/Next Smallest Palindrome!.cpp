// https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
// https://youtu.be/hZcindWcYI4

// add one at the start and end
// In the middle add n - 1 zeroes
string generateNextPalindromeWhenAllNines(int n)
{
    string res = "1";
    for(int i = 1; i < n; i++)
    {
        res += "0";
    }
    
    res += "1";
    
    return res;
}

string generateNextPalindrome(int *arr, int n)
{
    bool isLeftSideSmaller = false;
    
    int mid = n / 2;
    
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;
    
    // From the middle, find the left index which is not palindrome with the right index
    while(i >= 0 && arr[i] == arr[j])
    {
        i--;
        j++;
    }
    
    // Check if array is already palindrome (i < 0) or
    // Check if the left side value is less than the right side value
    if(i < 0 || arr[i] < arr[j])
    {
        isLeftSideSmaller = true;
    }
    
    if(isLeftSideSmaller)
    {
        i = mid - 1;
        int carry = 1;
        // If odd number of digits, then add carry to mid
        if(n % 2)
        {
            arr[mid] += carry;
            carry = arr[mid] / 10;
            arr[mid] %= 10;
            j = mid + 1;
        } else 
        {
            j = mid;
        }
        
        // add carry if present from the odd number of digits or
        // add carry for even number of digits
        // Finally copy the left side to right side
        while(i >= 0)
        {
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] %= 10;
            arr[j++] = arr[i--];
        }
    } else 
    {
        // Copy the reverse left side to right side
        while(i >= 0)
        {
            arr[j++] = arr[i--];
        }
    }
    
    string res = "";
    for(int i = 0; i < n; i++)
    {
        res += to_string(arr[i]);
    }
    
    return res;
}

string Solution::solve(string A) {
    int n = A.size();
    int arr[n];
    bool isAllNines = true;
    
    for(int i = 0; i < n; i++)
    {
        arr[i] = A[i] - '0';
        if(arr[i] != 9)
        {
            isAllNines = false;
        }
    }
    
    string res;
    
    if(isAllNines)
    {
        res = generateNextPalindromeWhenAllNines(n);
    } else 
    {
        res = generateNextPalindrome(arr, n);
    }
    
    return res;
}
