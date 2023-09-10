/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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

// 记录所有链表元素

// class Solution
// {
//     vector<int> nums;

// public:
//     Solution(ListNode *head)
//     {
//         ListNode *p = head;
//         while (p != nullptr)
//         {
//             nums.push_back(p->val);
//             p = p->next;
//         }
//     }

//     int getRandom()
//     {
//         int n = nums.size();
//         int pos = rand() % n;
//         return nums[pos];
//     }
// };

// 水塘抽样

class Solution
{
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
    }

    int getRandom()
    {
        int ans = head->val;
        ListNode *node = head->next;
        int i = 2;
        while (node != nullptr)
        {
            if ((rand() % i) == 0) // 1/i 的概率选中（替换为答案）
                ans = node->val;
            i++;
            node = node->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
