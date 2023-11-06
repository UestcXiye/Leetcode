/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode *insertionSortList(ListNode *head)
    {
        // 特判
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *lastSorted = head;
        ListNode *cur = head->next;
        while (cur)
        {
            if (lastSorted->val <= cur->val)
                lastSorted = lastSorted->next;
            else
            {
                ListNode *prev = dummy;
                while (prev->next->val <= cur->val)
                    prev = prev->next;
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummy->next;
    }
};
// @lc code=end
