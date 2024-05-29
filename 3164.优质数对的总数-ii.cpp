/*
 * @lc app=leetcode.cn id=3164 lang=cpp
 *
 * [3164] 优质数对的总数 II
 */

// @lc code=start

// 统计因子

// class Solution
// {
// public:
//     long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
//     {
//         unordered_map<int, int> cnt; // 统计因子的出现次数
//         for (int &x : nums1)
//             for (int i = 1; i * i <= x; i++)
//                 if (x % i == 0)
//                 {
//                     cnt[i]++;
//                     if (i * i < x)
//                         cnt[x / i]++;
//                 }

//         long long ans = 0LL;
//         for (int &x : nums2)
//             if (cnt.contains(x * k))
//                 ans += cnt[x * k];
//         return ans;
//     }
// };

// 枚举倍数

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> cnt1; // 统计 nums1[i] / k 的出现次数
        for (int &x : nums1)
            if (x % k == 0)
                cnt1[x / k]++;
        if (cnt1.empty())
            return 0LL;
        unordered_map<int, int> cnt2; // 统计nums2[i] 的出现次数
        for (int &x : nums2)
            cnt2[x]++;

        long long ans = 0LL;
        int u = ranges::max_element(cnt1)->first;

        for (auto &[i, c] : cnt2)
        {
            int s = 0;
            for (int j = i; j <= u; j += i)
                if (cnt1.contains(j))
                    s += cnt1[j];
            ans += (long long)s * c;
        }
        return ans;
    }
};
// @lc code=end
