string Solution::convert(string A, int B) {
    int n = A.length(), row = 0;
    bool down = true;
    vector<string>v(B);
    
	// Corner Case: If row number is only one, then just return A
    if(B == 1)
    {
        return A;
    }
    
    for(int i = 0; i < n; i++)
    {
        v[row].push_back(A[i]);
        
		// If we reach the down row, then next move up
        if(row == B - 1)
        {
            down = false;
        } // If we reach the top row, then next move down
		else if(row == 0)
        {
            down = true;
        }
        
        if(down)
        {
            row++; // go to next row top to down
        } else
        {
            row--; // go to next row from down to top
        }
    }
    
    string res = "";
    for(int i = 0; i < B; i++)
    {
        res += v[i];
    }
    
    return res;
}
