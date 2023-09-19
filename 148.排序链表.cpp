/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

// 使用数组辅助计数

// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         ListNode *p = head;
//         vector<int> nums;
//         while (p)
//         {
//             nums.push_back(p->val);
//             p = p->next;
//         }
//         sort(nums.begin(), nums.end());
//         p = head;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             p->val = nums[i];
//             p = p->next;
//         }
//         return head;
//     }
// };

// 自顶向下归并排序

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }
    // 辅函数 - 给定头尾指针，进行归并排序
    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return head;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    // 辅函数 - 按升序合并两个链表
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1)
            temp->next = temp1;
        else if (temp2)
            temp->next = temp2;
        return dummyHead->next;
    }
};
// @lc code=end
