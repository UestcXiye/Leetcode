/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.length();
        vector<int> cnt(10, 0);
        int bulls = 0, cows = 0;
        // 第一次遍历，统计数字中有多少位属于数字和确切位置都猜对了
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
                cnt[secret[i] - '0']++;
        }
        // 第二次遍历，统计数字中有多少位属于数字猜对了但是位置不对
        for (int i = 0; i < n; i++)
            if (secret[i] != guess[i] && cnt[guess[i] - '0'] > 0)
            {
                cows++;
                cnt[guess[i] - '0']--;
            }
        // 提示的格式为 "xAyB"，x 是公牛个数，y 是奶牛个数，A 表示公牛，B 表示奶牛
        string ans;
        ans += to_string(bulls);
        ans.push_back('A');
        ans += to_string(cows);
        ans.push_back('B');
        return ans;
    }
};
// @lc code=end
