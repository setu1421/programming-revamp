#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend-returns/
typedef long long ll;

void merge_array(vector<ll> &v1, vector<ll>&v2, int n1, int n2)
{
    int i = 0, j = 0;
    bool first_num = true;

    while(i < n1 && j < n2)
    {
        if(v1[i] > v2[j])
        {
            if(first_num)
            {
                cout<<v1[i];
                first_num = false;
            } else
            {
                cout<<" " <<v1[i];
            }

            i++;
        } else
        {
            if(first_num)
            {
                cout<<v2[j];
                first_num = false;
            } else
            {
                cout<<" " <<v2[j];
            }
            j++;
        }
    }

    while(i < n1)
    {
        if(first_num)
        {
            cout<<v1[i];
            first_num = false;
        } else
        {
            cout<<" " <<v1[i];
        }
        i++;
    }

    while(j < n2)
    {
        if(first_num)
        {
            cout<<v2[j];
            first_num = false;
        } else
        {
            cout<<" " <<v2[j];
        }
        j++;
    }

    cout<<endl;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n, m, num;
        cin>>n>>m;

        vector<ll>v1;
        vector<ll>v2;

        for(int i = 0; i < n; i++)
        {
            cin>>num;
            v1.push_back(num);
        }

        for(int i = 0; i < m; i++)
        {
            cin>>num;
            v2.push_back(num);
        }

        merge_array(v1, v2, n, m);

        v1.clear();
        v2.clear();

    }
}
