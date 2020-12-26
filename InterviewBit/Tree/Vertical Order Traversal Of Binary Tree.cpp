// https://www.youtube.com/watch?v=kqHNP6NTzME
// BFS approach: https://gist.github.com/SuryaPratapK/d73b9a97c2c8a2af762af106b794ad2d

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void solve(map<int, map<int, vector<int> > > &mp, TreeNode* root, int col, int row)
{
    if(root == NULL)
    {
        return;
    }
    
    mp[col][row].push_back(root->val);
    solve(mp, root->left, col - 1, row + 1);
    solve(mp, root->right, col + 1, row + 1);
}
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > res;
    map<int, map<int, vector<int> > > mp;
    solve(mp, A, 0, 0);
    
    for(auto m1: mp)
    {
        vector<int> v;
        for(auto m2: m1.second)
        {
            for(int val: m2.second)
            {
                v.push_back(val);
            }
        }
        
        res.push_back(v);
    }
    
    return res;
}

//BFS-Method
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode *curr;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        vector<vector<int>> ans;
        map<int,vector<int>> mymap;
        
        //BFS
        while(!q.empty())
        {
            int size = q.size();            
            map<int,set<int>> mapset;
            
            while(size--)
            {
                curr = q.front().first;
                int col = q.front().second;
                q.pop();
                mapset[col].insert(curr->val);
                
                if(curr->left)
                    q.push({curr->left,col-1});
                if(curr->right)
                    q.push({curr->right,col+1});
            }
            for(auto it: mapset)
                for(auto it2: it.second)
                    mymap[it.first].push_back(it2);
        }
        //Now pass all values from mymap to ans array
        for(auto it: mymap)
            ans.push_back(it.second);
        
        return ans;
    }
};