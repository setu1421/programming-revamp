// https://www.geeksforgeeks.org/find-minimum-moves-reach-target-infinite-line/
int Solution::solve(int A) {
    int target = abs(A);
    
    int sum = 0, step_count = 0;
    
    while(sum < target || (sum - target) % 2 != 0)
    {
        step_count++;
        sum += step_count;
    }
    
    return step_count;
}
