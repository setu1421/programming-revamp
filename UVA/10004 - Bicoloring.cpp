#include<bits/stdc++.h>
using namespace std;

#define MAXN 205

string bfs(int colors[MAXN], vector<int> graph[MAXN])
{
    queue<int> q;
    q.push(0);
    colors[0] = 0;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        int current_color = colors[top];

        for(int i = 0; i < graph[top].size(); i++)
        {
            int v = graph[top][i];

            if(colors[v] == current_color)
            {
                return "NOT BICOLORABLE.";
            } else if (colors[v] == -1)
            {
                colors[v] = !current_color;
                q.push(v);
            }
        }
    }

    return "BICOLORABLE.";
}

int main()
{
    int nodes, edges, u, v;

    while(scanf("%d", &nodes))
    {
        if(nodes == 0) break;

        int colors[MAXN];
        vector<int> graph[MAXN];
        memset(colors, -1, sizeof(colors));

        scanf("%d", &edges);
        for(int i = 0; i < edges; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout<<bfs(colors, graph)<<endl;
    }

    return 0;
}
