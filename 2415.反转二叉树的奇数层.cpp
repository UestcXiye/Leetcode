/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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

// 层序遍历

// class Solution
// {
// public:
//     TreeNode *reverseOddLevels(TreeNode *root)
//     {
//         if (root == nullptr)
//             return nullptr;
//         queue<TreeNode *> q;
//         q.push(root);
//         bool isOdd = false;
//         while (!q.empty())
//         {
//             int size = q.size();
//             vector<TreeNode *> arr;
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if (isOdd)
//                     arr.push_back(node);
//                 if (node->left)
//                     q.push(node->left);
//                 if (node->right)
//                     q.push(node->right);
//             }
//             if (isOdd)
//             {
//                 for (int l = 0, r = size - 1; l < r; l++, r--)
//                     swap(arr[l]->val, arr[r]->val);
//             }
//             isOdd = !isOdd;
//         }
//         return root;
//     }
// };

// 深度优先搜索

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root->left, root->right, true);
        return root;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root1, TreeNode *root2, bool isOdd)
    {
        if (root1 == nullptr || root2 == nullptr)
            return;
        if (isOdd)
            swap(root1->val, root2->val);
        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
    }
};
// @lc code=end
