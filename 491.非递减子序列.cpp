/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

    // 辅函数 - 回溯
    void backtrace(vector<int> &arr, int startIdx)
    {
        if (path.size() >= 2)
            res.push_back(path);

        unordered_set<int> hashSet;
        for (int i = startIdx; i < arr.size(); i++)
        {
            if ((!path.empty() && arr[i] < path.back()) || hashSet.count(arr[i]))
                continue;

            hashSet.insert(arr[i]);
            path.push_back(arr[i]);
            backtrace(arr, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrace(nums, 0);
        return res;
    }
};
// @lc code=end
