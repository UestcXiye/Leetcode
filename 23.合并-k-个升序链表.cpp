/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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

// 顺序合并

// class Solution
// {
// private:
//     ListNode *mergeTwoLists(ListNode *a, ListNode *b)
//     {
//         if ((!a) || (!b))
//             return a ? a : b;
//         ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//         while (aPtr && bPtr)
//         {
//             if (aPtr->val < bPtr->val)
//             {
//                 tail->next = aPtr;
//                 aPtr = aPtr->next;
//             }
//             else
//             {
//                 tail->next = bPtr;
//                 bPtr = bPtr->next;
//             }
//             tail = tail->next;
//         }
//         tail->next = (aPtr ? aPtr : bPtr);
//         return head.next;
//     }

// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         ListNode *ans = nullptr;
//         for (size_t i = 0; i < lists.size(); i++)
//             ans = mergeTwoLists(ans, lists[i]);
//         return ans;
//     }
// };

// 分治合并

// class Solution
// {
// private:
//     ListNode *mergeTwoLists(ListNode *a, ListNode *b)
//     {
//         if ((!a) || (!b))
//             return a ? a : b;
//         ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//         while (aPtr && bPtr)
//         {
//             if (aPtr->val < bPtr->val)
//             {
//                 tail->next = aPtr;
//                 aPtr = aPtr->next;
//             }
//             else
//             {
//                 tail->next = bPtr;
//                 bPtr = bPtr->next;
//             }
//             tail = tail->next;
//         }
//         tail->next = (aPtr ? aPtr : bPtr);
//         return head.next;
//     }

//     ListNode *merge(vector<ListNode *> &lists, int left, int right)
//     {
//         if (left == right)
//             return lists[left];
//         if (left > right)
//             return nullptr;
//         int mid = (left + right) >> 1;
//         return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
//     }

// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         return merge(lists, 0, lists.size() - 1);
//     }
// };

// 优先队列 priority_queue

class Solution
{
private:
    struct Comp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, Comp> q; // 降序队列
        for (ListNode *list : lists)
            if (list)
                q.push(list);
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (!q.empty())
        {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next)
                q.push(cur->next);
        }
        return dummy->next;
    }
};
// @lc code=end
