/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// 辅助数组

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *p = head;
//         vector<int> nums;
//         while (p)
//         {
//             nums.push_back(p->val);
//             p = p->next;
//         }
//         int n = nums.size();
//         p = head;
//         for (int i = nums.size() - 1; i >= 0; i--)
//         {
//             p->val = nums[i];
//             p = p->next;
//         }
//         return head;
//     }
// };

// 迭代

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// 递归

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == nullptr || head->next == nullptr)
//             return head;
//         ListNode *newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr; // 如果忽略了这一点，链表中可能会产生环
//         return newHead;
//     }
// };
// @lc code=end
