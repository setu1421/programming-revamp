/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool mycomp(Interval a, Interval b)
 {
     return a.start < b.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end(), mycomp);
    
    int index = 0;
    
    for(int i = 1; i < A.size(); i++)
    {
        if(A[index].end >= A[i].start)
        {
            A[index].end = max(A[index].end, A[i].end);
        } else
        {
            index++;
            A[index] = A[i];
        }
    }
    
    vector<Interval>ret;
    
    for(int i = 0; i <= index; i++)
    {
        ret.push_back(A[i]);
    }
    
    return ret;
}
