#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<long long>Q;
    RecentCounter() {

    }

    int ping(int t) {
        Q.push(t);

        if(t > 3001)
        {
            while(!Q.empty() && Q.front() < (t - 3000))
            {
                Q.pop();
            }
        }

        return Q.size();
    }
};
