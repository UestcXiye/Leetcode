/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

// 哈希表 + 链表

// class LRUCache
// {
// private:
//     unordered_map<int, list<pair<int, int>>::iterator> hash;
//     // 链表的链接顺序即为最近使用的新旧顺序，最新的信息在链表头节点
//     list<pair<int, int>> cache;
//     int size;

// public:
//     LRUCache(int capacity) : size(capacity) {}

//     int get(int key)
//     {
//         auto it = hash.find(key);
//         if (it == hash.end())
//             return -1;
//         // 将 it->second 从 cache 剪切到 cache 的开头
//         cache.splice(cache.begin(), cache, it->second);
//         return it->second->second;
//     }

//     void put(int key, int value)
//     {
//         auto it = hash.find(key);
//         // 如果关键字 key 已经存在
//         if (it != hash.end())
//         {
//             // 变更其数据值 value
//             it->second->second = value;
//             // 将 it->second 从 cache 剪切到 cache 的开头
//             cache.splice(cache.begin(), cache, it->second);
//             return;
//         }
//         // 向缓存中插入该组 key-value
//         cache.insert(cache.begin(), make_pair(key, value));
//         hash[key] = cache.begin();
//         // 如果插入操作导致关键字数量超过 capacity
//         if (cache.size() > size)
//         {
//             // 逐出最久未使用的关键字
//             hash.erase(cache.back().first);
//             cache.pop_back();
//         }
//     }
// };

// 哈希表 + 自定义双向链表

class Node
{
public:
    int key, value;
    Node *prev, *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache
{
private:
    int capacity;
    Node *dummy; // 哨兵节点
    unordered_map<int, Node *> key_to_node;

    // 删除一个节点（抽出一本书）
    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 在链表头添加一个节点（把一本书放在最上面）
    void push_front(Node *x)
    {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key)
    {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) // 没有这本书
            return nullptr;
        auto node = it->second; // 有这本书
        remove(node);           // 把这本书抽出来
        push_front(node);       // 放在最上面
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key)
    {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value)
    {
        auto node = get_node(key);
        if (node)
        {                        // 有这本书
            node->value = value; // 更新 value
            return;
        }
        key_to_node[key] = node = new Node(key, value); // 新书
        push_front(node);                               // 放在最上面
        if (key_to_node.size() > capacity)
        { // 书太多了
            auto back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node); // 去掉最后一本书
            delete back_node;  // 释放内存
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
