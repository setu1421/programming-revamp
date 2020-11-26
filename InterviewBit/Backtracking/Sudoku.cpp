// Time complexity: O(9^(n*n))
/*
Many recursive searches can be modeled as a tree. In Sodoku, you have 9 possibilities each time you try out a new field. At maximum, you have to put solutions into all 81 fields. The resulting search space is a tree with a depth of 81 and a branching factor of 9 at each node of each layer, and each leaf is a possible solution. Given these numbers, the search space is 9^81.
*/

struct HashKey
{
    string rowHash;
    string colHash;
    string boxHash;
};

HashKey getHashKeys(int row , int col, int value)
{
    HashKey key;

    key.rowHash = "row-" + to_string(row) + "-" + to_string(value);
    key.colHash = "col-" + to_string(col) + "-" + to_string(value);
    key.boxHash = "box-" + to_string(((row / 3) * 3) + (col / 3)) + "-" + to_string(value);

    return key;
}
void addHash(unordered_map<string, int> &mp, int row , int col, int value)
{
    HashKey key = getHashKeys(row, col, value);

    mp[key.rowHash] = 1;
    mp[key.colHash] = 1;
    mp[key.boxHash] = 1;
}

void removeHash(unordered_map<string, int> &mp, int row , int col, int value)
{
    HashKey key = getHashKeys(row, col, value);

    mp.erase(key.rowHash);
    mp.erase(key.colHash);
    mp.erase(key.boxHash);
}

void preComputeHash(vector<vector<char> > &A, unordered_map<string, int> &mp)
{
    for(int row = 0; row < A.size(); row++)
    {
        for(int col = 0; col < A[0].size(); col++)
        {
            char value = A[row][col];
            if(value != '.')
            {
                addHash(mp, row, col, value - '0');
            }
        }
    }
}

bool checkIfValid(unordered_map<string, int> &mp, int row , int col, int value)
{
    HashKey key = getHashKeys(row, col, value);

    if(mp.find(key.rowHash) != mp.end() || mp.find(key.colHash) != mp.end() || mp.find(key.boxHash) != mp.end())
    {
        return false;
    }

    return true;
}

bool sudokuUtil(vector<vector<char> > &A, unordered_map<string, int> &mp, int row, int col)
{
    if(row == A.size())
    {
        return true;
    }

    if(col == A[0].size())
    {
        return sudokuUtil(A, mp, row + 1, 0);
    }

    if(A[row][col] != '.')
    {
         return sudokuUtil(A, mp, row, col + 1);
    }

    for(int value = 1; value <= 9; value++)
    {
        bool isValid = checkIfValid(mp, row , col, value);

        if(isValid)
        {
            A[row][col] = value + '0';
            addHash(mp, row , col, value);
            bool success = sudokuUtil(A, mp, row, col + 1);

            if(success)
            {
                return true;
            }

            A[row][col] = '.';
            removeHash(mp, row , col, value);
        }
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    unordered_map<string, int>mp;

    preComputeHash(A, mp);

    sudokuUtil(A, mp, 0, 0);
}