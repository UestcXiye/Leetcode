/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
private:
    // 辅函数 - 先序遍历
    void preorder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        visit(root, nums);
        preorder(root->left, nums);
        preorder(root->right, nums);
    }
    // 辅函数 - 将当前访问节点的值记录到数组里
    void visit(TreeNode *node, vector<int> &nums)
    {
        nums.push_back(node->val);
    }

public:
    // 主函数
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> nums;
        preorder(root, nums);
        return nums;
    }
};

// 迭代

// class Solution
// {
// public:
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         if (root == nullptr)
//             return {};
//         vector<int> nums;
//         stack<TreeNode *> s;
//         s.push(root);
//         while (!s.empty())
//         {
//             TreeNode *node = s.top();
//             s.pop();
//             if (node == nullptr)
//                 continue;
//             nums.push_back(node->val);
//             // 先压入右子树，再压入左子树
//             // 由于栈的特性，先访问左子树，再访问右子树，符合先序遍历
//             if (node->right)
//                 s.push(node->right);
//             if (node->left)
//                 s.push(node->left);
//         }
//         return nums;
//     }
// };
// @lc code=end
