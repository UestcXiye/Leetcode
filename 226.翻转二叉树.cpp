/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

// 自顶向下递归

// class Solution
// {
// public:
//     TreeNode *invertTree(TreeNode *root)
//     {
//         if (root == nullptr)
//             return root;
//         TreeNode *left = invertTree(root->left);
//         TreeNode *right = invertTree(root->right);
//         root->left = right;
//         root->right = left;
//         return root;
//     }
// };

// 自底向上递归

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        // 交换当前节点的左右子树
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);  // 递归左节点
        invertTree(root->right); // 递归右节点
        return root;
    }
};
// @lc code=end
