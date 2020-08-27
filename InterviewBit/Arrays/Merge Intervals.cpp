/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<Interval> ret;
    
    for(int i = 0; i < intervals.size(); i++)
    {
        Interval currentInterval = intervals[i];
        
        // Case 1: newInterval has to be put before the currentInterval
        if(newInterval.end < currentInterval.start)
        {
            ret.push_back(newInterval);
            newInterval = currentInterval;
        } 
        // Case 2: currentInterval has to be put before the newInterval
        else if(currentInterval.end < newInterval.start)
        {
            ret.push_back(currentInterval);
        } // Case 3: Overlap
        else 
        {
            newInterval.start = min(currentInterval.start, newInterval.start);
            newInterval.end = max(currentInterval.end, newInterval.end);
        }
    }
    
    ret.push_back(newInterval);
    
    return ret;
}
