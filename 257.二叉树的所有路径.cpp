/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    // 主函数
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }
    // 辅函数
    void dfs(TreeNode *root, string path, vector<string> &paths)
    {
        if (root != nullptr)
        {
            path += to_string(root->val);
            // 当前节点是叶子节点
            if (root->left == nullptr && root->right == nullptr)
                paths.push_back(path); // 把路径加入到答案中
            else                       // 当前节点不是叶子节点，继续递归遍历
            {
                path += "->";
                dfs(root->left, path, paths);
                dfs(root->right, path, paths);
            }
        }
    }
};
// @lc code=end
