// Time Complexity: O(n)
// Space Complexity: O(n)
// https://www.youtube.com/watch?v=h6_lIwZYHQw&t=163s
int Solution::candy(vector<int> &A) {
    int n = A.size();
    if(n == 0)
    {
        return 0;
    }
    
    int left[n + 1], right[n + 1];
    
    fill_n(left, n, 1);
    fill_n(right, n, 1);
    
    for(int i = 1; i < n; i++)
    {
        if(A[i] > A[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }
    
    for(int i = n - 2; i >= 0; i--)
    {
        if(A[i] > A[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }
    
    long long res = 0;
    
    for(int i = 0; i < n; i++)
    {
        res += max(left[i], right[i]);
    }
    
    return res;
}

// Another approach: Using O(1) space
// https://medium.com/javarevisited/how-to-solve-the-minimum-candy-distribution-problem-4c868740f16a
public int candy(int[] ratings) {
      if (ratings.length < 2) {
          return ratings.length;
      }
         
      int count = 1;
      int upSlopeLength = 0;
      int upSlope = 0;
      int downSlope = 0;
         
      for (int i=1; i<ratings.length; i++) {
          int previous = ratings[i-1];
          int me = ratings[i];
          
          // ** Equal Ratings **   
          if (me == previous) {
              upSlope = 0;
              downSlope = 0;
              upSlopeLength = 0;
              count += 1;
          // ** Upward Slope **
          } else if (me > previous) {
              upSlope = upSlope == 0 ? 1 : upSlope;
              upSlope += 1;
              downSlope = 0;
              count += upSlope;
              upSlopeLength = upSlope;
          // ** Downward Slope **
          } else {
              upSlope = 0;
              downSlope += 1;
              int slopeDiff = 
                (downSlope + 1 - upSlopeLength) > 0 ? 1 : 0;
              count += downSlope + slopeDiff;         
          }     
      }
      return count;  
}
