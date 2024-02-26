/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int sum = 0;

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        inOrder(root, low, high);
        return sum;
    }
    // 辅函数 - 中序遍历
    void inOrder(TreeNode *root, const int low, const int high)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, low, high);
        int val = root->val;
        if (val >= low && val <= high)
            sum += root->val;
        inOrder(root->right, low, high);
    }
};
// @lc code=end
