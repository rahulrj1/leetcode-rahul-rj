class LFUCache {
private:    
    class node{
        public:
        int key, val, freq;
        node(int k, int v) {
            key = k; val  = v; freq = 1;
        }
    };
    unordered_map<int, list<node>::iterator> cache; //stores list iterator for a key
    map<int, list<node>> freqs; // stores list for a freq
    int cap;
    void createNewNode(int key, int value) {
        freqs[1].push_front({key,value});
        cache[key] = freqs[1].begin();
    }
    void deleteLFU() {
        auto it = freqs.begin();
        int freq = it->first;
        cache.erase(freqs[freq].back().key);
        freqs[freq].pop_back();
        if(freqs[freq].empty()) freqs.erase(freq);
    }
    void updateNodeFreq(list<node>:: iterator it) {
        auto node  = *it;
        freqs[node.freq].erase(it);
        if (freqs[node.freq].empty()) {
            freqs.erase(node.freq);
        }
        node.freq ++; 
        freqs[node.freq].push_front(node);
        cache[node.key] = freqs[node.freq].begin();
    }
    
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it != cache.end()) {
            int v = it->second->val;
            updateNodeFreq(it->second);
            return v;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) {
            it->second->val = value;
            updateNodeFreq(it->second);
        }
        else if(cap != 0) {
            if(cache.size() == cap) deleteLFU();
            createNewNode(key, value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */