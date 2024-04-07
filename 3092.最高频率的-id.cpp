/*
 * @lc app=leetcode.cn id=3092 lang=cpp
 *
 * [3092] 最高频率的 ID
 */

// @lc code=start

// 哈希 + 有序集合

// class Solution
// {
// public:
//     vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
//     {
//         int n = nums.size();
//         unordered_map<int, long long> cnt;
//         multiset<long long> ms;
//         vector<long long> ans(n);

//         for (int i = 0; i < n; i++)
//         {
//             auto it = ms.find(cnt[nums[i]]);
//             if (it != ms.end())
//                 ms.erase(it);
//             cnt[nums[i]] += freq[i];
//             ms.insert(cnt[nums[i]]);
//             ans[i] = *(ms.rbegin());
//         }

//         return ans;
//     }
// };

// 哈希 + 懒删除堆

class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        int n = nums.size();
        unordered_map<int, long long> cnt;
        priority_queue<pair<long long, int>> pq;
        vector<long long> ans(n);

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            cnt[x] += freq[i];
            pq.push(make_pair(cnt[x], x));
            // 堆顶保存的数据已经发生变化，删除
            while (pq.top().first != cnt[pq.top().second])
                pq.pop();
            ans[i] = pq.top().first;
        }

        return ans;
    }
};
// @lc code=end
