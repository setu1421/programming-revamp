#include <bits/stdc++.h>
using namespace std;
 
struct info
{
    long long sum = 0ll, prop = 0ll;
};
 
void updateSegmentTree(info *tree, long long node, long long b, long long e, long long i, long long j, long long x)
{
    // no overlap
    if(b > j || e < i) return;
    // total overlap
    if(i <= b && e <= j)
    {
        tree[node].sum += (e - b + 1) * x;
        tree[node].prop += x;
        return;
    }
 
    long long left = 2 * node + 1;
    long long right = 2 * node + 2;
    long long mid = (b + e) / 2;
 
    updateSegmentTree(tree, left, b, mid, i, j, x);
    updateSegmentTree(tree, right, mid + 1, e, i, j, x);
 
    tree[node].sum = tree[left].sum + tree[right].sum + ((e - b + 1) * tree[node].prop);
}
 
long long query(info *tree, long long node, long long b, long long e, long long i, long long j, long long carry)
{
    if(b > j || e < i) return 0;
 
    if(i <= b && e <= j)
    {
        return tree[node].sum + carry * (e - b + 1);
    }
 
    long long left = 2 * node + 1;
    long long right = 2 * node + 2;
    long long mid = (b + e) / 2;
 
    long long p1 = query(tree, left, b, mid, i, j, carry + tree[node].prop);
    long long p2 = query(tree, right, mid + 1, e, i, j, carry + tree[node].prop);
 
    return (p1 + p2);
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int t, n, c, p, q, qtype, v;
 
    cin>>t;
 
    while(t--)
    {
        cin>>n>>c;
        long long arr[n + 1] = {0};
        struct info tree[4*n];
 
        while(c--)
        {
            cin>>qtype>>p>>q;
 
            if(qtype == 0)
            {
                cin>>v;
                updateSegmentTree(tree, 0, 0, n - 1, p - 1, q - 1, v);
            } else
            {
                cout<<query(tree, 0, 0, n - 1, p - 1, q - 1, 0)<<endl;
            }
        }
    }
}