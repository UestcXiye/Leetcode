/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache
{
private:
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    // 链表的链接顺序即为最近使用的新旧顺序，最新的信息在链表头节点
    list<pair<int, int>> cache;
    int size;

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        // 将 it->second 从 cache 剪切到 cache 的开头
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        // 如果关键字 key 已经存在
        if (it != hash.end())
        {
            // 变更其数据值 value
            it->second->second = value;
            // 将 it->second 从 cache 剪切到 cache 的开头
            return cache.splice(cache.begin(), cache, it->second);
        }
        // 向缓存中插入该组 key-value
        cache.insert(cache.begin(), make_pair(key, value));
        hash[key] = cache.begin();
        // 如果插入操作导致关键字数量超过 capacity
        if (cache.size() > size)
        {
            // 逐出最久未使用的关键字
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
