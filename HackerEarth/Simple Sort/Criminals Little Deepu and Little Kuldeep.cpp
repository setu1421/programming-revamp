#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/criminals-little-deepu-and-little-kuldeep/
// There is an easy solution present as well
#define ll long long int

int findOptimalPackets(vector<ll>&v, int n)
{
    int counter = 0;
    int low_bound = 0;
    int up_bound = n-1;
    int last_up_bound = 0;
    bool already_marked = true;
    bool no_marked_elem = false;

    vector<bool>mark(n);

    while(low_bound <= up_bound && already_marked)
    {
        counter = counter + 1;
        ll start_elem = v[low_bound];
        mark[low_bound] = true; // this is used
        already_marked = false;
        no_marked_elem = true;
        last_up_bound = 0;

        for(int i = low_bound + 1; i <= up_bound; i++)
        {
            if(mark[i] == false)
            {
                if(start_elem < v[i])
                {
                    mark[i] = true;
                    start_elem = v[i];
                    no_marked_elem = false;
                } else
                {
                    if(start_elem == v[i])
                    {
                        last_up_bound = i;
                    }
                    // If not already marked for new lower bound
                    if(!already_marked)
                    {
                        already_marked = true;
                        low_bound = i;
                    }
                }
            }
        }

        if(no_marked_elem && last_up_bound != 0)
        {
           counter += (last_up_bound - low_bound) + 1;
           break;
        }
    }

    mark.clear();

    return counter;

}


int main()
{
    //freopen("input.txt", "r",stdin);
    //freopen("output.txt", "w",stdout);
    int t;
    cin>>t;

    while(t--)
    {
       int n;
       ll num;
       vector<ll>v;

       cin>>n;
       for(int i = 0; i < n; i++)
       {
           cin>>num;
           v.push_back(num);
       }

       // This sort takes O(nlogn) times.
       sort(v.begin(), v.end());

       int ret = findOptimalPackets(v, v.size());
       cout<<ret<<endl;

       v.clear();
    }
}
