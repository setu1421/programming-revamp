#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
   int T = 0, B = A.size() - 1, L = 0, R = A[0].size() - 1;
   int dir = 0;

   vector<int> ret;

   while(T <= B && L <= R)
   {
       if(dir == 0)
       {
           for(int i = L; i <= R; i++)
           {
               ret.push_back(A[T][i]);
           }
           T++;
       } else if(dir == 1)
       {
           for(int i = T; i <= B; i++)
           {
               ret.push_back(A[i][R]);
           }
           R--;
       } else if(dir == 2)
       {
           for(int i = R; i >= L; i--)
           {
               ret.push_back(A[B][i]);
           }
           B--;
       } else
       {
           for(int i = B; i >= T; i--)
           {
               ret.push_back(A[i][L]);
           }
           L++;
       }

       dir = (dir + 1) % 4;
   }

   return ret;
}

int main()
{

    vector<vector<int> > A = {{1,2,3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> ret = spiralOrder(A);

    for(int i = 0; i < ret.size(); i++)
    {
       cout<< ret[i] << " ";
    }
}
