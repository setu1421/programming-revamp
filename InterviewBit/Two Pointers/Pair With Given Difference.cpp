/*
Method 1: Brute Force
The simplest method is to run two loops, the outer loop picks the first element (smaller element) and the inner loop looks for the element picked by outer loop plus B.
Time complexity of this method is O(N^2). This wil not work lets us look on an optimized method.

Method 2: Sorting + Binary Search
We can use sorting and Binary Search to improve time complexity to O(NLogN).

The first step is to sort the array in ascending order.
Once the array is sorted, traverse the array from left to right, and for each element A[i], binary search for A[i] + B in A[i+1..n-1]. If the element is found, return 1.
Both first and second steps take O(NLogN). So overall complexity is O(NLogN).
Time Complexity : O(NlogN + NlogN)

Method 3: Sorting + Two Pointers
The second step of the above algorithm can be improved to O(N). The first step remain same.
The idea for second step:

Take two index variables i and j, initialize them as 0 and 1 respectively.
Now run a linear loop. If A[j] – A[i] is smaller than B, we need to look for greater A[j], so increment j.
If A[j] – A[i] is greater than B, we need to look for greater A[i], so increment i.
Time Complexity : O(NlogN + N)

Methos 4: Hashing
Create an empty hash table HT. Traverse the array, use array elements as hash keys and enter them in HT.
Traverse the array again look for value B + A[i] in HT.
Time Complexity: O(N) if we use unordered_map
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 1;
    B = abs(B);
    
    sort(A.begin(), A.end());
    
    while(i < n && j < n)
    {
        if(i == j)
        {
            j++;
        };
        
        int diff = abs(A[j] - A[i]);
        
        if(diff == B)
        {
            return 1;
        } else if(diff > B)
        {
            i++;
        } else
        {
            j++;
        }
    }
    
    return 0;
}

// Another solution using Hashing
int Solution::solve(vector<int> &A, int B) {
	if(B == 0) return 0;
	
    int n = A.size();
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        mp[A[i]] = 1;
    }
   
    for(int i = 0; i < n; i++)
    {
        if(mp.find(A[i] + B) != mp.end())
        {
            return 1;
        }
    }
    
    
    return 0;
}

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> umap;
    for(auto it: A)
    {
        if(umap[it - B] || umap[it + B])
        {
            return 1;
        }
        else 
        {
            umap[it] ++;
        }
    }

    return 0;
}