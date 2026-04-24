#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Remove node from DLL
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (MRU position)
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        Node* node = m[key];
        int val = node->value;

        deleteNode(node);
        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existing = m[key];
            deleteNode(existing);
            m.erase(key);
        }

        if (m.size() == cap) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        m[key] = newNode;
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10

    cache.put(3, 30); // evicts key 2

    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30

    return 0;
}