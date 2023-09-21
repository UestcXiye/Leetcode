/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// 分治

class Solution
{
public:
    // 主函数
    TreeNode *sortedListToBST(ListNode *head)
    {
        return buildTree(head, nullptr);
    }
    // 辅函数 - 利用 List[left...right) 建树
    TreeNode *buildTree(ListNode *left, ListNode *right)
    {
        if (left == right)
            return nullptr;
        ListNode *mid = getMiddleNode(left, right);
        TreeNode *node = new TreeNode(mid->val);
        node->left = buildTree(left, mid);
        node->right = buildTree(mid->next, right);
        return node;
    }
    // 辅函数 - 利用快慢指针得到中间节点
    ListNode *getMiddleNode(ListNode *left, ListNode *right)
    {
        ListNode *slow = left, *fast = left;
        while (fast != right && fast->next != right)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end
