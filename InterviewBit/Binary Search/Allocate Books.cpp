// How to prove that the solution will use all the students?
/*
If the size of the array is >= B and you are able to distribute the books optimally to let’s say x number of students where x < B while ensuring that none of the student has got more than ans no. of books then, it is very much possible that you can have x = B as well.

This is because now you have B-x children left to which you want to give the books. Now since the array A’s size is greater then B, it means that in your current distribution, there will definitely be children to whom you have given more than one book.
From these children, you can take the extra books except one, and distribute these extra books to the remaining B-x children. Just don’t take the books from the children which holds the books with ans number of pages, since then you answer (max number of pages) will still reduce further.
*/
int findStudentRequired(vector<int> &A, long long mid)
{
    int count = 0;
    
    for(int i = 0; i < A.size(); i++)
    {
        long long sum = 0ll; count++;
        
        while(sum + A[i] <= mid)
        {
            sum += A[i];
            i++;
        }
        
        i--;
    }
    
    return count;
}


int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    
    // If no of students is greater than no of books
    if(B > n)
    {
        return -1;
    }
    
    long long low = INT_MIN, high = 0ll;
    long long ans = INT_MAX;
    
    for(int i = 0; i < n; i++)
    {
        low = max(low, (long long) A[i]);
        high += A[i];
    }
    
    // If no of students is equal to no of books.
    if(B == n)
    {
        return (int) low;
    }
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        
        int students_req = findStudentRequired(A, mid);
        
        if(students_req > B)
        {
            low = mid + 1;
        } else
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    
    if(ans == INT_MAX)
    {
        ans = -1;
    }
    
    return (int) ans;
    
}
