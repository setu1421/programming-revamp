#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool isEndMarked, nextPresent;
    node* next[11];

    node()
    {
        for(int i = 0; i < 11; i++)
        {
            next[i] = NULL;
        }

        isEndMarked = false;
        nextPresent = false;
    }
} *root;

bool insertInTrie(string phone_number)
{
    int n = phone_number.length();
    node* curr = root;

    for(int i = 0; i < n; i++)
    {
        int id = phone_number[i] - '0';

        // if current node is already last node of a number, then not consistent
        if(curr->isEndMarked)
        {
            return false;
        }

        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
            curr->nextPresent = true;
        }

        curr = curr->next[id];
    }

    // If there is other nodes present from the current node, then not consistent
    if(curr->nextPresent)
    {
        return false;
    }

    curr->isEndMarked = true;

    return true;
}

void del(node* root)
{
    for(int i = 0; i < 11; i++)
    {
        if(root->next[i] != NULL)
        {
            del(root->next[i]);
        }
    }

    delete(root);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, n;
    cin>>t;

    while(t--)
    {
        root = new node();

        cin>>n;
        string phone_number;
        bool isValid = true;

        while(n--)
        {
            cin>>phone_number;
            if(isValid)
            {
                isValid = insertInTrie(phone_number);
            }
        }

        if(isValid)
        {
            cout<<"YES"<<endl;
        } else
        {
            cout<<"NO"<<endl;
        }

        del(root);
    }
}
