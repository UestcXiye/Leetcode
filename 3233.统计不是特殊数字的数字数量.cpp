/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 *
 * [3233] 统计不是特殊数字的数字数量
 */

// @lc code=start
const int MX = 31622; // floor(sqrt(10^9))
bool inited = false;
vector<int> pi(MX + 5, 0);

// 埃氏筛 O(Mlog(logM))
void init()
{
    if (inited)
        return;
    for (int i = 2; i <= MX; i++)
    {
        if (pi[i] == 0)
        { // i 没有被标记，i 是质数
            pi[i] = pi[i - 1] + 1;
            for (int j = i * i; j <= MX; j += i)
            { // 标记 i 的倍数为合数
                pi[j] = -1;
            }
        }
        else
        {
            pi[i] = pi[i - 1];
        }
    }
    inited = true;
}

class Solution
{
public:
    int nonSpecialCount(int l, int r)
    {
        init();
        return r - l + 1 - (pi[(int)sqrt(r)] - pi[(int)sqrt(l - 1)]);
    }
};

// @lc code=end
