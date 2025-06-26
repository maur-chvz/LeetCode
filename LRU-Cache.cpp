class LRUCache {
private:
    int cap;
    int current_size;
    int frequency;
    unordered_map<int, pair<int, int>> lru; // pair<value, frequency>
public:
    LRUCache(int capacity) : cap(capacity), current_size(0), frequency(1) {
        
    }

    int get(int key) {
        if(lru[key].second > 0) {
            lru[key].second = frequency;
            frequency++;
            return lru[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lru[key].second > 0) { // if it exists 
                lru[key].first = value;
                lru[key].second = frequency;
                frequency++;
        }
        else { // don't exist
            if(current_size < cap) {  
                lru[key] = {value, frequency};
                frequency++;
                current_size++;
            }
            else { // if over capacity
                pair<int, int> min_v{0, frequency};
                for(const auto& [k, v]: lru) {
                    if(v.second != 0 && v.second < min_v.second) {
                        min_v.first = k;
                        min_v.second = v.second;
                    }
                }
                lru[min_v.first].second = 0; // value being replaced here
                lru[key].first = value;
                lru[key].second = frequency;
                frequency++;
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
