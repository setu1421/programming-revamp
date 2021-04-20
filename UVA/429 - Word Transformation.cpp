#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dic, vis, dis;

int bfs(string src, string dest)
{
    queue<string> Q;
    Q.push(src);
    vis[src] = 1;
    dis[src] = 0;

    while(!Q.empty())
    {
        string top = Q.front(); Q.pop();

        if(top == dest)
        {
            return dis[top];
        }

        for(int i = 0; i < top.length(); i++)
        {
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                string new_word = top;
                new_word[i] = ch;

                if(dic.find(new_word) != dic.end() && vis[new_word] != 1)
                {
                    Q.push(new_word);
                    vis[new_word] = 1;
                    dis[new_word] = dis[top] + 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int test_case;
    string src, dest, word, line;

    cin>>test_case;

    for(int i = 0; i < test_case; i++)
    {
        if(i != 0)
        {
            cout<<endl;
        }

        while(cin>>word && word != "*")
        {
            dic[word] = 1;
        }

        cin.ignore();

        while(getline(cin, line) && line != "")
        {
            stringstream ss(line);
            ss >> src >> dest;
            vis.clear();
            dis.clear();
            cout<< src << " " << dest << " " << bfs(src, dest)<<endl;
        }

        dic.clear();
    }

    return 0;
}
