struct node
{
    bool endMarked;
    node* next[26 + 1];

    node()
    {
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        endMarked = false;
    }
} *root;

bool customcmp(const pair<int, int> a, const pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

void buildTrie(string word)
{
    int n = word.length();
    node* curr = root;

    for(int i = 0; i < n; i++)
    {
        int id = word[i] - 'a';

        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }

        curr = curr->next[id];
    }

    curr->endMarked = true;
}

bool searchTrie(string word)
{
    int n = word.length();
    node* curr = root;

    for(int i = 0; i < n; i++)
    {
        int id = word[i] - 'a';

        if(curr->next[id] == NULL)
        {
            return false;
        }

        curr = curr->next[id];
    }

    return curr->endMarked;
}

void delTrie(node* curr)
{
    for(int i = 0; i < 26; i++)
    {
        if(curr->next[i] != NULL)
        {
            delTrie(curr->next[i]);
        }
    }

    delete(curr);
}

vector<int> Solution:: solve(string A, vector<string> &B)
{
    root = new node();
    stringstream ss(A);
    string word;

    while(getline(ss, word, '_'))
    {
        buildTrie(word);
    }

    vector<pair<int, int> > ans;

    for(int i = 0; i < B.size(); i++)
    {
        string review = B[i];
        stringstream ss(review);
        string review_word;
        int counter = 0;
        while(getline(ss, review_word, '_'))
        {
            counter += searchTrie(review_word);
        }

        ans.push_back(make_pair(counter, i));
    }

    sort(ans.begin(), ans.end(), customcmp);

    delTrie(root);

    vector<int> res;
    for(auto p: ans)
    {
        res.push_back(p.second);
    }

    return res;
}