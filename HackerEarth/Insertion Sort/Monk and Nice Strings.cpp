#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/practice-problems/algorithm/monk-and-nice-strings-3/

void calculate_niceness(int n, vector<string>arr)
{
    string value;
    int hole, niceness_counter = 0;

	// The niceness will be always 0 for the first element
    cout<<niceness_counter<<endl;

    for(int i = 1; i < n; i++)
    {
        value = arr[i];
        hole = i;
        niceness_counter = 0;

        while(hole > 0)
        {
            int compare_ret = strcmp(arr[hole-1].c_str(), value.c_str());
            // if the left string is less than the value, then we need to increase the counter 
            if(compare_ret < 0)
            {
                niceness_counter++;
            }

            hole = hole - 1;
        }

        cout<< niceness_counter <<endl;
    }
}
int main()
{
    int n;
    cin>>n;

    vector<string>arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    calculate_niceness(n, arr);

}
