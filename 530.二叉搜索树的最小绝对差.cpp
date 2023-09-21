/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int ans = __INT_MAX__;
    TreeNode *pre = nullptr;

public:
    // 主函数
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return ans;
    }
    // 辅函数 - 中序遍历
    void inOrder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        if (pre != nullptr)
            ans = min(ans, abs(node->val - pre->val));
        pre = node;
        inOrder(node->right);
    }
};
// @lc code=end
