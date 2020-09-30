#define M 1000000007

void computerFactorial(long long *fact, int n)
{
    fact[0] = 1; fact[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

void calculateGaps(vector<int> &gap, vector<int> &B, int n, int A)
{
    gap.push_back(B[0] - 1);
    
    for(int i = 1; i <= n - 1; i++)
    {
        gap.push_back(B[i] - B[i - 1] - 1);
    }
    
    gap.push_back(A - B[n - 1]);
}

long long modPow(long long a, long long p)
{
    if(p == 0)
    {
        return 1;
    }
    if(p == 1)
    {
        return a;
    }
    
    long long res = modPow(a, p / 2);
    
    res = (res * res) % M;
    
    if(p & 1)
    {
        res = (a * res) % M;
    }
    
    return res;
}

int Solution::solve(int A, vector<int> &B) {
    int visited_cities = B.size();
    int nonvisited_cities = A - visited_cities;
    long long fact[1001];
    
    vector<int>gap;
    sort(B.begin(), B.end());
    calculateGaps(gap, B, visited_cities, A);
    
    computerFactorial(fact, 1000);
    long long ans = fact[nonvisited_cities];
    
    for(int i = 0; i < gap.size(); i++)
    {
        if(gap[i] > 1)
        {
            ans = (ans * modPow(fact[gap[i]], M - 2)) % M;
            // Always will be one way to computer for first and last gap
            if(i != 0 && i != gap.size() - 1)
            {
                 ans = (ans * modPow(2, gap[i] - 1)) % M;
            }
        }
    }
    
    return ans;
}
