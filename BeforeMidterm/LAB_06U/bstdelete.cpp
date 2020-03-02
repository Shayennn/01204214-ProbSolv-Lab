#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode *left;
    TreeNode *right;
    bool deleted;

    TreeNode(valueType val, TreeNode *left = 0, TreeNode *right = 0, bool deleted = 0)
        : val(val), left(left), right(right), deleted(deleted) {}
};

void insert(TreeNode *&r, valueType x)
{
    if (!r)
    {
        r = new TreeNode(x);
    }
    else if (x == r->val)
    {
        r->deleted = 0;
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
    if (r->val == x && !r->deleted)
        return r;
    if (x < r->val)
        return find(r->left, x);
    if (x > r->val)
        return find(r->right, x);
    return 0;
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

bool removebst(TreeNode *r, valueType x)
{
    TreeNode *target = find(r, x);
    if (target)
        target->deleted = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode *root = 0;

    int M, K, X;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> K;
        cin >> X;
        if (K == 1)
            insert(root, X);
        else if (K == 2)
        {
            if (find(root, X))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
            removebst(root, X);
    }
    // inorder(root);

    return 0;
}
