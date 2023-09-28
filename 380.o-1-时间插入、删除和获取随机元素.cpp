/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
private:
    vector<int> nums;                // 变长数组中存储元素
    unordered_map<int, int> indices; // 哈希表中存储每个元素在变长数组中的下标

public:
    RandomizedSet()
    {
        srand((unsigned)time(0));
    }

    bool insert(int val)
    {
        if (indices.count(val))
            return false;
        int index = nums.size();
        nums.push_back(val);
        indices[val] = index;
        return true;
    }

    bool remove(int val)
    {
        if (!indices.count(val))
            return false;
        // 从哈希表中获得 val 的下标 index
        int index = indices[val];
        int last = nums.back();
        // 将变长数组的最后一个元素 last 移动到下标 index 处
        nums[index] = last;
        // 在哈希表中将 last 的下标更新为 index
        indices[last] = index;
        // 在变长数组中删除最后一个元素
        nums.pop_back();
        // 在哈希表中删除 val
        indices.erase(val);
        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
