
   class MyLinkedList {
        struct node{
            int data;
            node* next;
            node(int x){
                data=x;
                next=NULL;
            }
        };
        node* head;
        int size;
        public:
        MyLinkedList(){
            head=NULL;
            size=0;
        }
    
    int get(int index) {
        node* temp=head;
        for(int i=0; temp!=NULL;i++){
            if(i==index)
            return temp->data;
            temp=temp->next;
        }
        return -1;
        
    }
    
    void addAtHead(int data) {
        node* newnode= new node(data);
        newnode->next=head;
        head=newnode;
        size++;
        
    }
    
    void addAtTail(int data) {
        node* newnode= new node(data);
        if(head==NULL){
            head = newnode;
        }
        else{
            node*temp=head;
            while (temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
        size++;
        
    }
    
    void addAtIndex(int index, int data) {
        if(index<0||index>size) return;
        if(index==0){
            addAtHead(data);
            return;
        }
        node* temp=head;
        for(int i=0;i<index-1;i++)
        temp=temp->next;
        node* newnode = new node(data);
        newnode->next=temp->next;
        temp->next=newnode;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size)return;
        node* temp =head;
        if(index==0){
            head=head->next;
        }
        else{
            for (int i=0;i<index-1;i++)
            temp=temp->next;
            node* del=temp->next;
            temp->next=del->next;
            delete del;
        } size--;    
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
