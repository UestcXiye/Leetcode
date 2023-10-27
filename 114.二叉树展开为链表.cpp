/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode *root)
    {
        // 特判
        if (root == nullptr)
            return;
        preOrder(root, nums);
        // 根据数组 nums 修改树
        TreeNode *cur = root;
        for (int i = 0; i < nums.size(); i++)
        {
            cur->val = nums[i];
            cur->left = nullptr;
            if (!cur->right && i != nums.size() - 1)
                cur->right = new TreeNode();
            cur = cur->right;
        }
    }
    // 辅函数 - 先序遍历
    void preOrder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        nums.push_back(root->val);
        preOrder(root->left, nums);
        preOrder(root->right, nums);
    }
};
// @lc code=end
