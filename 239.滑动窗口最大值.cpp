/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

// 暴力
// Time Limit Exceeded

// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> ans;
//         for (int i = 0; i <= nums.size() - k; i++)
//         {
//             int max_num = INT_MIN;
//             for (int j = i; j < i + k; j++)
//                 max_num = max(max_num, nums[j]);
//             ans.push_back(max_num);
//         }
//         return ans;
//     }
// };

// 优先队列 priority_queue

// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         priority_queue<pair<int, int>> q; //<值，位置>
//         // 初始时，将数组 nums 前 k 个元素放入优先队列中
//         for (int i = 0; i < k; i++)
//             q.push(make_pair(nums[i], i));
//         vector<int> ans;
//         ans.push_back(q.top().first);
//         for (int i = k; i < nums.size(); i++)
//         {
//             q.push(make_pair(nums[i], i));
//             while (q.top().second <= i - k)
//                 q.pop();
//             ans.push_back(q.top().first);
//         }
//         return ans;
//     }
// };

// 双端队列（单调队列）

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// @lc code=end
