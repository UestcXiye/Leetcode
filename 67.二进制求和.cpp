/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0)
        {
            int sum = add;
            sum += i >= 0 ? a[i] - '0' : 0;
            sum += j >= 0 ? b[j] - '0' : 0;
            ans += to_string(sum % 2);
            add = sum / 2;
            i--;
            j--;
        }
        ans += add == 1 ? "1" : "";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
