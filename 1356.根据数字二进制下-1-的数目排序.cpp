/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const int &a, const int &b)
    {
        int countOneOfa = countOne(a), countOneOfb = countOne(b);
        if (countOneOfa == countOneOfb)
            return a < b;
        return countOneOfa < countOneOfb;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
    // 辅函数 - 计算 x 的二进制表示中数字 1 的数目
    static int countOne(int x)
    {
        int count = 0;
        while (x)
        {
            count += x % 2;
            x /= 2;
        }
        return count;
    }
};
// @lc code=end
