// using map
class Solution {
private:
    map<Node*, Node*>mp;
    Node *getNode(Node* curr){
        if(!curr) return NULL;
        if(mp.count(curr)){
            return mp[curr];
        }
        else{
            mp[curr] = new Node(curr->val);
            return mp[curr];
        }
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *oldNode = head;
        Node *newNode = new Node(head->val);
        mp[oldNode] = newNode;
        while(oldNode){
            newNode->next = getNode(oldNode->next);
            newNode->random = getNode(oldNode->random);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return mp[head];
    }
};


//without using extra space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* ptr = head;
        while (ptr != NULL) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }

        ptr = head;

        while (ptr != NULL) {
            ptr->next->random = ptr->random == NULL ?  NULL : ptr->random->next;
            ptr = ptr->next->next;
        }

        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next; 
        Node* head_old = head->next;
        while (ptr_old_list != NULL) {
            ptr_old_list->next = ptr_old_list->next->next;
            ptr_new_list->next = (ptr_new_list->next != NULL) ? ptr_new_list->next->next : NULL;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_old;
    }
};