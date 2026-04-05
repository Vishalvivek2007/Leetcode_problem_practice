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

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int ans = node->value;

        deleteNode(node);
        addNode(node); // move to front

        return ans;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};