vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n = A.size(), index = 0;
    vector<string>res;
    
    while(index < n)
    {
        int count = A[index].length();
        int last = index + 1;
        
        while(last < n && (count + A[last].length() + 1) <= B)
        {
            count += A[last].length() + 1;
            last++;
        }
        
        int difference = last - index - 1;
        string line = "";
        // last line or a line with only one word
        if(difference == 0 || last == n)
        {
            for(int i = index; i < last; i++)
            {
                line += A[i] + " ";
            }
            // Erase the last empty space
            line.erase(line.end() - 1);
            // Add the empty space if required to make B characters in a line
            for(int i = line.length() + 1; i <= B; i++)
            {
                line += " ";
            }
        } else
        {
            int spaces = (B - count) / difference;
            int extra_spaces = (B - count) % difference;
            
            for(int i = index; i < last; i++)
            {
                line += A[i];
                
                int total_space = spaces + ((extra_spaces > 0) ? 1 : 0);
                extra_spaces--;
                
                if(i < last - 1)
                {
                    for(int j = 0; j <= total_space; j++)
                    {
                        line += " ";
                    }
                }

            }
        }
        
        res.push_back(line);
        index = last;
    }
    
    return res;
}
