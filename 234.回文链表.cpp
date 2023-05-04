/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *p = head;
        vector<int> nums;
        while (p)
        {
            nums.push_back(p->val);
            p = p->next;
        }
        vector<int> rev(nums.rbegin(), nums.rend());
        return rev == nums;
    }
};

// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         if (head == nullptr)
//         {
//             return true;
//         }

//         // 找到前半部分链表的尾节点并反转后半部分链表
//         ListNode *firstHalfEnd = endOfFirstHalf(head);
//         ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

//         // 判断是否回文
//         ListNode *p1 = head;
//         ListNode *p2 = secondHalfStart;
//         bool result = true;
//         while (result && p2 != nullptr)
//         {
//             if (p1->val != p2->val)
//             {
//                 result = false;
//             }
//             p1 = p1->next;
//             p2 = p2->next;
//         }

//         // 还原链表并返回结果
//         firstHalfEnd->next = reverseList(secondHalfStart);
//         return result;
//     }

//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         ListNode *curr = head;
//         while (curr != nullptr)
//         {
//             ListNode *nextTemp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextTemp;
//         }
//         return prev;
//     }

//     ListNode *endOfFirstHalf(ListNode *head)
//     {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         while (fast->next != nullptr && fast->next->next != nullptr)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };

// @lc code=end
