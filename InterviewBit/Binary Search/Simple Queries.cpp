// https://www.algostreak.com/post/simple-queries-interviewbit-solution
// 
#define ll long long
#define MAX 100010
#define MOD 1000000007

ll prod[MAX]; // To store product of divisor.

void precomputeDivisorsProduct()
{
    // function has already been called before.
    if(prod[1] != 0)
    {
        return;
    }

    for(int i = 1; i < MAX; i++)
    {
        prod[i] = (ll) i;
    }

    for(int i = 2; i < MAX; i++)
    {
        for(int j = 2 * i; j < MAX; j += i)
        {
            prod[j] = (prod[j] * i) % MOD;
        }
    }
}

// https://www.youtube.com/watch?v=sDKpIO2HGq0
// https://www.techiedelight.com/next-greater-element/
void computeFrequency(vector<ll> &freq, vector<int> &A, int n)
{
    // Find next equal to or greater element of the current element to find the right side count
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && A[st.top()] <= A[i])
        {
            freq[st.top()] = (ll) (i - st.top());
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty())
    {
        freq[st.top()] = (ll) (n - st.top());
        st.pop();
    }

    // Find next greater element of the current element to find the left side count
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && A[st.top()] < A[i])
        {
            freq[st.top()] *= (ll) (st.top() - i);
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty())
    {
        freq[st.top()] *= (ll) (st.top() + 1);
        st.pop();
    }
}

bool mycompare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.first > p2.first;
}

vector<int> Solution::solve(vector<int> &a, vector<int> &b)
{

    precomputeDivisorsProduct(); // To store product of divisors of each element.

    int n = a.size();

    // Step 1
    vector<ll> freq(n);
    computeFrequency(freq, a, n);

    // Step 2
    vector<pair<ll, ll> > store(n);
    for(int i = 0; i < n; i++)
    {
        store[i] = make_pair(prod[a[i]], freq[i]);
    }

    // Step 3
    sort(store.begin(), store.end(), mycompare);

    // Step 4
    for(int i = 1; i < n; i++)
    {
        store[i].second = store[i].second + store[i - 1].second;
    }

    // step 5
    vector<int> ans(b.size());
    for(int i = 0; i < b.size(); i++)
    { 
        if(store[0].second >= b[i])
        {
            ans[i] = store[0].first;
            continue;
        }
		
		int l = 1, r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(store[mid].second >= b[i] && store[mid-1].second < b[i])
            {
                ans[i] = store[mid].first;
                break;
            }
            else if(store[mid].second < b[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return ans;
}
