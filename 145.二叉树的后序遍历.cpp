/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> nums;
//         postOrder(root, nums);
//         return nums;
//     }
//     // 辅函数 - 后序遍历
//     void postOrder(TreeNode *root, vector<int> &nums)
//     {
//         if (root == nullptr)
//             return;
//         postOrder(root->left, nums);
//         postOrder(root->right, nums);
//         nums.push_back(root->val);
//     }
// };

// 迭代

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> nums;
        stack<TreeNode *> s;
        TreeNode *node = root, *prev = nullptr;
        while (!s.empty() || node)
        {
            while (node)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            // 如果没有右子树，或者右子树访问完了，说明可以访问当前节点
            if (node->right == nullptr || node->right == prev)
            {
                // 更新历史访问记录，这样回溯的时候父节点可以由此判断右子树是否访问完成
                nums.push_back(node->val);
                prev = node;
                node = nullptr;
            }
            else // 如果右子树没有被访问，那么将当前节点压栈，访问右子树
            {
                s.push(node);
                node = node->right;
            }
        }
        return nums;
    }
};
// @lc code=end
