/*
Method T.C-(NLOGN)

Lets take an example
sort the array such that you get no in decreasing order(you will know the advantage)

sort-NLOGN
A-3 2 1(represent using i)
B-6 5 4(represent using j)

create a heap<pair<int,pair<int,int>>

we will store sum and pair of(i,j)

insert-NLOGN
add in this way to take advantage of heap
sum i j
9 0 0
8 0 1
7 0 2

find N max sum-NLOGN
now find the largest no using max heap we made,remove it and increase the i(keeping j same) and push it in q
(we have to do this process N times)
eg-
remove 9(A[0]+A[0]),then insert
8 1 0(i+1,j)
remove 8(A[1]+A[0]),then insert
7 2 0(i+1,j)
remove 8(A[0]+A[1]),then insert
7 1 1(i+1,j)

stop as we found N max numbers
see the beauty of the method
this solution does all the process in NLOGN
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> res;
    priority_queue<pair<int, pair<int, int> > > pq;
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    for(int i = 0; i < B.size(); i++)
    {
        pq.push(make_pair(A[0] + B[i], make_pair(0, i)));
    }
    
    int n = A.size();
    
    while(res.size() < n)
    {
        pair<int, pair<int, int> > top = pq.top();
        pq.pop();
        
        int value = top.first;
        auto index = top.second;
        int i = index.first, j = index.second;
        
        res.push_back(value);
        pq.push(make_pair(A[i + 1] + B[j], make_pair(i + 1, j)));
    }
    
    return res;
}
