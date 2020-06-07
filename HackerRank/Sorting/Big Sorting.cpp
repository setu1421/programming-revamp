#include<bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/big-sorting/problem
// We can improve upon the comparison function here.
// When the length of two values are equal then we can check lexicographically instead of looping though the two values
bool cmp_number(const string s1, const string s2)
{
   if(s1.length() > s2.length())
   {
       return false;
   } else if (s1.length() < s2.length())
   {
       return true;
   }

   // Had to separate out equal condition from else because of strict weak ordering of sort compare function
   // https://stackoverflow.com/questions/60108990/hackerrank-big-sorting-segmentation-fault-in-c
    for(int i = 0; i < s1.length(); i++)
       {
          if(s1[i] - '0' > s2[i] - '0')
          {
              return false;
          } else if(s1[i] - '0' < s2[i] - '0')
          {
              return true;
          }
       }

   return false;
}


int main()
{
    int n; string s;
    cin>>n;
    vector<string>v;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp_number);

    for(int i = 0; i < n; i++)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}
