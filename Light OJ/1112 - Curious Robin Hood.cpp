#include <bits/stdc++.h>
using namespace std;

// using cin, cout will give TLE
// http://www.shafaetsplanet.com/?p=1557

void constructSegmentTree(int *arr, int *tree, int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int mid = (b + e) / 2;

    constructSegmentTree(arr, tree, left, b, mid);
    constructSegmentTree(arr, tree, right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int *tree, int node, int b, int e, int i, int j)
{
    if(b > j || e < i) return 0;
    if(i <= b && e <= j)
    {
        return tree[node];
    }

    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int mid = (b + e) / 2;

    int p1 = query(tree, left, b, mid, i, j);
    int p2 = query(tree, right, mid + 1, e, i, j);

    return (p1 + p2);
}

void updateSegmentTree(int *tree, int node, int b, int e, int i, int new_value)
{
    if(b > i || e < i) return;
    if(i <= b && e <= i)
    {
        tree[node] = new_value;
        return;
    }

    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int mid = (b + e) / 2;

    updateSegmentTree(tree, left, b, mid, i, new_value);
    updateSegmentTree(tree, right, mid + 1, e, i, new_value);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, n, q, cases = 1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);

        int arr[n + 1];
        int tree[4 * n];

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }

        constructSegmentTree(arr, tree, 0, 0, n - 1);

        int qtype, i, v, j;
        printf("Case %d:\n",cases++);
        while(q--)
        {
             scanf("%d %d",&qtype,&i);

            if(qtype == 1)
            {
                printf("%d\n",arr[i]);
                arr[i] = 0;
                updateSegmentTree(tree, 0, 0, n - 1, i, arr[i]);
            } else if(qtype == 2)
            {
                scanf("%d",&v);
                arr[i] = arr[i] + v;
                updateSegmentTree(tree, 0, 0, n - 1, i, arr[i]);
            } else
            {
                scanf("%d",&j);
                printf("%d\n",query(tree, 0, 0, n - 1, i, j));
            }
        }
    }
}
