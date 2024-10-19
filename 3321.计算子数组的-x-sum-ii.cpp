/*
 * @lc app=leetcode.cn id=3321 lang=cpp
 *
 * [3321] 计算子数组的 x-sum II
 */

// @lc code=start
class Solution
{
private:
    using pii = pair<int, int>; // 出现次数，元素值

public:
    vector<long long> findXSum(const vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        set<pii> L, R;
        long long sum_l = 0; // L 的元素和
        unordered_map<int, int> cnt;

        auto add = [&](int x)
        {
            pii p = {cnt[x], x};
            if (p.first == 0)
            {
                return;
            }
            if (!L.empty() && p > *L.begin())
            { // p 比 L 中最小的还大
                sum_l += (long long)p.first * p.second;
                L.insert(p);
            }
            else
                R.insert(p);
        };

        auto del = [&](int x)
        {
            pii p = {cnt[x], x};
            if (p.first == 0)
            {
                return;
            }
            auto it = L.find(p);
            if (it != L.end())
            {
                sum_l -= (long long)p.first * p.second;
                L.erase(it);
            }
            else
                R.erase(p);
        };

        auto l2r = [&]()
        {
            pii p = *L.begin();
            sum_l -= (long long)p.first * p.second;
            L.erase(p);
            R.insert(p);
        };

        auto r2l = [&]()
        {
            pii p = *R.rbegin();
            sum_l += (long long)p.first * p.second;
            R.erase(p);
            L.insert(p);
        };

        vector<long long> ans(n - k + 1);
        for (int r = 0; r < n; r++)
        {
            // 添加 in
            int in = nums[r];
            del(in);
            cnt[in]++;
            add(in);

            int l = r + 1 - k;
            if (l < 0)
                continue;

            // 维护大小
            while (!R.empty() && L.size() < x)
                r2l();
            while (L.size() > x)
                l2r();

            ans[l] = sum_l;

            // 移除 out
            int out = nums[l];
            del(out);
            cnt[out]--;
            add(out);
        }
        return ans;
    }
};
// @lc code=end
