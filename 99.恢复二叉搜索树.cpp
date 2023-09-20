/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    // 主函数
    void recoverTree(TreeNode *root)
    {
        TreeNode *x = nullptr, *y = nullptr; // 要交换的两个节点
        TreeNode *prev = nullptr;
        inOrder(root, x, y, prev);
        if (x && y)
            swap(x->val, y->val);
    }
    // 辅函数 - 中序遍历
    void inOrder(TreeNode *root, TreeNode *&x, TreeNode *&y, TreeNode *&prev)
    {
        if (root == nullptr)
            return;
        if (root->left)
            inOrder(root->left, x, y, prev);
        if (prev && root->val < prev->val)
        {
            if (x == nullptr)
            {
                x = prev;
                y = root;
            }
            else
                y = root;
            // cout << x->val;
            // cout << y->val;
        }
        prev = root;
        if (root->right)
            inOrder(root->right, x, y, prev);
    }
};

// 迭代

// class Solution
// {
// public:
//     void recoverTree(TreeNode *root)
//     {
//         if (root == nullptr)
//             return;
//         stack<TreeNode *> stk;
//         TreeNode *x = nullptr, *y = nullptr; // 要交换的两个节点
//         TreeNode *prev = nullptr;
//         // 中序遍历
//         while (!stk.empty())
//         {
//             while (root)
//             {
//                 stk.push(root);
//                 root = root->left;
//             }
//             root = stk.top();
//             stk.pop();
//             if (prev != nullptr && root->val < prev->val)
//             {
//                 y = root;
//                 if (x == nullptr)
//                     x = prev;
//                 else
//                     break;
//             }
//             prev = root;
//             root = root->right;
//         }
//         // 交换两个节点的值
//         swap(x->val, y->val);
//     }
// };
// @lc code=end
