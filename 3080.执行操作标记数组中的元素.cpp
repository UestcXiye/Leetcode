/*
 * @lc app=leetcode.cn id=3080 lang=cpp
 *
 * [3080] 执行操作标记数组中的元素
 */

// @lc code=start
class Solution
{
public:
    vector<long long>
    unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        // ranges::stable_sort(ids, [&](int i, int j) { return nums[i] < nums[j]; });
        sort(ids.begin(), ids.end(), [&](const int i, const int j)
             { if (nums[i] != nums[j]) return nums[i] < nums[j];
                else return i < j; });
        vector<long long> ans;
        int idx = 0;
        for (vector<int> &query : queries)
        {
            int index = query[0], k = query[1];
            s -= nums[index];
            nums[index] = 0; // 标记
            for (; idx < n && k; idx++)
            {
                index = ids[idx];
                if (nums[index] > 0) // 未被标记
                {
                    s -= nums[index];
                    nums[index] = 0; // 标记
                    k--;
                }
            }
            ans.push_back(s);
        }

        return ans;
    }
};
// @lc code=end
