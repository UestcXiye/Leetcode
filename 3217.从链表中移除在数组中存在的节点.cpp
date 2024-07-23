/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> dict(nums.begin(), nums.end());
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next)
        {
            if (dict.contains(p->next->val))
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end
