/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
private:
    vector<int> leafNums1;
    vector<int> leafNums2;

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        dfs(root1, leafNums1);
        dfs(root2, leafNums2);
        return compareVector(leafNums1, leafNums2);
    }
    // 辅函数 - 深度优先搜索
    void dfs(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            nums.push_back(root->val);
        if (root->left)
            dfs(root->left, nums);
        if (root->right)
            dfs(root->right, nums);
    }
    // 辅函数 - 判断两个数组是否相同
    bool compareVector(const vector<int> v1, const vector<int> v2)
    {
        if (v1.size() != v2.size())
            return false;
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                return false;
        return true;
    }
};
// @lc code=end
