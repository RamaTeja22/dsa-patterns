// Constructor inside Struct
// right to left like manga, recent at right
// new Node returns the address reference of theb created Node.

struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key_,int val_){
        key=key_;
        value=val_;
        prev=nullptr;
        next=nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>al;
    LRUCache(int _capacity) {
        capacity=_capacity;
        al.clear();
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){
        Node* before = node->prev;
        Node* after = node->next;
        node->next=nullptr;
        node->prev=nullptr;
        before->next=after;
        after->prev=before;
    }

    void insertAfterHead(Node* node){
        Node* afterHead = head->next;
        head->next=node;
        node->next=afterHead;
        afterHead->prev=node;
        node->prev=head;
    }
    
    int get(int key) {
        if(al.find(key)==al.end()){
            return -1;
        }
        Node* cc=al[key];
        deleteNode(cc);
        insertAfterHead(cc);
        return cc->value;
    }
    
    void put(int key, int value) {
        if(al.find(key)!=al.end()){
            Node* cc=al[key];
            cc->value=value;
            deleteNode(cc);
            insertAfterHead(cc);
            return;
        }
        if(al.size()==capacity){
            Node* toBeDeleted=tail->prev;
            int toBeDeletedKey=toBeDeleted->key;
            al.erase(toBeDeletedKey);
            deleteNode(toBeDeleted);
        }
        Node* newNode = new Node(key,value);
        al[key]=newNode;
        insertAfterHead(newNode);
    }
};
