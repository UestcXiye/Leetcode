/*
 * @lc app=leetcode.cn id=2333 lang=cpp
 *
 * [2333] 最小差值平方和
 */

// @lc code=start
class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size(), k = k1 + k2;
        long long ans = 0LL, sum = 0LL;
        vector<int> abs_diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            abs_diff[i] = abs(nums1[i] - nums2[i]);
            sum += abs_diff[i];
            ans += (long long)abs_diff[i] * abs_diff[i];
        }
        // 特判
        if (sum <= k)
            return 0;
        if (k == 0)
            return ans;
        sort(abs_diff.begin(), abs_diff.end(), greater<int>());
        abs_diff.push_back(0); // 哨兵
        for (int i = 0;; i++)
        {
            long j = i + 1, v = abs_diff[i], c = j * (v - abs_diff[j]);
            ans -= v * v;
            if (c < k)
            {
                k -= c;
                continue;
            }
            v -= k / j;
            return ans + k % j * (v - 1) * (v - 1) + (j - k % j) * v * v;
        }
    }
};
// @lc code=end
