/*
 * @lc app=leetcode.cn id=3072 lang=cpp
 *
 * [3072] 将元素分配到两个数组中 II
 */

// @lc code=start
class Fenwick
{
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    // 把下标为 i 的元素增加 1
    void add(int i)
    {
        while (i < tree.size())
        {
            tree[i]++;
            i += i & -i;
        }
    }

    // 返回下标在 [1,i] 的元素之和
    int pre(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<int> a{nums[0]}, b{nums[1]};
        Fenwick t1(m + 1), t2(m + 1);
        t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1);
        t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1);
        for (int i = 2; i < nums.size(); i++)
        {
            int x = nums[i];
            int v = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            int gc1 = a.size() - t1.pre(v); // greaterCount(a, v)
            int gc2 = b.size() - t2.pre(v); // greaterCount(b, v)
            if (gc1 > gc2 || gc1 == gc2 && a.size() <= b.size())
            {
                a.push_back(x);
                t1.add(v);
            }
            else
            {
                b.push_back(x);
                t2.add(v);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};
// @lc code=end
