#define MOD 10003

bool isVowel(char c)
{
    if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u')
    {
        return true;
    } else
    {
        return false;
    }
}

int Solution::solve(string A) {
    int n = strlen(A.c_str());
    long long total_count = 0ll;
    
    for(int i = 0; i < n; i++)
    {
        if(isVowel(tolower(A[i])))
        {
            int temp = (n - i);
            total_count = (total_count + temp) % MOD;
        }
    }
    
    return total_count;
}
