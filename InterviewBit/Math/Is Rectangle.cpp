int Solution::solve(int A, int B, int C, int D) {
    if(A == B == C == D)
    {
        return 1;
    } else if(A == B && C == D)
    {
        return 1;
    } else if(A == C && B == D)
    {
        return 1;
    } else if(A == D && B == C)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//Another Solution: Using unordered_map
int Solution::solve(int A, int B, int C, int D) {
   unordered_map<int, int> mp;
   
   mp[A]++;mp[B]++;mp[C]++;mp[D]++;
   
   for(auto p: mp)
   {
       if(p.second % 2 != 0)
       {
           return 0;
       }
   }
   
   return 1;
}

