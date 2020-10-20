int Solution::removeElement(vector<int> &A, int B) {
   int n = A.size();
   int i = -1, j = 0;
   
   while(i < n & j < n)
   {
	   // If element is same as B, then skip.
       if(A[j] == B)
       {
           j++;
       } // Otherwise, place that element in the next position and check for other elements
	   else
       {
           i++;
           swap(A[i], A[j]);
           j++;
       }
   }
   // Set i to -1 at first as all the elements in the array can be only B. In that case, element count will be 0
   return (i + 1);
}
