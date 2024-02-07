/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        root->val = 0;

        while (!q.empty())
        {
            int n = q.size();
            // 每一个兄弟节点值的和
            vector<int> s(n, 0);
            int sum = 0;
            // 用于处理当前层，暂时存储
            vector<TreeNode *> tmp;
            // 维护下一层的堂兄弟节点值的和
            for (int i = 0; i < n; i++)
            {
                TreeNode *u = q.front();
                tmp.push_back(u);
                q.pop();
                if (u->left)
                {
                    s[i] += u->left->val;
                    q.push(u->left);
                }
                if (u->right)
                {
                    s[i] += u->right->val;
                    q.push(u->right);
                }
                sum += s[i];
            }
            // 修改下一层的节点
            for (int i = 0; i < n; i++)
            {
                TreeNode *u = tmp[i];
                // 更新为其所有堂兄弟节点值的和，不包括自身
                int res = sum - s[i]; // 更新后的值
                if (u->left)
                    u->left->val = res;
                if (u->right)
                    u->right->val = res;
            }
        }
        return root;
    }
};
// @lc code=end
