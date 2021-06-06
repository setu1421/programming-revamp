vector<int> Solution::solve(vector<int> &A) {

    unordered_map<int, set<int>> mp;
    for (int i = 0; i < A.size(); i++) {
        if (mp.find(A[i]) == mp.end()) {
            mp[A[i]].insert(i);
        } // if the same element present before, then increment the value at that index.
		// for example: 1 2 3 2 3 3 -> 1 4 4 2 3 3 (set of index is used to erase the first occurrence)
        else {
            auto it = mp[A[i]].begin();
            int idx = *it;

            mp[A[i]].erase(it);
            mp[A[i]].insert(i);
            
            A[idx] = A[i] + 1;
			mp[A[i] + 1].insert(idx);

        }

    }

    return A;

}