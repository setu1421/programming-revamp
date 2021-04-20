void swap_array(vector<int> &A, int start, int end)
{
    int n = (end - start) + 1;
    for(int i = 0; i < n/2; i++)
    {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> result;
    int start = 0, end = 0;

    for(int i = 0; i < B; i++)
    {
        result.push_back(i + 1);
    }

    for(int i = 0; i < B - 1; i++)
    {
        if(A[i] == 'D')
        {
            start = i;
            end = i;

            while((i < B - 1) && A[i] == 'D')
            {
                end = i;
                i++;
            }

            swap_array(result, start, end + 1);
        }
    }

    return result;
}

// Another Solution:

vector Solution::findPerm(const string A, int B) {

vector<int> result;

int current_smallest = 1;
int current_largest = B;

for(int i = 0; i < A.size(); i++){
    if(A[i] == 'I'){
        result.push_back(current_smallest);
        current_smallest++;
    }else{
        result.push_back(current_largest);
        current_largest--;
    }
}
 if(A[ A.size() - 1] == 'I'){
        result.push_back(current_smallest);
    }else{
        result.push_back(current_largest);
    }
return result;
}
