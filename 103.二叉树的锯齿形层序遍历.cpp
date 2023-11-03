/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // 特判
        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        bool isOrderLeft = true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // deque<int> levelList;
            vector<int> levelList;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                /* --- processing code --- */
                levelList.push_back(node->val);
                /* --- processing code --- */
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (!isOrderLeft)
                reverse(levelList.begin(), levelList.end());
            ans.push_back(levelList);
            isOrderLeft = !isOrderLeft;
        }
        return ans;
    }
};
// @lc code=end
