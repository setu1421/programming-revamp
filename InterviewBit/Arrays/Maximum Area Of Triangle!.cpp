/*
We know area of a triangle = 1/2 * base *height, so we need to maximize the base and height of the triangle. Since one side is parallel to the y-axis, we can consider that side as the base of the triangle.

To maximize base, we can find the first and last occurrence of {r, g, b} for each column. So we have two sets of 3 values for each column. For base in any column, one vertex is from the first set and the second vertex from the second set such that they have different values.

To maximize height, for any column as a base, the third vertex must be chosen such that the vertex should be farthest from the column, on the left or right side of the column having a value different from the other two vertices.
Now for each column find the maximum area of the triangle.

Time Complexity: O(NM)
*/
#define maxN 1002
#define maxM 1002

int Left[3]; //contains the first occurrence of the values in the row
int Right[3]; //contains the last occurrence of the values in the row
int Top[3][maxM]; //contains the first occurrence of the values in the column
int Bottom[3][maxM]; //contains the last occurrence of the values in the column

//mapping for easy access
int mapping(char c)
{
    if(c == 'r')
    {
        return 0;
    } else if(c == 'g')
    {
        return 1;
    } else 
    {
        return 2;
    }
}

void Precompute(vector<string> &A, int n, int m)
{
    fill_n(Left, sizeof(Left), maxM);
    fill_n(Right, sizeof(Right), -1);
    fill_n(&Top[0][0], 3 * maxM, maxN);
    fill_n(&Bottom[0][0], 3 * maxM, -1);
    
	//to find out global left and right color values
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Left[mapping(A[i][j])] = min(Left[mapping(A[i][j])], j);
            Right[mapping(A[i][j])] = max(Right[mapping(A[i][j])], j);
        }
    }
    //to find out top and bottom values for each column
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            Top[mapping(A[i][j])][j] = min(Top[mapping(A[i][j])][j], i);
            Bottom[mapping(A[i][j])][j] = max(Bottom[mapping(A[i][j])][j], i);
        }
    }
}

int Solution::solve(vector<string> &A) {
    
    int n = A.size(), m = A[0].size();
    Precompute(A, n, m);
    double ans = (double) 0;
    //setting the column
    for(int j = 0; j < m; j++)
    {
        for(int s1 = 0; s1 < 3; s1++)
        {
            for(int s2 = 0; s2 < 3; s2++)
            {
                int s3 = 3 - s1 - s2;
                
                if(s1 != s2 && Top[s1][j] != maxN && Bottom[s2][j] != -1 && Right[s3] != -1)
                {
                    ans = max(ans, ((double)1 / (double)2) * (Bottom[s2][j] - Top[s1][j]) * (Right[s3] - j));
                }
                
                if(s1 != s2 && Top[s1][j] != maxN && Bottom[s2][j] != -1 && Left[s3] != maxM)
                {
                    ans = max(ans, ((double)1 / (double)2) * (Bottom[s2][j] - Top[s1][j]) * (j - Left[s3]));
                }
            }
        }
    }

    
    return (int)(ceil(ans));
}
