/*
 * @lc app=leetcode.cn id=3134 lang=cpp
 *
 * [3134] 找出唯一性数组的中位数
 */

// @lc code=start
class Solution
{
public:
    int medianOfUniquenessArray(vector<int> &nums)
    {
        int n = nums.size();
        long long k = ((long long)n * (n + 1) / 2 + 1) / 2;

        auto check = [&](int upper)
        {
            long long cnt = 0;
            int l = 0;
            unordered_map<int, int> freq;
            for (int r = 0; r < n; r++)
            {
                freq[nums[r]]++;
                while (freq.size() > upper)
                {
                    int out = nums[l++];
                    freq[out]--;
                    if (freq[out] == 0)
                        freq.erase(out);
                }
                cnt += r - l + 1;
                if (cnt >= k)
                    return true;
            }
            return false;
        };

        int left = 0, right = n;
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
// @lc code=end
