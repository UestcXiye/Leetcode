/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    int post_idx;
    unordered_map<int, int> index;

public:
    // 主函数
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        // 从后序遍历的最后一个元素开始
        post_idx = n - 1;
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return myBuildTree(inorder, postorder, 0, n - 1);
    }
    // 辅函数
    TreeNode *myBuildTree(vector<int> &inorder, vector<int> &postorder, int in_left, int in_right)
    {
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right)
            return nullptr;
        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);
        // 根据 root 所在位置分成左右两棵子树
        int root_index = index[root_val];
        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = myBuildTree(inorder, postorder, root_index + 1, in_right);
        // 构造左子树
        root->left = myBuildTree(inorder, postorder, in_left, root_index - 1);
        return root;
    }
};
// @lc code=end
