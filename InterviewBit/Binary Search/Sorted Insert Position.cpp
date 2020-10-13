int Solution::searchInsert(vector<int> &A, int B) {
   int n = A.size();
   int low = 0, high = n - 1;
   
   while(low <= high)
   {
       int mid = low + (high - low) / 2;
       
       if(A[mid] == B)
       {
           return mid;
       } else if(A[mid] > B)
       {
           high = mid - 1;
       } else 
       {
           low = mid + 1;
       }
   }
   
   return low;
}
