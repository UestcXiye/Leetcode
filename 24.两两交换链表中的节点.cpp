/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        //  特判
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *temp = dummy;
        while (temp->next && temp->next->next)
        {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummy->next;
    }
};

// 递归

// class Solution
// {
// public:
//     ListNode *swapPairs(ListNode *head)
//     {
//         //  特判
//         if (!head || !head->next)
//             return head;
//         ListNode *newHead = head->next;
//         head->next = swapPairs(newHead->next);
//         newHead->next = head;
//         return newHead;
//     }
// };
// @lc code=end
