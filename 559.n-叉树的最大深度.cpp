/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;
        int maxChildDepth = 0;
        vector<Node *> children = root->children;
        for (auto &child : children)
        {
            int childDepth = maxDepth(child);
            maxChildDepth = max(childDepth, maxChildDepth);
        }
        return maxChildDepth + 1;
    }
};
// @lc code=end
