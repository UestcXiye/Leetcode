/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
    ListNode *removeNodes(ListNode *head)
    {
        // 特判
        if (head == nullptr)
            return head;
        // 单调栈
        stack<int> stk;
        // 遍历链表
        ListNode *p = head;
        while (p)
        {
            while (!stk.empty() && stk.top() < p->val)
                stk.pop();
            stk.push(p->val);
            p = p->next;
        }
        // 头插法建立单链表
        ListNode *dummy = new ListNode(-1, nullptr);
        while (!stk.empty())
        {
            ListNode *node = new ListNode(stk.top());
            node->next = dummy->next;
            dummy->next = node;
            stk.pop();
        }
        return dummy->next;
    }
};
// @lc code=end
