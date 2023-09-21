/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();
        return myBuildTree(pre, post, 0, n - 1, 0, n - 1);
    }
    // 辅函数
    TreeNode *myBuildTree(vector<int> &pre, vector<int> &post, int preStart, int preEnd, int postStart, int postEnd)
    {
        if (preStart > preEnd)
            return nullptr;
        TreeNode *root = new TreeNode(pre[preStart]);
        if (preStart == preEnd)
        { // 只有一个，直接返回
            return root;
        }
        int i = postStart;
        while (i < postEnd && post[i] != pre[preStart + 1])
        {
            // 确定分界点，左子树的根节点
            i++;
        }
        int len = i - postStart + 1; // 左子树长度
        root->left = myBuildTree(pre, post, preStart + 1, preStart + len, postStart, i);
        root->right = myBuildTree(pre, post, preStart + 1 + len, preEnd, i + 1, postEnd - 1);
        return root;
    }
};
// @lc code=end
