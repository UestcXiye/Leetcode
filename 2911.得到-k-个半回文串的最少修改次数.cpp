/*
 * @lc app=leetcode.cn id=2911 lang=cpp
 *
 * [2911] 得到 K 个半回文串的最少修改次数
 */

// @lc code=start

// 预处理每个数的真因子，时间复杂度 O(MX * log(MX))
const int MX = 201;
vector<vector<int>> divisors(MX);
int init = []
{
    for (int i = 1; i < MX; i++)
        for (int j = i * 2; j < MX; j += i)
            divisors[j].push_back(i);
    return 0;
}();

class Solution
{
public:
    int minimumChanges(string s, int k)
    {
        int n = s.size();
        vector<vector<int>> modify(n - 1, vector<int>(n));
        for (int left = 0; left < n - 1; left++)
            for (int right = left + 1; right < n; right++)
            {
                string subStr = s.substr(left, right - left + 1);
                modify[left][right] = get_modify(subStr);
            }
        vector<vector<int>> memo(k, vector<int>(n, n + 1)); // n+1 表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i == 0)
                return modify[0][j];
            int &res = memo[i][j]; // 注意这里是引用
            if (res <= n)
            { // 之前计算过
                return res;
            }
            for (int L = i * 2; L < j; L++)
                res = min(res, dfs(i - 1, L - 1) + modify[L][j]);
            return res;
        };
        return dfs(k - 1, n - 1);
    }
    // 辅函数 - 计算字符串 s 变成半回文串需要修改的字符数目
    int get_modify(string s)
    {
        int n = s.size(), res = n;
        for (int d : divisors[n])
        {
            int cnt = 0;
            for (int i0 = 0; i0 < d; i0++)
                for (int i = i0, j = n - d + i0; i < j; i += d, j -= d)
                    cnt += s[i] != s[j];
            res = min(res, cnt);
        }
        return res;
    }
};
// @lc code=end
