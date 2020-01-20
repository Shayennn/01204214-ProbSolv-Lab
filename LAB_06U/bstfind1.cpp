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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // bool *inserted = (bool *) calloc(2000001, sizeof(bool));
    TreeNode *root = 0;

    int M, K, X;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> K;
        cin >> X;
        if (K == 1)
        {
            insert(root, X);
            // inserted[X+1000001] = true;
        }
        else
        {
            if (find(root, X))
            // if (inserted[X+1000001])
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}
