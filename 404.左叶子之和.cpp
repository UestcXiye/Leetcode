/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int sumOfLeftLeafNode = 0;
        dfs(root, sumOfLeftLeafNode);
        return sumOfLeftLeafNode;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, int &sum)
    {
        if (root->left != nullptr)
        {
            if (isLeafNode(root->left))
                sum += root->left->val;
            else
                dfs(root->left, sum);
        }
        if (root->right != nullptr && isLeafNode(root->right) == false)
            dfs(root->right, sum);
    }
    // 辅函数 - 判断是否为叶子节点
    bool isLeafNode(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
};
// @lc code=end
