/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        // 特判
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
    // 辅函数 - 回溯
    vector<TreeNode *> generateTrees(int start, int end)
    {
        if (start > end)
            return {nullptr};
        vector<TreeNode *> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; i++)
        {
            // 获得所有可行的左子树集合
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            // 获得所有可行的右子树集合
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto &leftNode : leftTrees)
                for (auto &rightNode : rightTrees)
                {
                    TreeNode *curTree = new TreeNode(i);
                    curTree->left = leftNode;
                    curTree->right = rightNode;
                    allTrees.push_back(curTree);
                }
        }
        return allTrees;
    }
};
// @lc code=end
