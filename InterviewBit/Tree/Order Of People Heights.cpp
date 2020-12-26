// Time Complexity: O(nlogn)
// https://www.youtube.com/watch?v=q4_ck62hCYA&t=897s

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second > b.second;
    }
    
    return a.first < b.first;
}

void buildSegmentTree(vector<int> &segtree, int node, int b, int e)
{
    if(b == e)
    {
        segtree[node] = 1;
        return;
    }
    
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int mid = (b + e) / 2;
    
    buildSegmentTree(segtree, left_node, b, mid);
    buildSegmentTree(segtree, right_node, mid + 1, e);
    
    segtree[node] = segtree[left_node] + segtree[right_node];
}

void updateSegmentTree(vector<int> &res, vector<int> &segtree, int node, int b, int e, int pos, int height)
{
    if(b == e)
    {
        res[b] = height;
        segtree[node] = 0;
        return;
    }
    
    int left_node = 2 * node + 1, left_weight = segtree[left_node];
    int right_node = 2 * node + 2, right_weight = segtree[right_node];
    int mid = (b + e) / 2;
    
    if(pos <= left_weight)
    {
        updateSegmentTree(res, segtree, left_node, b, mid, pos, height);
    } else
    {
        updateSegmentTree(res, segtree, right_node, mid + 1, e, pos - left_weight, height);
    }
    
    segtree[node] = segtree[left_node] + segtree[right_node];
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int, int> > height_pair;
    vector<int> res(n);
    vector<int> segtree(4 * n);
    
    for(int i = 0; i < n; i++)
    {
        height_pair.push_back(make_pair(A[i], B[i]));
    }
    
    sort(height_pair.begin(), height_pair.end(), cmp);
    
    buildSegmentTree(segtree, 0, 0, n - 1);
    
    for(auto h: height_pair)
    {
        updateSegmentTree(res, segtree, 0, 0, n - 1, h.second + 1, h.first);
    }
    
    return res;
}


// Another approach: Without using segment tree
// Time Complexity: O(nlogn + n^2)
// https://www.youtube.com/watch?v=khddrw6Bfyw&t=529s

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int, int> > height_pair;
    vector<int> res(n, -1);
    
    for(int i = 0; i < n; i++)
    {
        height_pair.push_back(make_pair(A[i], B[i]));
    }
    
    sort(height_pair.begin(), height_pair.end());
    
    for(int i = 0; i < n; i++)
    {
        int count = height_pair[i].second;
        
        for(int j = 0; j < n; j++)
        {
            if(res[j] == -1 && count == 0)
            {
                res[j] = height_pair[i].first;
                break;
            } else if(res[j] == -1 || res[j] > height_pair[i].first)
            {
                count--;
            }
        }
    }
    
    return res;
}

