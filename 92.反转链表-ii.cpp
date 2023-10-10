/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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

// 模拟

// class Solution
// {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right)
//     {
//         vector<int> nums = getNums(head);
//         reverse(nums.begin() + left - 1, nums.begin() + right);
//         return buildList(nums);
//     }
//     // 辅函数 - 遍历链表
//     vector<int> getNums(ListNode *head)
//     {
//         ListNode *p = head;
//         vector<int> nums;
//         while (p)
//         {
//             nums.push_back(p->val);
//             p = p->next;
//         }
//         return nums;
//     }
//     // 辅函数 - 根据数组建立链表
//     ListNode *buildList(vector<int> &nums)
//     {
//         ListNode *dummy = new ListNode(0);
//         ListNode *cur = dummy;
//         for (int &num : nums)
//         {
//             ListNode *node = new ListNode(num);
//             cur->next = node;
//             cur = cur->next;
//         }
//         return dummy->next;
//     }
// };

// 穿针引线

// class Solution
// {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right)
//     {
//         ListNode *dummy = new ListNode(0, head);
//         ListNode *pre = dummy;
//         // 从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
//         for (int i = 0; i < left - 1; i++)
//             pre = pre->next;
//         // 从 pre 再走 right - left + 1 步，来到 right 节点
//         ListNode *rightNode = pre;
//         for (int i = 0; i < right - left + 1; i++)
//             rightNode = rightNode->next;
//         // 切断出一个子链表（截取链表）
//         ListNode *leftNode = pre->next;
//         ListNode *cur = rightNode->next;
//         // 切断链接
//         pre->next = nullptr;
//         rightNode->next = nullptr;
//         // 反转链表的子区间
//         reverseLinkedList(leftNode);
//         // 接回到原来的链表中
//         pre->next = rightNode;
//         leftNode->next = cur;
//         return dummy->next;
//     }
//     // 辅函数 - 反转链表
//     void reverseLinkedList(ListNode *head)
//     {
//         ListNode *pre = nullptr;
//         ListNode *cur = head;
//         while (cur)
//         {
//             ListNode *next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//     }
// };

// 一次遍历「穿针引线」反转链表（头插法）

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // pre 永远指向待反转区域的第一个节点 left 的前一个节点，在循环过程中不变
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++)
            pre = pre->next;
        // cur 指向待反转区域的第一个节点
        ListNode *cur = pre->next;
        // next 永远指向 cur 的下一个节点
        ListNode *next;
        for (int i = 0; i < right - left; i++)
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};

// @lc code=end
