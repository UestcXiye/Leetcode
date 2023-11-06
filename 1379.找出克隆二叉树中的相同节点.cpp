/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
private:
    TreeNode *target = nullptr;
    TreeNode *node = nullptr;

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        this->target = target;
        if (original == nullptr)
            return nullptr;
        dfs(original, cloned);
        return node;
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *original, TreeNode *cloned)
    {
        if (original == nullptr)
            return;
        if (original == target)
        {
            node = cloned;
            return;
        }
        if (original->left)
            dfs(original->left, cloned->left);
        if (original->right)
            dfs(original->right, cloned->right);
    }
};
// @lc code=end
