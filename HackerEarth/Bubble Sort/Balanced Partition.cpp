#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/balanced-partition-818edecd/
//TimeComplexity: O(nlogn)
const int X = 1000;
const int off = 2 * X + 50;

void isBalancedPartition(vector< pair<int, int> > v)
{
    vector<int> sum(4 * off);

    // Sum of number of houses at x points. Multiple house points can be present at a particular x value
    for(auto e: v)
    {
        sum[e.first + off] += e.second;
    }

    int all = accumulate(sum.begin(), sum.end(), 0LL);

    bool found = false;

    for(int i = 1; i < sum.size(); i++)
    {
        sum[i] += sum[i-1];
        /*
          Two Conditions:
            1. If the line passes through the point
            2. If the line passes through i and i+1 point
        */
        if((2*sum[i] == all) || (sum[i-1] == all - sum[i]))
        {
            found = true;
        }
    }

    if(found)
    {
        cout<< "YES"<<endl;
    } else
    {
        cout<<"NO"<<endl;
    }
}


int main()
{
    //freopen("input.txt", 'r', stdin);
    //freopen("output.txt", 'w', stdout);
   int t;

   cin>>t;

   while(t--)
   {
       int no_of_house;

       cin>>no_of_house;

       vector< pair<int,int> > v(no_of_house);

       for(int i = 0; i < no_of_house; i++)
       {
           int x,y,h;
           cin>>x>>y>>h;

           // rotate the point to 45 degree. We will compare all the points by parallel to y axis
           v[i] = make_pair(x-y, h);
       }

       // Sort the points based x value in the x axis
       sort(v.begin(), v.end());

       isBalancedPartition(v);
   }
}
