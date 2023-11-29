/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */

// @lc code=start
class SmallestInfiniteSet
{
private:
    set<int> s;
    int min_num = 1;

public:
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        if (s.empty())
            return min_num++;
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }

    void addBack(int num)
    {
        if (num < min_num)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
