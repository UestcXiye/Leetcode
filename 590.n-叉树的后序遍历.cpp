/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> nums;
        helper(root, nums);
        return nums;
    }
    // 辅函数
    void helper(const Node *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;

        for (auto &child : root->children)
            helper(child, nums);
        nums.emplace_back(root->val);
    }
};
// @lc code=end
