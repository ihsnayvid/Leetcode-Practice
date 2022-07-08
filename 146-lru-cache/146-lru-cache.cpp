class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int k, int v){
            key = k;
            val = v;
        }
       
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(node* n){
        node* temp = head->next;
        n->next = temp;
        n->prev = head;
        head->next = n;
        temp->prev = n;                
    }
        
    void del(node* n){
        node* delprev = n->prev;
        node* delnext = n->next;
        delprev->next = delnext;
        delnext->prev = delprev;        
    }    
    
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* n = mp[key];
            int ans = n->val;
            mp.erase(key);
            del(n);
            add(n);
            mp[key] = head->next;
            return ans;
        }
 
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* exist = mp[key];
            mp.erase(key);
            del(exist);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */