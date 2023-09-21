/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 两次遍历

// class Solution
// {
// public:
//     // 主函数
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         TreeNode *ancestor = nullptr;
//         vector<TreeNode *> path_p = getPath(root, p);
//         vector<TreeNode *> path_q = getPath(root, q);
//         for (int i = 0; i < path_p.size() && i < path_q.size(); i++)
//         {
//             if (path_p[i] == path_q[i])
//                 ancestor = path_p[i];
//             else
//                 break;
//         }
//         return ancestor;
//     }
//     // 辅函数 - 得到从根节点到目标节点的路径
//     vector<TreeNode *> getPath(TreeNode *root, TreeNode *target)
//     {
//         vector<TreeNode *> path;
//         TreeNode *node = root;
//         while (node != target)
//         {
//             path.push_back(node);
//             if (node->val > target->val)
//                 node = node->left;
//             else
//                 node = node->right;
//         }
//         path.push_back(node);
//         return path;
//     }
// };

// 一次遍历

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancestor = root;
        while (1)
        {
            // 如果当前节点的值大于 p 和 q 的值，说明 p 和 q 在当前节点的左子树
            if (ancestor->val > p->val && ancestor->val > q->val)
                ancestor = ancestor->left;
            // 如果当前节点的值小于p和q的值，说明p和q在当前节点的右子树
            else if (ancestor->val < p->val && ancestor->val < q->val)
                ancestor = ancestor->right;
            else // 当前节点就是「分岔点」
                break;
        }
        return ancestor;
    }
};
// @lc code=end
