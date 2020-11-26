/* we have 2 choices for each of the n bits either we  
   can include i.e invert the bit or we can exclude the  
   bit i.e we can leave the number as it is. */
   
void grayCodeUtil(vector<int> &res, int n, int &num)
{
    // base case when we run out bits to process 
    // we simply include it in gray code sequence.
    if(n == 0)
    {
        res.push_back(num);
        return;
    }
    // ignore the bit. 
    grayCodeUtil(res, n - 1, num);
    // invert the bit. 
    num = num ^ (1 << (n - 1));
    grayCodeUtil(res, n - 1, num);
}

vector<int> Solution::grayCode(int A) {
    vector<int> res;
    int num = 0;
    
    grayCodeUtil(res, A, num);
    
    return res;
}
