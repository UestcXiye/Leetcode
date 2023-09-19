/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         // 特判
//         if (list1 == nullptr)
//             return list2;
//         if (list2 == nullptr)
//             return list1;
//         ListNode *dummy = new ListNode();
//         ListNode *list = dummy;
//         while (list1 && list2)
//         {
//             if (list1->val < list2->val)
//             {
//                 list->next = list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 list->next = list2;
//                 list2 = list2->next;
//             }
//             list = list->next;
//         }
//         // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
//         list->next = list1 == nullptr ? list2 : list1;
//         return dummy->next;
//     }
// };

// 递归

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end
