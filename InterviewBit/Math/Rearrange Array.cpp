// https://www.quora.com/How-can-I-rearrange-a-given-array-so-that-Arr-I-becomes-Arr-Arr-I-with-O-1-extra-space
void Solution::arrange(vector<int> &A) {
   int n = A.size();

   // Encode both numbers by x + (y % n) * n and store in A[i]
   // y % n is because of we may have already the value at the index of value y.
   for(int i = 0; i < n; i++)
   {
       A[i] = A[i] + (A[A[i]] % n) * n;
   }

   // Finally decode to get the new value by A[i] / n
   for(int i = 0; i < n; i++)
   {
       A[i] = A[i] / n;
   }
}
