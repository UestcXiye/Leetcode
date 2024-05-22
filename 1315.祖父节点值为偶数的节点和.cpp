/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int sumEvenGrandparent(TreeNode *root)
    {

        function<int(TreeNode *, TreeNode *, TreeNode *)> dfs = [&](TreeNode *root, TreeNode *father, TreeNode *grandFather) -> int
        {
            if (root == nullptr)
                return 0;
            int sum = 0;
            if (grandFather && grandFather->val % 2 == 0)
                sum += root->val;
            // 递归左右子树
            sum += dfs(root->left, root, father);
            sum += dfs(root->right, root, father);
            return sum;
        };

        return dfs(root, nullptr, nullptr);
    }
};
// @lc code=end
