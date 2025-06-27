class LRUCache {
public:
    class Node{
    public:
        int val;
        int key;
        Node* next;
        Node* prev;
    };
private:
    int cap;
    int csize;
    unordered_map<int, Node*> lru;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) : cap(capacity), csize(0) {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    void deleteLast() {
        Node* temp = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        lru[temp->key] = nullptr;
        delete temp;
    }

    void addNewNode(int key, int value) {
        lru[key] = new Node;
        lru[key]->val = value;
        lru[key]->key = key;
    }

    void moveFront(int key) {
        lru[key]->next = head->next;
        lru[key]->prev = head;
        head->next->prev = lru[key];
        head->next = lru[key];
    }

    void fixConnection(int key) {
        lru[key]->prev->next = lru[key]->next;
        lru[key]->next->prev = lru[key]->prev;
    }
    
    int get(int key) {
        if(lru[key] != nullptr) {
            fixConnection(key);
            moveFront(key);
            return lru[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(head->next == nullptr) { // base case - empty lru
            addNewNode(key, value);
            ++csize;
            return;
        }

        if(lru[key] != nullptr) { // if node exists
            lru[key]->val = value;
            fixConnection(key);
            moveFront(key);
        }
        else {                    // node doesn't exist
            if(csize >= cap) {    // full LRU
                deleteLast();
                addNewNode(key, value);
                moveFront(key);
            }
            else {                // LRU has space
                addNewNode(key, value);
                moveFront(key);
                ++csize;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
