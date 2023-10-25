/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
// class Solution
// {
// private:
//     vector<int> nums;

// public:
//     int minDiffInBST(TreeNode *root)
//     {
//         inOrder(root, nums);
//         sort(nums.begin(), nums.end());
//         int minDiff = __INT_MAX__;
//         for (int i = 1; i < nums.size(); i++)
//             minDiff = min(minDiff, nums[i] - nums[i - 1]);
//         return minDiff;
//     }
//     // 辅函数 - 深度优先搜索
//     void inOrder(TreeNode *root, vector<int> &nums)
//     {
//         if (root == nullptr)
//             return;
//         nums.push_back(root->val);
//         if (root->left)
//             inOrder(root->left, nums);
//         if (root->right)
//             inOrder(root->right, nums);
//     }
// };

// 中序遍历

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX, pre = -1;
        inOrder(root, pre, ans);
        return ans;
    }
    // 辅函数 - 中序遍历
    void inOrder(TreeNode *root, int &pre, int &ans)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, pre, ans);
        if (pre == -1)
            pre = root->val;
        else
        {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        inOrder(root->right, pre, ans);
    }
};
// @lc code=end
