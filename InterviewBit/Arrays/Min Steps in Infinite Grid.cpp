// https://www.youtube.com/watch?v=eAhBad1KoSw
#include <bits/stdc++.h>
using namespace std;

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {

    if(X.size()<=1) return 0;
    int ans=0;
    for(int i=1;i<X.size();i++)
    {
        ans+=max(abs(X[i]-X[i-1]),abs(Y[i]-Y[i-1]));

    }
    return ans;
}
