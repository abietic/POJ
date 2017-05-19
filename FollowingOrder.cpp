//拓扑排序和DFS结合。看了别人的代码才勉强理解DFS原理。
#include <iostream>
#include <vector>
#include <cstring>
//----------------------------------------
using namespace std;
//----------------------------------------
struct node
{
    vector<int> adj;
    bool visited;
    int degree;
    bool exist;
    node()
    {
        visited = false;
        exist = false;
        degree = 0;
    }
};
//----------------------------------------
void dfs(node aovnet[] , int total , int len);
//----------------------------------------
char output[30];
//----------------------------------------
int main()
{
    char str[1000];
    while (cin.getline(str , 1000 , '\n'))
    {
        node aovnet[26];
        char from , to;
        int len = 0;
        for (int i = 0 ; str[i] != '\0' ; i++)
        {
            if (str[i] != ' ')
            {
                aovnet[str[i] - 'a'].exist = true;
                ++len;
            }
        }
        cin.getline(str , 1000 , '\n');
        for (int i = 0 , j = strlen(str) ; i < j ; i += 4)
        {
            from = str[i];
            to = str[i + 2];
            aovnet[from - 'a'].adj.push_back(to - 'a');
            aovnet[to - 'a'].degree++;
        }
        dfs(aovnet , 0 , len);
        cout << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
void dfs(node aovnet[] , int total , int len)
{
    if (total == len)
    {
        output[total] = '\0';
        cout << output << endl;
        return;
    }
    for (int i = 0 ; i < 26 ; i++)
    {
        if (!aovnet[i].exist || aovnet[i].visited || aovnet[i].degree != 0)
        {
            continue;
        }
        aovnet[i].visited = true;
        for (int j = 0 ; j < aovnet[i].adj.size() ; j++)
        {
            aovnet[aovnet[i].adj[j]].degree--;
        }
        output[total] = 'a' + i;
        dfs(aovnet , total + 1 , len);
        for (int j = 0 ; j < aovnet[i].adj.size() ; j++)
        {
            aovnet[aovnet[i].adj[j]].degree++;
        }
        aovnet[i].visited = false;
    }
    return;
}
//----------------------------------------
