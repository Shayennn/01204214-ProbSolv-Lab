#include <iostream>
// #include <stdlib.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(valueType val, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), left(left), right(right) {}
};

void insert(TreeNode *&r, valueType x)
{
    if (!r)
    {
        r = new TreeNode(x);
    }
    else if (x < r->val)
    {
        insert(r->left, x);
    }
    else if (x > r->val)
    {
        insert(r->right, x);
    }
}
TreeNode *find(TreeNode *r, valueType x)
{
    if (r == 0)
        return 0;
    if (r->val == x)
        return r;
    if (x < r->val)
        return find(r->left, x);
    if (x > r->val)
        return find(r->right, x);
}

void inorder(TreeNode *r)
{
    if (!r)
    {
        return;
    }
    inorder(r->left);
    cout << r->val << endl;
    inorder(r->right);
}

void postorder(TreeNode *r)
{
    if (!r)
    {
        return;
    }
    postorder(r->right);
    cout << r->val << endl;
    postorder(r->left);
}

void postorder_tree(TreeNode *r, int level)
{
    if (!r)
    {
        return;
    }
    postorder_tree(r->right, level+1);
    for(int i = 0; i<level; i++){
        cout << "...";
    }
    cout << "* " << r->val << endl;
    postorder_tree(r->left, level+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode *root = 0;

    int N, X;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X;
        insert(root, X);
    }
    postorder_tree(root, 0);

    return 0;
}
