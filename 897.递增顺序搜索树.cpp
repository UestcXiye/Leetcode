/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> nums;
        inOrder(root, nums);
        return myBuildTree(nums);
    }
    // 辅函数 - 中序遍历，并记录值
    void inOrder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    // 辅函数 - 根据数组 nums 建立递增顺序 BST
    TreeNode *myBuildTree(vector<int> &nums)
    {
        TreeNode *dummy = new TreeNode();
        TreeNode *cur = dummy;
        for (int &num : nums)
        {
            cur->right = new TreeNode(num);
            cur = cur->right;
        }
        return dummy->right;
    }
};
// @lc code=end
