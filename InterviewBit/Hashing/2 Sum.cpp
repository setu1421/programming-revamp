vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++)
    {
        if(mp.find(B - A[i]) != mp.end())
        {
            return {mp[B - A[i]] + 1, i + 1};
        } else
        {
            /* unordered_map does not allow key duplicates, 
            so if you are trying to use the .insert() method to insert the same key 
            it will fail and skip that operation. 
            However if you use unorderedMap[key] = value to insert a duplicate key, 
            it will not skip but updating the value matching the key to the new value.
            So, it will handle 2, 2, 1 scenario and output (1, 3) instead of (2, 3) i.e.
            If index2 is same then will take the smallest index1.
            */
            mp.insert(make_pair(A[i], i));
        }
    }
    
    return {};
}
