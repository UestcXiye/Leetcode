/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node *root)
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
        nums.push_back(root->val);
        for (auto &child : root->children)
            helper(child, nums);
    }
};
// @lc code=end
