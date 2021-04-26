// https://www.quora.com/How-can-I-rearrange-a-given-array-so-that-Arr-I-becomes-Arr-Arr-I-with-O-1-extra-space
// https://www.youtube.com/watch?v=XAbG2Bjs6NA
void Solution::arrange(vector<int> &A) {
   int n = A.size();

   // Encode both numbers by x + (y % n) * n and store in A[i]
   // y % n is because of we may have already the value at the index of value y.
   for(int i = 0; i < n; i++)
   {
       A[i] = A[i] + (A[A[i]] % n) * n; // We are doing A[A[i]] % N to get the original value during calculation
   }

   // Finally decode to get the new value by A[i] / n
   for(int i = 0; i < n; i++)
   {
       A[i] = A[i] / n;
   }
}

/* 
A = A + B * N
A = A % N // old value
A = A / N // new value
*/