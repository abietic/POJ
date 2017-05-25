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
        node aovnet[26];//通过直接字母序存储节点省去了排序。很巧妙。
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
        for (int i = 0 , j = strlen(str) ; i < j ; i += 4)//读取关系的方式很巧妙，完全避免了题目模棱两可的输入标准带来的错误。之前疯狂RE
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
        output[total] = '\0';//这里len是个数，而total则是数组下一个录入的位置。原来写total+1疯狂WA
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
        //进行回溯，这里是DFS的关键。
        for (int j = 0 ; j < aovnet[i].adj.size() ; j++)
        {
            aovnet[aovnet[i].adj[j]].degree++;
        }
        aovnet[i].visited = false;
    }
    return;
}
//----------------------------------------
