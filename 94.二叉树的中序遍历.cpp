/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

// 递归

// class Solution
// {
// public:
//     // 主函数
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> nums;
//         inOrder(root, nums);
//         return nums;
//     }
//     // 辅函数 - 中序遍历
//     void inOrder(TreeNode *root, vector<int> &nums)
//     {
//         if (root == nullptr)
//             return;
//         inOrder(root->left, nums);
//         nums.push_back(root->val);
//         inOrder(root->right, nums);
//     }
// };

// 迭代

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> nums;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (!s.empty() || node)
        {
            while (node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            nums.push_back(node->val);
            node = node->right;
        }
        return nums;
    }
};
// @lc code=end
