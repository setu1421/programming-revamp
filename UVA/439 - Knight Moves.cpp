#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAXN 10

int fx[]={1, -1, 1, -1, 2, 2, -2, -2};
int fy[]={2, 2, -2, -2, 1, -1, 1, -1};

int vis[MAXN][MAXN], dis[MAXN][MAXN];

int bfs(string src, string dest)
{
    int src_row = src[0] - 'a' + 1 , src_col = src[1] - '0';
    int dest_row = dest[0] - 'a' + 1, dest_col = dest[1] - '0';

    queue<pii>Q;
    Q.push(pii(src_row, src_col));
    vis[src_row][src_col] = 1;
    dis[src_row][src_col] = 0;

    while(!Q.empty())
    {
        pii top = Q.front(); Q.pop();

        if(top.first == dest_row && top.second == dest_col)
        {
            return dis[top.first][top.second];
        }

        for(int i = 0; i < 8; i++)
        {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];



            if(ty >= 1 && ty <= 8 && tx >= 1 && tx <= 8 && vis[tx][ty] == 0)
            {
                Q.push((pii(tx, ty)));
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[top.first][top.second] + 1;
            }
        }
    }

    return 0;
}

int main()
{
    string src, dest;

    while(cin>>src>>dest)
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        int ret = bfs(src, dest);
        cout<<"To get from "<<src<<" to " << dest << " takes "<< ret << " knight moves."<<endl;
    }

    return 0;
}
