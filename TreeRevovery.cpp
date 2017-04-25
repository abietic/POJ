/*使用递归。
先根的子树根一定在数组头。
中根则是其子树根左为其左子树元素 ， 其子树右为右子树元素。
当然 ， 是与左右子树的元素个数有关。
做递归时要判断子树长。
做树的题一般会用到树的思想。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
//----------------------------------------
using namespace std;
//----------------------------------------
struct node
{
    char data;
    node *left , *right;
};
//----------------------------------------
node* make_tree(char pre[] , char in[] , int length);
void display_post(node* root);
void delete_tree(node*& ro);
//----------------------------------------
int main()
{
    char pre[100];
    char in[100];
    while (scanf("%s%s" , pre , in) == 2)
    {
        int length = strlen(pre);
        node* root = make_tree(pre , in , length);
        display_post(root);
        delete_tree(root);
        cout << endl;
    }
    return 0;
}
//----------------------------------------
node* make_tree(char pre[] , char in[] , int length)
{
    if (!length)
    {
        return NULL;
    }
    int n = 0;
    while (in[n] != pre[0] && n < length)
    {
        n++;
    }
    node*root = new node;
    root->data = pre[0];
    root->left = make_tree(pre + 1 , in , n);
    root->right = make_tree(pre + n + 1 , in + n + 1 , length - n -1);
    return root;
}
//----------------------------------------
void display_post(node* root)
{
    if (root->left != NULL)
    {
        display_post(root->left);
    }
    if (root->right != NULL)
    {
        display_post(root->right);
    }
    cout << root->data;
}
//----------------------------------------
void delete_tree(node*& ro)
{
    std::queue<node*> first;
    std::stack<node*> last;
    first.push(ro);
    node* temp;
    while (!first.empty())
    {
        temp = first.front();
        first.pop();
        if (temp->left != NULL)
        {
            first.push(temp->left);
        }
        if (temp->right != NULL)
        {
            first.push(temp->right);
        }
        last.push(temp);
    }
    while (!last.empty())
    {
        temp = last.top();
        last.pop();
        delete temp;
    }
}
//----------------------------------------
