class MyLinkedList {
public:
    struct Node
    {
        int val;
        Node *next;
        Node(int v = 0, Node *n = nullptr){ val = v; next = n; }
    };

    Node *head, *tail;
    int curSize;

    MyLinkedList() {
        head = tail = nullptr;
        curSize = 0;
    }

    int get(int index) {
        if(index < 0 || index >= curSize) return -1;
        Node *n = head;
        while(index--) n = n->next;
        return n->val;
    }

    void addAtHead(int val) {
        Node *n = new Node(val, head);
        if(!head) head = tail = n;
        else head = n;
        curSize++;
    }

    void addAtTail(int val) {
        Node *n = new Node(val);
        if(!head) head = tail = n;
        else tail->next = n, tail = n;
        curSize++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > curSize) return;

        if(index == 0) addAtHead(val);
        else if(index == curSize) addAtTail(val);
        else
        {
            Node *n = new Node(val), *prev = head;
            while(--index) prev = prev->next;
            n->next = prev->next;
            prev->next = n;
            curSize++;
        }
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= curSize) return;

        if(index == 0) head = head->next;
        else
        {
            Node *prev = head;
            while(--index) prev = prev->next;
            if(prev->next == tail) tail = prev;
            prev->next = prev->next->next;
        }

        curSize--;
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
