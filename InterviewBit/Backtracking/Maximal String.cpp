// https://youtu.be/5crucASFoA4
/* Complexity Analysis:  

Time Complexity: O((n^2)^k). 
	For every recursive call, n^2 recursive calls is generated until the value of k is 0. So total recursive calls are O((n^2)^k).
Space Complexity:O(n). 
	This is the space required to store the output string.
*/

void maximalStr(string &ans, string &str, int index, int B)
{
    if(B == 0)
    {
        return;
    }
    
    for(int i = index; i < str.length() - 1; i++)
    {
        for(int j = i + 1; j < str.length(); j++)
        {
            if(str[i] < str[j])
            {
                swap(str[i], str[j]);
				
                if(str > ans)
                {
                    ans = str;
                }
				
                maximalStr(ans, str, index + 1, B - 1);
                swap(str[i], str[j]); 
            }
        }
    }
}

string Solution::solve(string A, int B) {
    string ans;
    
    maximalStr(ans, A, 0, B);
    
    return ans;
}

/* Another approach:
Approach: The above approach traverses the whole string at each recursive call which is highly inefficient and unnecessary. Also, pre-computing the maximum digit after the current at a recursive call avoids unnecessary exchanges with each digit. It can be observed that to make the maximum string, the maximum digit is shifted to the front. So, instead of trying all pairs, try only those pairs where one of the elements is the maximum digit which is not yet swapped to the front. 
*/

// Time Complexity: O(n^k).
void findMaximumNum(string &str, int k, string& max, int curr)
{
    // return if no swaps left
    if (k == 0)
        return;
 
    int n = str.length();
 
    // Consider every digit after
    // the curr position
    char maxm = str[curr];
    for (int j = curr + 1; j < n; j++) {
        // Find maximum digit greater than at curr among rest
        if (maxm < str[j])
        {
            maxm = str[j];
        }
    }
    
    if(maxm == str[curr])
    {
        findMaximumNum(str, k, max, curr + 1);
    } else
    {
        // search this maximum among the rest
        for (int j = curr + 1; j < n; j++) 
        {
            // If digit equals maxm swap
            // the digit with current
            // digit and recurse for the rest
            if (str[j] == maxm) 
            {
                // swap str[curr] with str[j]
                swap(str[curr], str[j]);
     
                // If current num is more than maximum so far
                if (str > max)
                {
                    max = str;
                }
                    
                // recurse other swaps after curr
                findMaximumNum(str, k - 1, max, curr + 1);
     
                // Backtrack
                swap(str[curr], str[j]);
            }
        }
    }
}

string Solution::solve(string A, int B) {
    string ans;
    
    findMaximumNum(A, B, ans, 0);
    
    return ans;
}


