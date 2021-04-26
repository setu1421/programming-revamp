int Solution::isPrime(int A) {
    if(A < 2)
      return 0;
    if(A == 2)
      return 1;
    int x = sqrt(A);
    
    for(int i = 2;i <= x;i++)
    {
        if(A % i == 0)
          return 0;
    }
    return 1;
}
