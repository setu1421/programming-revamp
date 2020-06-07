#include <bits/stdc++.h>

using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/save-patients/editorial/
// Space Complexity: O(constant * N)
void sortArray(vector<int> &vaccine, vector<int> &patient, int n)
{
    int temp;
    for(int step = 0; step < n - 1; step++)
    {
        for(int i = 0; i < n - step - 1; i++)
        {
            if(vaccine[i] > vaccine[i+1])
            {
                temp = vaccine[i];
                vaccine[i] = vaccine[i+1];
                vaccine[i+1] = temp;
            }

            if(patient[i] > patient[i+1])
            {
                temp = patient[i];
                patient[i] = patient[i+1];
                patient[i+1] = temp;
            }
        }
    }
}

void canSaveAllPatient(vector<int> &vaccine, vector<int> &patient, int n)
{
    bool canSave = true;
    for(int i = 0; i < n; i++)
    {
        if(vaccine[i] <= patient[i])
        {
            canSave = false;
            break;
        }
    }

    if(canSave)
    {
        cout<<"Yes"<<endl;
    }else
    {
        cout<<"No"<<endl;
    }
}

int main()
{
    // decrease the time of cin,, cout
    ios::sync_with_stdio(false);cin.tie(0);

    int n, value;
    cin>>n;
    vector<int>vaccine(n);
    vector<int>patient(n);

    for(int i = 0; i < n; i++)
    {
        cin>>vaccine[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin>>patient[i];
    }

    sortArray(vaccine, patient, n);

    canSaveAllPatient(vaccine, patient, n);


}
