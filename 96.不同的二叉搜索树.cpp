/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

// 回溯

// class Solution
// {
// public:
//     int numTrees(int n)
//     {
//         // 特判
//         if (n == 0)
//             return 0;
//         vector<TreeNode *> allTrees = generateTrees(1, n);
//         return allTrees.size();
//     }
//     // 辅函数 - 回溯
//     vector<TreeNode *> generateTrees(int start, int end)
//     {
//         if (start > end)
//             return {nullptr};
//         vector<TreeNode *> allTrees;
//         // 枚举可行根节点
//         for (int i = start; i <= end; i++)
//         {
//             // 获得所有可行的左子树集合
//             vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
//             // 获得所有可行的右子树集合
//             vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
//             // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
//             for (auto &leftNode : leftTrees)
//                 for (auto &rightNode : rightTrees)
//                 {
//                     TreeNode *curTree = new TreeNode(i);
//                     curTree->left = leftNode;
//                     curTree->right = rightNode;
//                     allTrees.push_back(curTree);
//                 }
//         }
//         return allTrees;
//     }
// };

// 动态规划

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

// 数学

// class Solution
// {
// public:
//     int numTrees(int n)
//     {
//         long long C = 1;
//         for (int i = 0; i < n; ++i)
//         {
//             C = C * 2 * (2 * i + 1) / (i + 2);
//         }
//         return (int)C;
//     }
// };
// @lc code=end
