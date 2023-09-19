/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

// 计算链表长度

// class Solution
// {
// private:
//     int getListLength(ListNode *head)
//     {
//         int len = 0;
//         ListNode *p = head;
//         while (p)
//         {
//             len++;
//             p = p->next;
//         }
//         return len;
//     }

// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         ListNode *dummy = new ListNode();
//         dummy->next = head;
//         ListNode *p = dummy;
//         int len = getListLength(head);
//         for (int i = 0; i < len - n; i++)
//             p = p->next;
//         ListNode *delNode = p->next;
//         p->next = delNode->next;
//         delNode->next = nullptr;
//         delete delNode;
//         return dummy->next;
//     }
// };

// 栈

// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         ListNode *dummy = new ListNode(0, head);
//         stack<ListNode *> stk;
//         ListNode *cur = dummy;
//         while (cur)
//         {
//             stk.push(cur);
//             cur = cur->next;
//         }
//         for (int i = 0; i < n; i++)
//             stk.pop();
//         ListNode *prev = stk.top();
//         ListNode *delNode = prev->next;
//         prev->next = delNode->next;
//         delNode->next = nullptr;
//         delete delNode;
//         return dummy->next;
//     }
// };

// 快慢指针

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = head;
        ListNode *slow = dummy;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // slow->next 就是要删除的节点
        ListNode *delNode = slow->next;
        slow->next = delNode->next;
        delNode->next = nullptr;
        delete delNode;
        return dummy->next;
    }
};
// @lc code=end
