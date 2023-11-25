

typedef struct CacheNode {
    int32_t key = 0;
    int32_t val = 0;
    CacheNode* prev = NULL;
    CacheNode* next = NULL;
} CacheNode;


class LRUCache {
private:
    CacheNode* cache_head = NULL;
    CacheNode* cache_tail = NULL;
    std::map<int32_t, CacheNode*> cache = {};
    int32_t capacity = 0;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void print_cache() {
        printf("cache: ");
        for (const auto& x : this->cache) {
            printf("%i=%i ", x.second->key, x.second->val);
            assert(x.first == x.second->key);
        }
        printf("\n");
    }
    
    int get(int key) {
        int32_t out = -1;
        //this->print_cache();
        if (this->cache.find(key) != this->cache.end()) {
            out = this->cache[key]->val;
        }
        printf("get key=%i, val=%i\n", key, out);
        return out;
    }
    
    void put(int key, int value) {
        CacheNode* node = NULL;
        int32_t cache_size = static_cast<int32_t>(this->cache.size());
        if (cache_size == 0) {
            node = new CacheNode({key, value, NULL, NULL});
            this->cache_head = node;
            this->cache_tail = node;
            this->cache[key] = node;
        } else if (this->cache.find(key) == this->cache.end()) {
            node = new CacheNode({key, value, NULL, NULL});
            node->next = this->cache_head;
            this->cache_head = node;
            this->cache[key] = node;
        } else {
            node = this->cache[key];
            node->val = value;
            if (node != this->cache_head) {
                node->prev->next = node->next;
                node->next = this->cache_head;
                this->cache_head = node;
            }
        }
        if (cache_size > this->capacity) {
            this->cache_tail = this->cache_tail->prev;
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
