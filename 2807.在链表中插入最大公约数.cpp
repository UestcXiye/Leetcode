/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        // 特判
        if (head == nullptr)
            return nullptr;

        for (ListNode *cur = head; cur->next != nullptr; cur = cur->next->next)
        {
            ListNode *gcdNode = new ListNode(gcd(cur->val, cur->next->val));
            gcdNode->next = cur->next;
            cur->next = gcdNode;
        }
        return head;
    }
    // 辅函数 - 求 x 和 y 的最大公约数
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
};
// @lc code=end
