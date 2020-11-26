void generateParenthesisUtil(vector<string> &res, string str, int A, int count, int diff)
{
	// If all the closing and opening brackets are added
    if(diff == 0 && count == A)
    {
        res.emplace_back(str);
        return;
    }
    // If already all the opening brackets added then return.
    if(count == A)
    {
        return;
    }
    // add the opening bracket, increment the opening bracket counts.
    str += "(";
    count++;
    diff++;
    
    generateParenthesisUtil(res, str, A, count, diff);
    // add the closing brackets based on diff which is the count of how many close brackets need to be addded.
    while(diff > 0)
    {
		// add the closing bracket and decrement the diff for adding closing brackets.
        str += ")";
        diff--;
        generateParenthesisUtil(res, str, A, count, diff);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    string str = "";
    
    generateParenthesisUtil(res, str, A, 0, 0);
    
    return res;
}
