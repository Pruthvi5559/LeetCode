//146. LRU Cache
class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    // Dummy head and tail nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Maximum cache capacity
    int cap;

    // Maps key to its corresponding node
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;

        // Initialize empty doubly linked list
        head->next = tail;
        tail->prev = head;
    }

    // Insert a node right after the head (Most Recently Used)
    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove a node from the doubly linked list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_) {

        // Key found in cache
        if (m.find(key_) != m.end()) {

            Node* resNode = m[key_];
            int res = resNode->val;

            // Move accessed node to the front (MRU)
            m.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            m[key_] = head->next;

            return res;
        }

        // Key not present
        return -1;
    }

    void put(int key_, int value) {

        // Remove existing node if key already exists
        if (m.find(key_) != m.end()) {
            Node* existingNode = m[key_];

            m.erase(key_);
            deleteNode(existingNode);
        }

        // Cache is full, remove Least Recently Used (LRU) node
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // Insert new node at the front (MRU)
        addNode(new Node(key_, value));
        m[key_] = head->next;
    }
};