int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    // If only one element present in the array,
    // then, no repeated number present
    if(n < 2)
    {
        return -1;
    }
    
    // Detect cycle using Floyd's cycle detection algo
    int slow = A[0];
    int fast = A[A[0]];
    
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    // Finally find the starting of the loop
    // https://www.youtube.com/watch?v=LUm2ABqAs1w
    fast = 0;
    while(slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    
    return slow;
}


// Observation for https://www.youtube.com/watch?v=LUm2ABqAs1w:

/*
(m+k) = integer*l -> this means, if you have p at the kth node and q at the start, by the time q travels m+k nodes from the start, p will finish one or more complete revolution on that loop. 

i.e., p and q will coincide at the kth node again. 

But if q only travels m nodes, p  has travelled only (integer*l)- k nodes as well. So if p started at the kth node, and q at the start, they will meet at the start of the loop.
*/

// Another Approach: Using bucketing
/*
Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).

Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.

At least one of the ranges will contain more than sqrt(n) elements.

Do another pass and process just those elements in the oversubscribed range.

Using a hash table to keep frequencies, you’ll find a repeated element.

This is O(sqrt(n)) memory and 2 sequential passes through the stream.
*/


int repeatedNumber(const vector<int>&A)
{
    int n=A.size()-1;
    int bucket_size=int(sqrt(n));
    vector<int>buckets(ceil((n+1)*1.0/bucket_size),0);
    // Place the elements in each bucket and increment the count.
    for(int i=0; i<A.size(); i++)
    {
        buckets[(A[i]-1) / bucket_size]++;
    }
    // If there are no buckets with more than bucket_size elements,
    // then definitely the last bucket will have duplicate elements.
    // For example: 4 1 2 3 5 5
    int check=buckets.size()-1;

    for(int i=0; i<buckets.size(); i++)
    {
        if(buckets[i]>bucket_size)
        {
            check=i;
            break;
        }
    }
    map<int,int>counts;
    // Determine the range of elements that fall into the bucket
    int left=check*bucket_size+1;
    int right=(check+1)*bucket_size+1;

    for(int i=0; i<A.size(); i++)
    {
        if(A[i]>=left && A[i]<right)
        {
            counts[A[i]]++;
            if(counts[A[i]]>1)
                return A[i];
        }
    }

    return -1;
}