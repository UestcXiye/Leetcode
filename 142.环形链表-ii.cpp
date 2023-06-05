/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p = head;
        unordered_set<ListNode *> visited;
        while (p != nullptr)
        {
            if (visited.count(p))
                return p;
            visited.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};
// class Solution
// {
// public:
//     ListNode *detectCycle(ListNode *head)
//     {
//         ListNode *fast = head, *slow = head;
//         // 判断是否存在环路
//         do
//         {
//             if (fast == nullptr || fast->next == nullptr)
//                 return nullptr;
//             fast = fast->next->next;
//             slow = slow->next;
//         } while (fast != slow);
//         // 如果存在，查找环路节点
//         fast = head;
//         while (fast != slow)
//         {
//             slow = slow->next;
//             fast = fast->next;
//         }
//         return fast;
//     }
// };
// @lc code=end
