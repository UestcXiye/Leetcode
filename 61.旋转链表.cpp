/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // 特判
        if (head == nullptr)
            return nullptr;
        int len = getLength(head);
        int pos = k % len;
        // pos 为 0，说明旋转后的链表与原链表一样，直接返回头结点
        if (pos == 0)
            return head;
        // fast 指向原链表的尾结点，slow 指向新链表的尾结点
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < pos; i++)
            fast = fast->next;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next; // slow->next 就是新链表的头节点
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
    // 辅函数 - 得到链表长度
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            len++;
        }
        return len;
    }
};
// @lc code=end
