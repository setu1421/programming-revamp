// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
/*
	Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations.
	Auxiliary Space : O(1)
*/
int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    
	// Find the desired count of numbers
	// The median is (1+N*M)/2 th smallest element out of the given elements.
    int desired = ((r * c) + 1) / 2;
    
    int min_elem = INT_MAX, max_elem = INT_MIN;
    
    for(int i = 0; i < r; i++)
    {
        min_elem = min(min_elem, A[i][0]);
        max_elem = max(max_elem, A[i][c - 1]);
    }
    
    while(min_elem < max_elem)
    {
        int mid = min_elem + (max_elem - min_elem) / 2;
        int count = 0;
        
        // Count the number of elements less than or equal to mid
        for(int i = 0; i < r; i++)
        {
            count += upper_bound(&A[i][0], &A[i][c], mid) - &A[i][0];
        }
        
        if(count < desired)
        {
            min_elem = mid + 1;
        } else
        {
            // We are not doing mid - 1 because mid can also be a candidate for median
            max_elem = mid;
        }
    }
    
    return min_elem;
}

// Matrix Median of matrix sorted with both in the rows and cols
// https://ayoubomari.medium.com/kth-smallest-element-in-sorted-matrix-b20400cf878e

#include<bits/stdc++.h>
using namespace std;

class Point
{
    int value, row, col;

public:
    Point(int _value, int _row, int _col)
    {
        value = _value;
        row = _row;
        col = _col;
    }

    int getValue(){return value;}
    int getRow(){return row;}
    int getCol(){return col;}
} ;

class myComparator
{
public:
    int operator() (Point& p1, Point& p2)
    {
        return p1.getValue() > p2.getValue();
    }
};

int findMedian(vector<vector<int> > A)
{
    int row = A.size(), col = A[0].size();
    int desired = ((row * col) + 1) / 2;

    priority_queue<Point, vector<Point>, myComparator> pq;
    set<pair<int, int> > s;

    pq.push(Point(A[0][0], 0, 0));
    s.insert(make_pair(0, 0));

    while(desired > 1)
    {
        Point top = pq.top();
        pq.pop();

        int t_r = top.getRow(), t_c = top.getCol();

        if(t_c + 1 < col && s.find(make_pair(t_r, t_c + 1)) == s.end())
        {
            pq.push(Point(A[t_r][t_c + 1], t_r, t_c + 1));
            s.insert(make_pair(t_r, t_c + 1));
        }
        if(t_r + 1 < row && s.find(make_pair(t_r + 1, t_c)) == s.end())
        {
            pq.push(Point(A[t_r + 1][t_c], t_r + 1, t_c));
            s.insert(make_pair(t_r + 1, t_c));
        }

        desired--;
    }

    Point res = pq.top();
    return res.getValue();
}

int main()
{
    vector<vector<int> > v = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout<<findMedian(v)<<endl;
}


