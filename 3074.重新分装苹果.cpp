/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 *
 * [3074] 重新分装苹果
 */

// @lc code=start
class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int box = 0;
        for (int &cap : capacity)
        {
            sum -= cap;
            box++;
            if (sum <= 0)
                break;
        }
        return box;
    }
};
// @lc code=end
