/*
 * @lc app=leetcode.cn id=3066 lang=cpp
 *
 * [3066] 超过阈值的最少操作数 II
 */

// @lc code=start

// typedef long long LL;

// class Solution
// {
// public:
//     int minOperations(vector<int> &nums, int k)
//     {
//         priority_queue<LL, vector<LL>, greater<>> pq;
//         for (int &num : nums)
//             pq.push((LL)num);

//         int ans = 0;
//         while (pq.top() < k)
//         {
//             LL x = pq.top();
//             pq.pop();
//             LL y = pq.top();
//             pq.pop();
//             pq.push(min(x, y) * 2 + max(x, y));
//             ans++;
//         }
//         return ans;
//     }
// };

// 模拟（TLE）

// class Solution
// {
// public:
//     int minOperations(vector<int> &nums, int k)
//     {
//         vector<long long> LLnums;
//         for (int &num : nums)
//             LLnums.push_back((long long)num);
//         int count = 0;
//         while (*min_element(LLnums.begin(), LLnums.end()) < k && LLnums.size() >= 2)
//         {
//             sort(LLnums.begin(), LLnums.end());
//             // auto it = min_element(LLnums.begin(), LLnums.end());
//             // long long x = *it;
//             // LLnums.erase(it);
//             // it = min_element(LLnums.begin(), LLnums.end());
//             // long long y = *it;
//             // LLnums.erase(it);
//             long long x = LLnums[0], y = LLnums[1];
//             LLnums.erase(LLnums.begin());
//             LLnums.erase(LLnums.begin());
//             count++;
//             long long add = min(x, y) * 2 + max(x, y);
//             LLnums.push_back(add);
//         }
//         return count;
//     }
// };
// @lc code=end
