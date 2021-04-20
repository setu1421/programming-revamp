int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    int Lmin[n], Rmax[n];
    
    // Find the minimum at each step
    Lmin[0] = A[0];
    for(int i = 1; i < n; i++)
    {
        Lmin[i] = min(Lmin[i - 1], A[i]);
    }
    
    // Find the maximum at each step
    Rmax[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        Rmax[i] = max(Rmax[i + 1], A[i]);
    }
    
    // Calculate the max_diff
    int i = 0, j = 0, max_diff = 0;
    
    while(i < n && j < n)
    {
        if(Lmin[i] <= Rmax[j])
        {
            max_diff = max(max_diff, j - i);
            j++;
        } else 
        {
            i++;
        }
    }
    
    return max_diff;
}


// Another approach:

int maximumGap(const vector<int> &num) {
	if (num.size() == 0) return -1;
	if (num.size() == 1) return 0;
	vector<pair<int, int> > toSort; 
	for (int i = 0; i < num.size(); i++) {
		toSort.push_back(make_pair(num[i], i));
	}
	sort(toSort.begin(), toSort.end());
	int len = toSort.size();
	int maxIndex = toSort[len - 1].second;
	int ans = 0;
	for (int i = len - 2; i >= 0; i--) {
		ans = max(ans, maxIndex - toSort[i].second);
		maxIndex = max(maxIndex, toSort[i].second);
	}
	return ans;
}
