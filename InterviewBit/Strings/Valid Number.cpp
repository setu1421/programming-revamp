int Solution::isNumber(const string A) {
    int n = A.length();
    
	// Removing white space from the left
    int i = 0;
    while(i < n && A[i] == ' ')
    {
        i++;
    }
    // Removing white space from the right
    int j = n - 1;
    while(j > i && A[j] == ' ')
    {
        j--;
    }
    
    bool num_seen = false, e_seen = false, dot_seen = false;
    for(int k = i; k <= j; k++)
    {
        if(isdigit(A[k]))
        {
            num_seen = true;
        } else if(A[k] == 'e')
        {
			// if we encounter e, then we should see a number before that or should not see e before.
            if(e_seen == true || num_seen == false)
            {
                return false;
            } else
            {
                e_seen = true;
				// making num_seen false as after e we should see a number to a valid number
                num_seen = false;
            }
        } else if(A[k] == '.')
        {
			// before dot "e" can not appear
            if(dot_seen == true || e_seen == true)
            {
                return false;
            } else
            {
                dot_seen = true;
				// making num_seen false as after dot we should see a number to a valid number
                num_seen = false;
            }
        } else if(A[k] == '-' || A[k] == '+')
        {
			// - or + should found at the first index or if found in other indices then before that we should see a "e"
            if(k != i && A[k - 1] != 'e')
            {
                return false;
            }
        } else
        {
            return false;
        }
    }
    
    return num_seen;
}
