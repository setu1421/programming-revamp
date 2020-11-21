vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    //mapping sum value to a vector of pair indices
    unordered_map<int, vector<pair<int,int> > > mp;
    vector<vector<int> > ans;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //calculate sum with i and j indices
            int sum = A[i] + A[j];
            //if B- sum is already present in Hash then check for valid indices
            if(mp.find(B - sum) != mp.end())
            {
                //get vector of pair of indices with Hash of B- Sum
                vector<pair<int, int> > vec = mp[B - sum];
                 //check for all pairs with i anf j
                for(auto value: vec)
                {
                     //we are checking that all the indices are different
                    if(value.first != i && value.first != j && 
                         value.second != i && value.second != j)
                    {
                        vector<int> quadruplet;
                        quadruplet.push_back(A[i]);
                        quadruplet.push_back(A[j]);
                        quadruplet.push_back(A[value.first]);
                        quadruplet.push_back(A[value.second]);
                        //sort the vector ans to maintain the expected output
                        sort(quadruplet.begin(), quadruplet.end());
                        //push to final result and avoids duplicates
                        if(find(ans.begin(), ans.end(), quadruplet) == ans.end())
                        {
                            ans.push_back(quadruplet);
                        }
                    }
                }
            }
            //Hash the indices i and j with sum of i and j
            mp[sum].push_back(make_pair(i, j));
        }
    }
    //finally sort the result vector to maintain expected output
    sort(ans.begin(), ans.end());
    
    return ans;
}
