/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *p = head;
        ListNode *small = new ListNode(0);
        ListNode *smallHead = small;
        ListNode *large = new ListNode(0);
        ListNode *largeHead = large;
        while (p)
        {
            if (p->val < x)
            {
                small->next = p;
                small = small->next;
            }
            else
            {
                large->next = p;
                large = large->next;
            }
            p = p->next;
        }
        small->next = largeHead->next;
        large->next = nullptr;
        return smallHead->next;
    }
};
// @lc code=end
