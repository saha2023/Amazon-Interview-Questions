//O(nlog*n)
class LRUCache {
int cap;
    unordered_map<int,pair<int,int>>mp;
    set<pair<int,int>>st;
    int seq = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            st.erase({mp[key].second, key});
            st.insert({++seq,key});
            mp[key].second = seq;
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mp.count(key)){
            st.erase({mp[key].second, key});
            st.insert({++seq,key});
            mp[key] = {val,seq};
        }
        else{
            if(st.size() == cap){
                auto it = st.begin();
                mp.erase(it->second);
                st.erase({it->first, it->second});
            }
            mp[key]={val,++seq};
            st.insert({seq,key});
        }
    }
};


//O(n) using dounly linked list
class DLL{
public:
    int key,value;
    DLL *right,*left;
    DLL(int key,int value){
        this->key=key;
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
class LRUCache {
public:
    DLL *head, *tail;
    int capacity,size;
    unordered_map<int, DLL*> m;
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        this->head=NULL;
        this->tail=NULL;
        
    }
    void delete_node(DLL *p){
        if(p->left!=NULL){
            p->left->right=p->right;
        }
        else{
            head=p->right;
        }
        if(p->right!=NULL){
            p->right->left=p->left;
            
        }
        else{
            tail=p->left;
        }
        p->left=NULL;
        p->right=NULL;
    }
    
    void insert(DLL *q){
       if (head == NULL) {
            head = tail = q;
        }
        else{
            tail->right = q;
            q->left = tail;
            tail = q;
        }

    }
    
    int get(int key) {
        if (m.find(key)==m.end())
            return -1;
        DLL *x=m[key];
        delete_node(x);
        insert(x);
        
        return x->value;
    }
    
    void put(int key, int value) {
        DLL *y = new DLL(key,value);
        if(m.find(key)!=m.end()){
            m[key]->value=value;
            delete_node(m[key]);
            insert(m[key]);
        }
        else{
            m[key]=y;
            if(size==capacity){
                m.erase(head->key);//remove the least recently used value from map
                delete_node(head);
                insert(y);
            }
            else{
                size+=1;//size of window increase
                insert(y);
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