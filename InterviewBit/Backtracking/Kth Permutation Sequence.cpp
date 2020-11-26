// https://www.youtube.com/watch?v=W9SIlE2jhBQ

void precomputeFact(vector<long long> &fact, int n, int k)
{
    fact.push_back(0);
    fact.push_back(1);

    for(int i = 2; i <= n; i++)
    {
		/*
		 there’s no problem in returning INT_MAX. Since in the question it’s already given that ‘k’ will be less than INT_MAX. Any factorial greater than 12 will be greater than INT_MAX which will make k/(n-1)! equal to 0. So we can return INT_MAX which will also make k/(n-1)! equal to zero,since ‘k’ is always less than INT_MAX when n>12
		*/
        if(fact[i - 1] > k)
        {
            fact.push_back(INT_MAX);
        } else
        {
            fact.push_back(fact[i - 1] * i);
        }
    }
}

void getPermutationUtil(vector<long long> &fact, string &res, vector<int> &v, int n, int k)
{
    if(n == 1)
    {
        res += to_string(v[0]);
        return;
    }

    int index = (k - 1) / fact[n - 1];
    res += to_string(v[index]);
    v.erase(v.begin() + index);
    k = k - (index * fact[n - 1]);
    getPermutationUtil(fact, res, v, n - 1, k);
}

string Solution::getPermutation(int A, int B) {
    vector<int> v;
    vector<long long> fact;
    string res;

    precomputeFact(fact, A - 1, B);

    for(int i = 1; i <= A; i++)
    {
        v.push_back(i);
    }

    getPermutationUtil(fact, res, v, A, B);

    return res;
}