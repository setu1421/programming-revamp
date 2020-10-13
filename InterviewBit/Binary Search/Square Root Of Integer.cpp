int Solution::sqrt(int A) {
    int low = 1, high = A;
    int res;
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        
        long long square = mid * mid;
        long long next_square = (mid + 1) * (mid + 1);
        
        if(square <= A && next_square > A)
        {
            res = mid;
            break;
        } else if(square > A)
        {
            high = mid - 1;
        } else
        {
            low = mid + 1;
        }
    }
    
    return res;
}

// Another approach without using long long
int Solution::sqrt(int A) {
    int low = 1, high = A;
    int res;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
		// mid * mid < a can be replaced as mid < a / mid to overcome the overflow
        if(mid <= A / mid)
        {
			// store the result and move the low to mid + 1
            res = mid;
            low = mid + 1;
        }else
        {
            high = mid - 1;
        }
    }

    return res;
}
