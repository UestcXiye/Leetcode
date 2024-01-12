/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
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
//     bool flipEquiv(TreeNode *root1, TreeNode *root2)
//     {
//         // 特判
//         if (root1 == nullptr && root2 == nullptr)
//             return true;
//         if ((root1 && root2 == nullptr) || (root1 == nullptr && root2))
//             return false;
//         if (root1->val != root2->val)
//             return false;

//         return helper(root1, root2);
//     }
//     // 辅函数 - 递归
//     bool helper(TreeNode *root1, TreeNode *root2)
//     {
//         if (root1 == root2)
//             return true;
//         if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
//             return false;

//         return (helper(root1->left, root2->left) && helper(root1->right, root2->right)) ||
//                (helper(root1->right, root2->left) && helper(root1->left, root2->right));
//     }
// };

// 标准态遍历

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        // 特判
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if ((root1 && root2 == nullptr) || (root1 == nullptr && root2))
            return false;
        if (root1->val != root2->val)
            return false;

        vector<int> seq1, seq2;
        StandardTraversal(root1, seq1);
        StandardTraversal(root2, seq2);
        return seq1 == seq2;
    }
    // 辅函数 - 标准态遍历
    void StandardTraversal(TreeNode *root, vector<int> &sequence)
    {
        if (root == nullptr)
            return;
        sequence.push_back(root->val);
        int leftVal = root->left ? root->left->val : -1;
        int rightVal = root->right ? root->right->val : -1;
        if (leftVal > rightVal)
        {
            StandardTraversal(root->left, sequence);
            StandardTraversal(root->right, sequence);
        }
        else
        {
            StandardTraversal(root->right, sequence);
            StandardTraversal(root->left, sequence);
        }
        // 确保两个树深度一致，不同深度的树可能具有相同前序遍历结果
        sequence.push_back(-1);
    }
};
// @lc code=end
