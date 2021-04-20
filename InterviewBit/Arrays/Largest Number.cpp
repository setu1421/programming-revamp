bool mycompare(string a, string b)
{
    return (a + b) > (b + a);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string>v;
    string result;
    
    for(int i = 0; i < A.size(); i++)
    {
        v.push_back(to_string(A[i]));
    }
    
    sort(v.begin(), v.end(), mycompare);
    // Check if the first number in the sorted array is zero, then larget number will only be 0.
    if(stoi(v[0]) == 0)
    {
        return "0";
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        result += v[i];
    }
    
    return result;
}
