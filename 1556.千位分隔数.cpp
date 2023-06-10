/*
 * @lc app=leetcode.cn id=1556 lang=cpp
 *
 * [1556] 千位分隔数
 */

// @lc code=start
class Solution
{
public:
    string thousandSeparator(int n)
    {
        int count = 0;
        string ans;
        do
        {
            int cur = n % 10;
            n /= 10;
            ans += to_string(cur);
            count++;
            if (count % 3 == 0 && n)
                ans += '.';
        } while (n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
