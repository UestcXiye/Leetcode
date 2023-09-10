/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution
{
    vector<int> origin;

public:
    Solution(vector<int> &nums) : origin(std::move(nums)) {}
    // Solution(vector<int> &nums)
    // {
    //     origin.resize(nums.size());
    //     for (int i = 0; i < nums.size(); i++)
    //         origin[i] = nums[i];
    // }

    vector<int> reset()
    {
        return origin;
    }

    vector<int> shuffle()
    {
        if (origin.empty())
            return {};
        int n = origin.size();
        vector<int> shuffled(origin.begin(), origin.end());
        // 可以使用反向或者正向洗牌，效果相同
        // 反向洗牌：
        for (int i = n - 1; i >= 0; i--)
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        // 正向洗牌：
        // for (int i = 0; i < n; i++)
        // {
        //     int pos = rand() % (n - i);
        //     swap(shuffled[i], shuffled[i + pos]);
        // }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
