/*
 * @lc app=leetcode.cn id=2949 lang=cpp
 *
 * [2949] 统计美丽子字符串 II
 */

// @lc code=start
class Solution
{
public:
    long long beautifulSubstrings(string s, int k)
    {
        int n = s.length();
        // 计算 k'
        k = mySqrt(4 * k);
        // <pair<i % k', preSum[i]>, 出现次数>
        map<pair<int, int>, int> cnt;
        cnt[make_pair(k - 1, 0)]++;
        // 前缀和
        int preSum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int bit = isVowels(s[i]) ? 1 : -1;
            preSum += bit;
            cnt[make_pair(i % k, preSum)];
            ans += cnt[make_pair(i % k, preSum)];
            cnt[make_pair(i % k, preSum)]++;
        }
        return ans;
    }
    int mySqrt(int n)
    {
        int res = 1;
        for (int i = 2; i * i <= n; i++)
        {
            int i2 = i * i;
            while (n % i2 == 0)
            {
                res *= i;
                n /= i2;
            }
            if (n % i == 0)
            {
                res *= i;
                n /= i;
            }
        }
        if (n > 1)
            res *= n;
        return res;
    }
    // 辅函数 - 判断字符 c 是否是元音字母
    bool isVowels(const char &c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};
// @lc code=end
