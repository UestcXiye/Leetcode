/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

// 递归

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;
        // 当前节点的值大于 key，递归去其左子树删除
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        // 当前节点的值小于 key，递归去其右子树删除
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // 找到需要删除的节点
        if (root->val == key)
        {
            // root 为叶子节点，直接删除
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            // root 只有左子树，返回左子树
            if (root->left && root->right == nullptr)
                return root->left;
            // root 只有右子树，返回右子树
            if (root->left == nullptr && root->right)
                return root->right;
            // root 有左右子树
            TreeNode *node = root->right;
            // 找到删除节点的右子树的最左下节点
            while (node->left)
                node = node->left;
            // 将删除节点的左子树成为其右子树的最左节点的左子树
            node->left = root->left;
            // 删除节点的右子树顶替其位置，节点被删除
            root = root->right;
        }
        return root;
    }
};
// @lc code=end
