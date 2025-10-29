#include <iostream>
#include <cstring> // For memset

using namespace std;

// Node for Doubly Linked List
struct Node {
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// Entry for hash table (chaining)
struct Entry {
    int key;
    Node* node;
    Entry* next;
    Entry(int k, Node* n) : key(k), node(n), next(nullptr) {}
};

// Hash table size (prime for better distribution)
const int TABLE_SIZE = 1009;
Entry* table[TABLE_SIZE];

// Hash function
int hashFunc(int key) {
    return key % TABLE_SIZE;
}

// LRU Cache class
class LRUCache {
    int capacity, size;
    Node *head, *tail; // Head = most recent, Tail = least recent

public:
    LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr) {
        memset(table, 0, sizeof(table));
    }

    // Add node to front
    void addToFront(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    }

    // Remove node
    void removeNode(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }

    // Move node to front (mark as recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    // Hash table: get node by key
    Node* getFromTable(int key) {
        int h = hashFunc(key);
        Entry* e = table[h];
        while (e) {
            if (e->key == key) return e->node;
            e = e->next;
        }
        return nullptr;
    }

    // Hash table: put key-node
    void putInTable(int key, Node* node) {
        int h = hashFunc(key);
        Entry* e = new Entry(key, node);
        e->next = table[h];
        table[h] = e;
    }

    // Hash table: delete key
    void deleteFromTable(int key) {
        int h = hashFunc(key);
        Entry* e = table[h];
        Entry* prev = nullptr;
        while (e) {
            if (e->key == key) {
                if (prev) prev->next = e->next;
                else table[h] = e->next;
                delete e;
                return;
            }
            prev = e;
            e = e->next;
        }
    }

    // Get value
    int get(int key) {
        Node* node = getFromTable(key);
        if (!node) return -1;
        moveToFront(node);
        return node->value;
    }

    // Put key-value
    void put(int key, int value) {
        Node* node = getFromTable(key);
        if (node) {
            node->value = value;
            moveToFront(node);
            return;
        }

        if (size == capacity) {
            // Remove least recently used
            deleteFromTable(tail->key);
            removeNode(tail);
            delete tail;
            size--;
        }

        Node* newNode = new Node(key, value);
        addToFront(newNode);
        putInTable(key, newNode);
        size++;
    }

    // Debug print
    void printCache() {
        Node* curr = head;
        cout << "Cache: ";
        while (curr) {
            cout << "[" << curr->key << ":" << curr->value << "] ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

// ---------------- Main ----------------

int main() {
    LRUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cache.printCache(); // 3 2 1

    cout << "get(2): " << cache.get(2) << "\n"; // 200
    cache.printCache(); // 2 3 1

    cache.put(4, 400);  // evicts key 1
    cache.printCache(); // 4 2 3

    cout << "get(1): " << cache.get(1) << "\n"; // -1
    cout << "get(3): " << cache.get(3) << "\n"; // 300
    cache.printCache(); // 3 4 2

    return 0;
}
