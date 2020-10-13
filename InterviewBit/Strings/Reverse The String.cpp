string Solution::solve(string A) {
    int n = A.length();
    
    int i = 0;
    
    while(i < n)
    {
        if(A[i] != ' ')
        {
            break;
        }
        i++;
    }
    
    int j = n - 1;
    
    while(j >= 0)
    {
        if(A[j] != ' ')
        {
            break;
        }
        j--;
    }
    
    stack<string>ss;
    
    string word = "";
    while(i <= j)
    {
        while(i <= j && A[i] != ' ')
        {
            word += A[i];
            i++;
        }
        
        if(word != "")
        {
            ss.push(word);
            word = "";
        }

        i++;
    }
    
    string res = "";
    bool isFirstWord = true;
    
    while(!ss.empty())
    {
        if(!isFirstWord)
        {
            res += " ";
        } else 
        {
            isFirstWord = false;
        }
        res += ss.top();
        ss.pop();
    }
    
    return res;
}

// Another Approach: Using stringsteam

string Solution::solve(string A) {
    stringstream ss(A);
    string temp;

    vector<string>v;

    while(ss >> temp)
    {
        v.push_back(temp);
    }

    string res = "";

    for(int i = v.size() - 1; i > 0; i--)
    {
        res += v[i] + " ";
    }

    res += v[0];

    return res;
}

