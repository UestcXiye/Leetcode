/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int ans = 0;
        int curLevel = 0;
        int maxLevelSum = INT_MIN;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            curLevel++;
            int sz = q.size();
            int levelSum = 0;
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (levelSum > maxLevelSum)
            {
                maxLevelSum = levelSum;
                ans = curLevel;
            }
        }
        return ans;
    }
};
// @lc code=end
