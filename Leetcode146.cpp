#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        auto it = map[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
        }

        cache.push_front({key, value});
        map[key] = cache.begin();

        if (cache.size() > capacity) {
            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);

    cout << cache.get(2) << endl; // -1

    cache.put(4, 4);

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}