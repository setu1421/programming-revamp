#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/pizza-confusion/


int main()
{

   int n, value, selected_value;
   string name, selected_name;

   cin >> n;

   for(int i = 0; i < n; i++)
   {
       cin >> name >> value;

       if(i != 0)
       {
           if(selected_value < value)
           {
              selected_value = value;
              selected_name = name;
           } else if(selected_value == value)
           {
              selected_name = min(name, selected_name);
           }
       } else
       {
           selected_name = name;
           selected_value = value;
       }
   }

   cout<<selected_name<<endl;
}
