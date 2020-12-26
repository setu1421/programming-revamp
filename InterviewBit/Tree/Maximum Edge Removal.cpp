int dfs(vector<int> graph[], unordered_map<int, int> &visited, int u, int &res)
{
    visited[u] = 1;
    int currentNodeCount = 0;
    //  iterate over all neighbor of node u 
    for(int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        
        if(!visited[v])
        {
			// Count the number of nodes in a subtree 
            int nodeCountofSubtree = dfs(graph, visited, v, res);
            // if returned node count is even, disconnect 
            // the subtree and increase result by one. 
            if(nodeCountofSubtree % 2 == 0)
            {
                res++;
            } //  else add subtree nodes in current component
			else
            {
                currentNodeCount += nodeCountofSubtree;
            }
        }
    }
    // number of nodes in current component and one for current node 
    return currentNodeCount + 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int res = 0;
    unordered_map<int, int> visited;
    vector<int> graph[A];
    
    for(int i = 0; i < B.size(); i++)
    {
        vector<int> nodes = B[i];
        graph[nodes[0] - 1].push_back(nodes[1] - 1);
        graph[nodes[1] - 1].push_back(nodes[0] - 1);
    }
    
    dfs(graph, visited, 0, res);
    
    return res;
}
