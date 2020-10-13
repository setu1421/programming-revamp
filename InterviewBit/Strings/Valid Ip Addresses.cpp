bool isValidPart(string part)
{
    int n = part.length();
    // if the part length is greater than 3
    if(n > 3)
    {
        return false;
    } // 011, 01 invalid part. Only 0 is valid.
    else if(part != "" && part[0] == '0' && n > 1)
    {
        return false;
    }
    
    int partValue = stoi(part);
    
    return partValue >= 0 && partValue <= 255;
}
 
vector<string> Solution::restoreIpAddresses(string A) {
    int n = A.length();
    vector<string>res;
    
    for(int i = 1; i < n && i < 4; i++)
    {
        string firstPart = A.substr(0, i);
        if(!isValidPart(firstPart))
        {
            continue;
        }
        
        for(int j = 1; i + j < n && j < 4; j++)
        {
            string secondPart = A.substr(i, j);
            if(!isValidPart(secondPart))
            {
                continue;
            }
            
            for(int k = 1; i + j + k < n && k < 4; k++)
            {
                string thirdPart = A.substr(i + j, k);
                string fourthPart = A.substr(i + j + k);
                if(!isValidPart(thirdPart) || !isValidPart(fourthPart))
                {
                    continue;
                }
                
                res.push_back(firstPart + "." + secondPart + "." + thirdPart + "." + fourthPart);
            }
        }
    }
    
    return res;
}

// Using backtracking
void backtrack(vector<string> &v, string A, int n, string ip, int indx, int depth)
{
	// depth must be 4 and full string must be covered
    if(depth == 4)
    {
        if(indx == n)
        {
			// erase the last dot and add to the result vector
            ip.erase(ip.end() - 1);
            v.push_back(ip);
            return; 
        } else
        {
            return;
        }
    }
    
    for(int len = 1; len <= 3; len++)
    {
		// only 0 is valid but 00, 01, 000, 001 is not valid
        if(A[indx] == '0' && len > 1)
        {
            return;
        }
        // out of index => invalid
        if(indx + len > n)
        {
            return;
        }
        
        string part = A.substr(indx, len);
        if(stoi(part) < 256)
        {
            backtrack(v, A, n, ip + part + ".", indx + len, depth + 1);
        } else
        {
            return;
        }
    }
}
 
vector<string> Solution::restoreIpAddresses(string A) {
    int n = A.length();
    vector<string>res;
    backtrack(res, A, n, "", 0, 0);
    
    return res;
}