/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
public:
    // 主函数
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return dfs(root, subRoot);
    }
    // 辅函数 - 深度优先遍历
    bool dfs(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
    // 辅函数 - 对比
    bool check(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if ((root1 && !root2) || (!root1 && root2))
            return false;
        if (root1->val != root2->val)
            return false;
        return check(root1->left, root2->left) && check(root1->right, root2->right);
    }
};
// @lc code=end
