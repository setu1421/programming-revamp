#include<bits/stdc++.h>
using namespace std;

#define MAXN 21

vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int start, int dest)
{
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while(!Q.empty())
    {
        int top = Q.front();
        Q.pop();

        if(top == dest)
        {
            printf("%2d to %2d: %d\n", start, dest, dist[top]);
            break;
        }

        for(int i = 0; i < graph[top].size(); i++)
        {
            int v = graph[top][i];
            if(dist[v] == -1)
            {
                dist[v] = dist[top] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, val, queries, cases = 1, start, dest;
    while(1)
    {
        for(int i = 1; i < 20; i++)
        {
            if(scanf("%d", &n) == EOF)
                return 0;

            for(int j = 0; j < n; j++)
            {
                scanf("%d", &val);
                graph[i].push_back(val);
                graph[val].push_back(i);
            }
        }

        scanf("%d", &queries);
        printf("Test Set #%d\n", cases++);

        for(int k = 0; k < queries; k++)
        {
            memset(dist, -1, sizeof(dist));
            scanf("%d %d", &start, &dest);
            bfs(start, dest);
        }

        for(int i = 0; i < MAXN; i++)
        {
            graph[i].clear();
        }

        printf("\n");
    }


    return 0;
}
