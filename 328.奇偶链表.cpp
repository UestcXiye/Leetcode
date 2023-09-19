/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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

// 迭代

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        // 特判
        if (head == nullptr)
            return head;
        ListNode *evenHead = head->next; // 偶数链表的开头
        ListNode *odd = head;            // 奇数链表
        ListNode *even = evenHead;       // 偶数链表
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead; // 将偶数链表连接在奇数链表之后
        return head;
    }
};
// @lc code=end
