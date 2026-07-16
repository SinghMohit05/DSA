#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        remove(node);
        insertFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insertFront(node);

        if (cache.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};