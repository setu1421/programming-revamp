#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(0);cin.tie(0);}}$;

// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/median-game-june-easy-19-3722be60/

#define MAX_NUM INT_MAX
#define MIN_NUM INT_MIN

int main()
{
    int t, n;
    cin>>t;

    while(t--)
    {
        int num, maxn = MIN_NUM, minn = MAX_NUM;
        cin>>num;

        while(num--)
        {
            cin>>n;
            maxn = max(n, maxn);
            minn = min(n, minn);
        }

        cout<< maxn + minn << endl;

    }
}
