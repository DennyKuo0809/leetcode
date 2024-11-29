class LRUCache {
private:
    struct history{
        int k;
        int v;
        struct history* prev;
        struct history* next;
    };
    struct history *head = NULL, *tail = NULL;
    unordered_map<int, struct history*> m;
    int size;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key) != m.end() && m[key]){
            if(m[key] != head) {
                if(m[key] -> prev) m[key] -> prev -> next = m[key] -> next;
                if(m[key] -> next) m[key] -> next -> prev = m[key] -> prev;
                if(m[key] == tail) tail = m[key] -> prev;
                m[key] -> prev = NULL;
                m[key] -> next = head;
                head -> prev = m[key];
                head = m[key];
            }
            return m[key] -> v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end() && m[key]){
            m[key] -> v = value;
            
            if(m[key] != head) {
                if(m[key] -> prev) m[key] -> prev -> next = m[key] -> next;
                if(m[key] -> next) m[key] -> next -> prev = m[key] -> prev;
                if(m[key] == tail) tail = m[key] -> prev;
                m[key] -> prev = NULL;
                m[key] -> next = head;
                head -> prev = m[key];
                head = m[key];
            }
        }
        else{
            size ++;
            m[key] = new struct history;
            m[key] -> k = key;
            m[key] -> v = value;
            m[key] -> prev = m[key] -> next = NULL;
            if(!head) head = tail = m[key];
            else{
                if(size > cap){
                    m[tail -> k] = NULL;
                    tail = tail -> prev;
                    if(tail) tail -> next = NULL;
                    else head = NULL;
                    size --;
                }
                m[key] -> next = head;
                if(head) head -> prev = m[key];
                else tail = m[key];
                head = m[key];
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
