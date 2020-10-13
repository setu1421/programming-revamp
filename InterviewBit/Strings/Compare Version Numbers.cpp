int compareString(string A, string B)
{
    int m = A.length(), n = B.length();
    
    int i = 0, j = 0;
    while(i < m && A[i] == '0')
    {
        i++;
    }
    
    while(j < n && B[j] == '0')
    {
        j++;
    }
    
    A = A.substr(i, m - i);
    B = B.substr(j, n - j);
    
    m = A.length(), n = B.length();
    
    if(m > n)
    {
        return 1;
    } else if(m < n)
    {
        return -1;
    } else
    {
        for(int i = 0; i < m; i++)
        {
            int a = A[i] - '0';
            int b = B[i] - '0';
            
            if(a > b)
            {
                return 1;
            } else if(a < b)
            {
                return -1;
            }
        }
    }
    
    return 0;
}

int Solution::compareVersion(string A, string B) {
    int m = A.length(), n = B.length();
    
    string vnum1, vnum2;
    
    for(int i = 0, j = 0; i < m || j < n;)
    {
        vnum1 = "", vnum2 = "";
        
        while(i < m && A[i] != '.')
        {
            vnum1 += A[i];
            i++;
        }
        
        while(j < n && B[j] != '.')
        {
            vnum2 += B[j];
            j++;
        }
        
        int ret = compareString(vnum1, vnum2);
        
        if(ret == 1)
        {
            return 1;
        } else if(ret  == -1)
        {
            return -1;
        } else 
        {
            i++;
            j++;
        }
    }
    
    return 0;  
}
