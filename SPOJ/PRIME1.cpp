#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// Time Complexity: O(n*log(log(n)))

void SeiveOfEratosthenes(int limit, bool *prime_within_limit, vector<int> &prime)
{
    memset(prime_within_limit, true, limit);
    prime_within_limit[0] = false, prime_within_limit[1] = false, prime_within_limit[2] = true;

    for(int i = 0; i <= sqrt(limit); i++)
    {
        // If it is a prime number, then mark all the composites as non prime
        if(prime_within_limit[i] == true) {
            for(int j = 2; i*j <= limit; j++)
            {
                prime_within_limit[i*j] = false;
            }
        }
    }

    for(int i = 0; i <= limit; i++)
    {
        // If prime, then push into the prime array
        if(prime_within_limit[i])
        {
           prime.push_back(i);
        }
    }
}

void segmented_seive(int range_a, int range_b, int limit, bool *prime_within_limit, vector<int> &prime)
{
    int low, high;
   if(range_a <= limit)
   {
       for(int k = range_a; k <= limit; k++)
       {
           if(prime_within_limit[k])
           {
               cout<<k<<endl;
           }
       }
      low = limit + 1;
      high = 2*limit;
    } else {
        low = range_a;
        high = low + limit;
    }

   // Print the

   while(low < range_b)
   {
       if(high > range_b)
       {
           high = range_b;
       }

       bool mark[high-low+1];
       memset(mark, true, sizeof(mark));

       for(int i = 0; i < prime.size(); i++)
       {
          int lowLimit = floor(low / prime[i]) * prime[i];
          if(lowLimit < low) {
            lowLimit = lowLimit + prime[i];
          }

          for(int j = lowLimit; j <= high; j += prime[i])
          {
              mark[j - low] = false;
          }
       }

       for(int i = low; i <= high; i++)
       {
           if(mark[i-low])
           {
               cout<<i<<endl;
           }
       }

       low = low + limit;
       high = high + limit;
   }

}

int main()
{
    int limit = floor(sqrt(1000000000)) + 1;
    bool prime_within_limit [limit + 1];
    vector<int> prime;
    SeiveOfEratosthenes(limit, prime_within_limit, prime);

    int test_cases;
    scanf("%d", &test_cases);

    while(--test_cases >= 0)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(b <= limit) {
            for(int i = a; i <= b; i++)
            {
                if(prime_within_limit[i])
                {
                    cout<<i<<endl;
                }
            }
        } else
        {
            // Segmented Sieve
            segmented_seive(a, b, limit, prime_within_limit, prime);
        }

        if(test_cases != 0)
        {
            cout<<endl;
        }
    }
}
