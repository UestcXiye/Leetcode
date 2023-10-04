/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
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
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        // 得到正数第 k 个节点
        ListNode *head_k = head;
        for (int i = 0; i < k - 1; i++)
            head_k = head_k->next;
        // 得到倒数第 k 个节点
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k; i++)
            fast = fast->next;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 交换值
        swap(head_k->val, slow->val);
        return head;
    }
};
// @lc code=end
