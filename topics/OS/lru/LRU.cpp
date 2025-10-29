#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int capacity;
    list<int> usage; // Most recently used at front
    unordered_map<int, pair<int, list<int>::iterator>> cache; // cache[key] = {value, position_in_list}

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        // Move key to front
        usage.erase(it->second.second);
        usage.push_front(key);
        it->second.second = usage.begin();

        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // If key exists, erase old position
        if (it != cache.end()) {
            usage.erase(it->second.second);
        }
        // If new key and cache full, evict least used
        else if (cache.size() == capacity) {
            int lru = usage.back();
            usage.pop_back();
            cache.erase(lru);
        }

        // Insert at front
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }
};

int main() {
    LRUCache lru(3);
    lru.put(1, 10); 
    lru.put(2, 20);
    lru.put(3, 30);
    cout << lru.get(2) << "\n"; // 20
    lru.put(4, 40);             // Evicts 1
    cout << lru.get(1) << "\n"; // -1 (not found)
    cout << lru.get(3) << "\n"; // 30
}
