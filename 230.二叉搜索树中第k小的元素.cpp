/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int ans = 0;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root, k);
        return ans;
    }
    // 辅函数 - 中序遍历
    void inOrder(TreeNode *root, int &k)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, k);
        k--;
        if (k == 0)
        {
            ans = root->val;
            return;
        }
        if (k > 0)
            inOrder(root->right, k);
    }
};
// @lc code=end
