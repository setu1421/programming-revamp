#define maxN 1002
#define maxM 1002

int Left[3], Right[3], Top[3][maxM], Bottom[3][maxM];

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
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Left[mapping(A[i][j])] = min(Left[mapping(A[i][j])], j);
            Right[mapping(A[i][j])] = max(Right[mapping(A[i][j])], j);
        }
    }
    
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
                    ans = max(ans, ((double)1 / (double)2) * (Bottom[s2][j] - Top[s1][j] + 1) * (j - Left[s3] + 1));
                }
            }
        }
    }

    
    return (int)(ceil(ans));
}
