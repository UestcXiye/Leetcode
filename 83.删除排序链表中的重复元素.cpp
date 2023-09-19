/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 特判
        if (head == nullptr)
            return head;
        ListNode *p = head;
        while (p && p->next)
        {
            ListNode *node = p->next;
            if (p->val == node->val)
            {
                p->next = node->next;
                node->next = nullptr;
                delete node;
            }
            else
                p = p->next;
        }
        return head;
    }
};
// @lc code=end
