int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    
    int left = 0, right = n - 1;

    int indx = -1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if(A[mid] == B)
        {
            indx = mid;
            break;
        } else if(A[mid] < B)
        {
            left = mid + 1;
        } else 
        {
            right = mid - 1;
        }
    }
    
    if(indx == -1)
    {
        return 0;
    } else
    {
        int temp = indx + 1, count = 1;
        while(temp < n && A[temp] == B)
        {
            count++;
            temp++;
        }
        temp = indx - 1;
        while(temp >= 0 && A[temp] == B)
        {
            count++;
            temp--;
        }
        
        return count;
    }
}
