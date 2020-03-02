// #include <iostream>
#include <stdio.h>
// #include <stdlib.h>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode *left;
    TreeNode *right;
    int l_child;
    int r_child;

    TreeNode(valueType val, TreeNode *left = 0, TreeNode *right = 0, int l_child = 0, int r_child = 0)
        : val(val), left(left), right(right), l_child(l_child), r_child(r_child) {}
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
        ++(r->l_child);
    }
    else if (x > r->val)
    {
        insert(r->right, x);
        ++(r->r_child);
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
TreeNode *find_gt(TreeNode *r, valueType x)
{
    if (r == 0)
        return 0;
    if (r->val > x)
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
    printf("%d\n", r->val);
    // cout << r->val << endl;
    inorder(r->right);
}

void postorder(TreeNode *r)
{
    if (!r)
    {
        return;
    }
    postorder(r->right);
    printf("%d\n", r->val);
    postorder(r->left);
}

void postorder_tree(TreeNode *r, int level)
{
    if (!r)
    {
        return;
    }
    postorder_tree(r->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("...");
        // cout << "...";
    }
    printf("* %d\n", r->val);
    postorder_tree(r->left, level + 1);
}

int getCount(TreeNode *root, valueType x)
{
    // Base case
    if (!root)
        return 0;
    if (root->val == x){
        return root->r_child;
    } else if (root->val < x){
        return getCount(root->right, x);
    } else {
        return 1+getCount(root->left, x)+root->r_child;
    }
}


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    TreeNode *root = 0;

    int M, K, X;
    // cin >> M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &K, &X);
        // cin >> K;
        // cin >> X;
        if (K == 1)
        {
            insert(root, X);
        }
        else
        {
            printf("%d\n", getCount(root, X));
            // cout << counter;
            // cout << "\n";
        }
    }
    // postorder_tree(root, 0);

    return 0;
}
