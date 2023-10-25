/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    vector<int> nums;

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root, nums);
        if (nums.size() < 2)
            return -1;
        sort(nums.begin(), nums.end());
        return nums[1];
    }
    // 辅函数
    void dfs(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        if (count(nums.begin(), nums.end(), root->val) == 0)
            nums.push_back(root->val);
        if (root->left)
        {
            dfs(root->left, nums);
            dfs(root->right, nums);
        }
    }
};
// @lc code=end
