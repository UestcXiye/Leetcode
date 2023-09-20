/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//     int maxDepth(TreeNode *root)
//     {
//         if (root == nullptr)
//             return 0;
//         int maxLeftDepth = maxDepth(root->left);
//         int maxRightDepth = maxDepth(root->right);
//         return 1 + max(maxLeftDepth, maxRightDepth);
//     }
// };

// one-line code
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
// @lc code=end
