class MyCircularDeque {
public:
    struct Node
    {
        int data;
        Node *next, *prev;
        Node(int d, Node *n = nullptr, Node *p = nullptr){ data = d; next = n; prev = p; }
    };

    Node *head; // dummy head node with size info
    int maxSize;

    MyCircularDeque(int k) {
        head = new Node(0);
        head->prev = head->next = head;
        maxSize = k;
    }

    bool insertFront(int dataue) {
        if(isFull()) return false;

        Node *n = new Node(dataue, head->next, head);
        head->next->prev = n;
        head->next = n;
        head->data++;

        return true;
    }

    bool insertLast(int dataue) {
        if(isFull()) return false;

        Node *n = new Node(dataue, head, head->prev);
        head->prev->next = n;
        head->prev = n;
        head->data++;

        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;

        Node *n = head->next;
        head->next = n->next;
        n->next->prev = head;
        delete n;
        head->data--;

        return true;
    }

    bool deleteLast() {
        if(isEmpty()) return false;

        Node *n = head->prev;
        head->prev = n->prev;
        n->prev->next = head;
        delete n;
        head->data--;

        return true;
    }

    int getFront() {
        if(isEmpty()) return -1;
        else return head->next->data;
    }

    int getRear() {
        if(isEmpty()) return -1;
        else return head->prev->data;
    }

    bool isEmpty() {
        return !head->data;
    }

    bool isFull() {
        return head->data == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(dataue);
 * bool param_2 = obj->insertLast(dataue);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
