class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            deleteNode(node);
            node->value = value;
            addNode(node);
            return;
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            Node* prevNode = tail->prev;
            deleteNode(prevNode);
            delete prevNode;
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};
