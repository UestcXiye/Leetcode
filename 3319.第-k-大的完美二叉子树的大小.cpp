/*
 * @lc app=leetcode.cn id=3319 lang=cpp
 *
 * [3319] 第 K 大的完美二叉子树的大小
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
    int kthLargestPerfectSubtree(TreeNode *root, int k)
    {
        // 完美二叉子树的高度
        vector<int> heights;

        function<int(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root == nullptr)
                return 0;

            int leftHeight = dfs(root->left);
            int rightHeight = dfs(root->right);

            if (leftHeight < 0 || rightHeight < 0 || leftHeight != rightHeight)
                return -1;

            int height = leftHeight + 1;
            heights.push_back(height);

            return height;
        };

        dfs(root);

        if (heights.size() < k)
            return -1;

        sort(heights.begin(), heights.end(), greater<int>());

        // 设完美二叉树的高度为 h，其大小为 2^h-1
        return (1 << heights[k - 1]) - 1;
    }
};
// @lc code=end
