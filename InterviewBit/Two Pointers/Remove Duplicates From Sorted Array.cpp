int Solution::removeDuplicates(vector<int> &A) {
   int n = A.size();
   int i = 0, j = 1;
   
   while(i < n && j < n)
   {
       // If same element the skip that element
       if(A[i] == A[j])
       {
           j++;
       } // Otherwise, place the element in the next position and check for next element
       else
       {
           i++;
           swap(A[i], A[j]);
           j++;
       }
   }
   
   // ith position is the last position of distinct element
   return (i + 1);
}
