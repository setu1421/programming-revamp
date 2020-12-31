// https://www.youtube.com/watch?v=wDgKaNrSOEI

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size();
    int diff_total = 0, starting = 0, tank = 0;
    
    for(int i = 0; i < n; i++)
    {
        diff_total += (gas[i] - cost[i]);
    }
    
    if(diff_total < 0)
    {
        return -1;
    } else
    {
        for(int i = 0; i < n; i++)
        {
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                starting = i + 1;
                tank = 0;
            }
        }
    }
    
    return starting;
}
