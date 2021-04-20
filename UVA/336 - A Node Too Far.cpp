#include<bits/stdc++.h>
using namespace std;

#define MAXN 31

int findUnreachabledNodes(int start, int ttl, vector<int> graph[MAXN], int visited[MAXN], unordered_map<int, int> &mp)
{
    queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    int res = 0;

    while(!Q.empty())
    {
        int qSize = Q.size();
        if(ttl == 0)
        {
            break;
        }

        while(qSize--)
        {
            int top = Q.front(); Q.pop();

            for(int i = 0; i < graph[top].size(); i++)
            {
                int v = graph[top][i];
                if(visited[v] == 0)
                {
                    Q.push(v);
                    visited[v] = 1;
                }
            }
        }

        ttl--;
    }

	// Count the unreachable nodes
    for(auto p: mp)
    {
        if(visited[p.second] == 0)
        {
            res++;
        }
    }

    return res;
}



int main()
{
    int nc, u, v, start, ttl, case_no = 1;

    while(scanf("%d", &nc))
    {
        if(nc == 0) break;

        vector<int> graph[MAXN];
        int visited[MAXN] = {0};
        unordered_map<int, int> mp;
        int compressed_number = 0;

        for(int i = 0; i < nc; i++)
        {
            scanf("%d %d", &u, &v);

            if(mp.find(u) == mp.end())
            {
                mp[u] = compressed_number++;
            }

            if(mp.find(v) == mp.end())
            {
                mp[v] = compressed_number++;
            }

            graph[mp[u]].push_back(mp[v]);
            graph[mp[v]].push_back(mp[u]);
        }

        while(scanf("%d %d", &start, &ttl))
        {
            if(start == 0 && ttl == 0)
            {
                break;
            }
            memset(visited, 0, sizeof(visited));

            int ret = 0;

			// If the starting node is not found, then all will be unreachable nodes.
            if(mp.find(start) == mp.end())
            {
                ret = mp.size();
            } else
            {
               ret = findUnreachabledNodes(mp[start], ttl, graph, visited, mp);
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", case_no++, ret, start, ttl);
        }
    }

    return 0;
}
