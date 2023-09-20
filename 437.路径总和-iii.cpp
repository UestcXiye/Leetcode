/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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

// 深度优先搜索

// class Solution
// {
// public:
//     int pathSum(TreeNode *root, int targetSum)
//     {
//         if (root == nullptr)
//             return 0;
//         return pathSumStartWithRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
//     }
//     // 辅函数，long long防止test case中大数溢出，一般情况下用int即可
//     long long pathSumStartWithRoot(TreeNode *root, long long sum)
//     {
//         if (root == nullptr)
//             return 0;
//         long long count = root->val == sum ? 1 : 0;
//         count += pathSumStartWithRoot(root->left, sum - root->val);
//         count += pathSumStartWithRoot(root->right, sum - root->val);
//         return count;
//     }
// };

// 回溯 + 前缀和

class Solution
{
private:
    unordered_map<long long, int> prefix; //<前缀和，次数>

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        prefix[0] = 1; // 初始化
        return dfs(root, 0, targetSum);
    }
    // 辅函数
    int dfs(TreeNode *root, long long curr, int targetSum)
    {
        if (root == nullptr)
            return 0;
        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum))
            ret = prefix[curr - targetSum];
        prefix[curr]++; // 修改当前节点状态
        // 递归子节点
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--; // 回改当前节点状态
        return ret;
    }
};
// @lc code=end
