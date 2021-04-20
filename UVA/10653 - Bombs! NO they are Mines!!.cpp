#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int cell[1005][1005], vis[1005][1005], dis[1005][1005];
int row, col;


int bfs(int start_row, int start_col, int dest_row, int dest_col)
{
    queue<pii> Q;
    Q.push(pii(start_row, start_col));
    vis[start_row][start_col] = 1;
    dis[start_row][start_col] = 0;

    while(!Q.empty())
    {
        pii top = Q.front(); Q.pop();

        for(int k = 0; k < 4; k++)
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if(tx == dest_row && ty == dest_col)
            {
                return dis[top.first][top.second] + 1;
            }

            if(tx >= 0 && tx < row && ty >= 0 && ty < col && vis[tx][ty] == 0 && cell[tx][ty] != 1)
            {
                Q.push(pii(tx, ty));
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[top.first][top.second] + 1;
            }
        }
    }

    return 0;
}

int main()
{
    int bomb_row, bomb_col, total_bombs_row, bombs_count, start_row, start_col, dest_row, dest_col;

    while(scanf("%d %d", &row, &col))
    {
        if(row == 0 && col == 0)
        {
            break;
        }

        memset(vis, 0, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        memset(cell, 0, sizeof(cell));

        scanf("%d", &total_bombs_row);

        for(int i = 0; i < total_bombs_row; i++)
        {
            scanf("%d %d", &bomb_row, &bombs_count);
            while(bombs_count--)
            {
                scanf("%d", &bomb_col);
                cell[bomb_row][bomb_col] = 1;
            }
        }

        scanf("%d %d", &start_row, &start_col);
        scanf("%d %d", &dest_row, &dest_col);

        int ret = bfs(start_row, start_col, dest_row, dest_col);
        printf("%d\n", ret);
    }


    return 0;
}
