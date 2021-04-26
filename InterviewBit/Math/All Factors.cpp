vector<int> Solution::allFactors(int A) {
 vector<int> ans;
 
 if(A < 2)
 {
     ans.push_back(A);
     return ans;
 }
 
 int upperlimit = sqrt(A);
 
 for(int i = 1; i * i < A; i++)
 {
     if(A % i == 0)
     {
         ans.push_back(i);
     }
 }
 
 for(int i = upperlimit; i>=1; i--)
 {
     if(A % i == 0)
     {
         ans.push_back(A / i);
     }
 }
  
 return ans;
}
