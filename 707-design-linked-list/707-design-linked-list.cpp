class MyLinkedList {
public:
    
    struct ll{
        int val;
        ll *next;
        ll() : val(0), next(nullptr) {}
        ll(int x) : val(x), next(nullptr) {}        
    };
    
    ll *head;
    
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        ll *temp = head;
        int pos = 0;
        while(temp){
            if(pos == index) break;
            pos ++;
            temp = temp->next;
        }
        if(temp) return temp->val;
        return -1;
    }
    
    void addAtHead(int val) { 
        ll *node = new ll(val);
        node->next = head;
        head = node;            
    }
    
    void addAtTail(int val) {
        ll *node = new ll(val);
        if(!head) {
            head = node;
            return;
        }
        ll *temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = node;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        
        ll *node = new ll(val);
        ll *temp = head;
        int pos = 1;
        while(temp){
            if(pos == index) break;
            pos ++;
            temp = temp->next;        
        }
        if(temp){
            node->next = temp->next;
            temp->next = node;  
        }
        
    }
    
    void deleteAtIndex(int index) {
        ll *temp = head;
        if(index == 0){
            head = head->next;
            return;
        }
        
        int pos = 0;
        while(temp){
            if(pos == index-1) break;
            pos ++;
            temp = temp->next;
        }
        if(temp and temp->next)
            temp->next = temp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */