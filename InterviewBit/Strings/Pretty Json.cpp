vector<string> Solution::prettyJSON(string A) {
    int n = A.length();
    int tabs_level = 0;
    string temp = "";
    vector<string>res;
    
    for(int i = 0; i < n; i++)
    {
		// Check for open brackets
        if(A[i] == '{' || A[i] == '[')
        {
			// If there is any string before, then push them in a line.
            if(temp.length() > 0)
            {
                string space(tabs_level, '\t');
                space += temp;
                res.push_back(space);
                temp = "";
            }
            // After that, add the open brackets with the same spaces in a new line
            string open(tabs_level, '\t');
            open += A[i];
            res.push_back(open);
            tabs_level++;
        } else if(A[i] == '}' || A[i] == ']')
        {
			// If there is any string before, then push them in a line.
            if(temp.length() > 0)
            {
                string space(tabs_level, '\t');
                space += temp;
                res.push_back(space);
                temp = "";
            }
            // After that, add the closed brackets by decreasing one tab in a new line
            tabs_level--;
            string close(tabs_level, '\t');
            close += A[i];
            // Check if there is any comma after the closed brackets. If present, take that comma.
            if(i + 1 < n && A[i + 1] == ',')
            {
                close += A[i + 1];
                i++;
            }
            
            res.push_back(close);
        } else if(A[i] == ',')
        {
            string space(tabs_level, '\t');
            space += temp + A[i];
            res.push_back(space);
            temp = "";
        } else
        {
            temp += A[i];
        }
    }
    
    return res;
}
