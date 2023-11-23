/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
private:
    int index = 0;
    vector<int> nums;
    // 辅函数
    void inOrder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    // 中序遍历
    vector<int> inOrderTraversal(TreeNode *root)
    {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

public:
    BSTIterator(TreeNode *root) : index(0), nums(inOrderTraversal(root))
    {
    }

    int next()
    {
        int num = nums[index];
        index++;
        return num;
    }

    bool hasNext()
    {
        return (index < nums.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
