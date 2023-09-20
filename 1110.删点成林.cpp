/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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

// 后序遍历

class Solution
{
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> forest;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = postOrder(root, dict, forest);
        if (root)
            forest.push_back(root);
        return forest;
    }
    // 辅函数 - 后序遍历
    TreeNode *postOrder(TreeNode *root, unordered_set<int> &dict, vector<TreeNode *> &forest)
    {
        if (root == nullptr)
            return root;
        root->left = postOrder(root->left, dict, forest);
        root->right = postOrder(root->right, dict, forest);
        if (dict.count(root->val))
        {
            if (root->left)
                forest.push_back(root->left);
            if (root->right)
                forest.push_back(root->right);
            root = nullptr;
        }
        return root;
    }
};
// @lc code=end
