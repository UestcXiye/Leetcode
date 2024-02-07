/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    // x 的信息
    int x;
    TreeNode *x_parent;
    int x_depth;
    bool x_found = false;
    // y 的信息
    int y;
    TreeNode *y_parent;
    int y_depth;
    bool y_found = false;

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, int depth, TreeNode *parent)
    {
        if (root == nullptr)
            return;
        if (root->val == x)
        {
            x_parent = parent;
            x_depth = depth;
            x_found = true;
        }
        else if (root->val == y)
        {
            y_parent = parent;
            y_depth = depth;
            y_found = true;
        }
        if (x_found && y_found)
            return;
        dfs(root->left, depth + 1, root);
        dfs(root->right, depth + 1, root);
    }
};
// @lc code=end
