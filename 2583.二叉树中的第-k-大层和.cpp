/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
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

// 层序遍历 + 排序

// class Solution
// {
// public:
//     long long kthLargestLevelSum(TreeNode *root, int k)
//     {
//         if (root == nullptr)
//             return -1;

//         vector<long long> levelSum;
//         queue<TreeNode *> q;
//         q.push(root);
//         while (!q.empty())
//         {
//             int size = q.size();
//             long long sum = 0LL;
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 sum += node->val;
//                 if (node->left)
//                     q.push(node->left);
//                 if (node->right)
//                     q.push(node->right);
//             }
//             levelSum.push_back(sum);
//         }

//         if (levelSum.size() < k)
//             return -1;

//         sort(levelSum.begin(), levelSum.end());

//         return levelSum[levelSum.size() - k];
//     }
// };

// 层序遍历 + 快速选择

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        if (root == nullptr)
            return -1;

        vector<long long> levelSum;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0LL;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelSum.push_back(sum);
        }

        int n = levelSum.size();
        if (k > n)
            return -1;
        ranges::nth_element(levelSum, levelSum.begin() + (n - k));
        return levelSum[n - k];
    }
};
// @lc code=end
