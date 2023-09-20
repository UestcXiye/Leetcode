/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return root;
        // 节点值 > high，说明该节点及它的右子树都不符合要求
        if (root->val > high)
        {
            // 返回对它的左子树进行修剪后的结果
            return trimBST(root->left, low, high);
        }
        // 节点值 < low，说明该节点及它的左子树都不符合要求
        if (root->val < low)
        {
            // 返回对它的右结点进行修剪后的结果
            return trimBST(root->right, low, high);
        }
        // 节点值位于区间 [low, high]
        root->left = trimBST(root->left, low, high);   // 将结点的左结点设为对它的左子树修剪后的结果
        root->right = trimBST(root->right, low, high); // 右结点设为对它的右子树进行修剪后的结果
        return root;
    }
};

// 迭代

// class Solution
// {
// public:
//     TreeNode *trimBST(TreeNode *root, int low, int high)
//     {
//         while (root && (root->val < low || root->val > high))
//         {
//             if (root->val < low)
//                 root = root->right;
//             else
//                 root = root->left;
//         }
//         if (root == nullptr)
//             return root;
//         // 左子树的修剪
//         for (auto node = root; node->left;)
//         {
//             // node 的左结点的值 < low，node->left 及其左子树需要修剪
//             if (node->left->val < low)
//             {
//                 // 将 node 的左结点设为 left 的右节点，再重新对 node 的左子树进行修剪
//                 node->left = node->left->right;
//             }
//             else // left 的右子树一定符合要求
//             {
//                 // 我们只需要对 left 的左子树进行修剪
//                 node = node->left;
//             }
//         }
//         // 右子树的修剪
//         for (auto node = root; node->right;)
//         {
//             if (node->right->val > high)
//                 node->right = node->right->left;
//             else
//                 node = node->right;
//         }
//         return root;
//     }
// };
// @lc code=end
