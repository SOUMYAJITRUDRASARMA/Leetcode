class MyCircularQueue {
public:
    /* struct Node
    {
        int data;
        Node *next;
        Node(int d, Node *n = nullptr){ data = d; next = n; }
    };

    Node *head;
    int maxSize; */

    vector<int> v;
    int front, back, maxSize, curSize;

    MyCircularQueue(int k) {
        maxSize = k;
        v.resize(maxSize);
        curSize = front = 0;
        back = -1;

        /* head = nullptr;
        maxSize = k; */
    }

    bool enQueue(int value) {
        if(isFull()) return false;

        back = (back + 1) % maxSize;
        v[back] = value;
        curSize++;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;

        front = (front + 1) % maxSize;
        curSize--;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;

        return v[front];
    }

    int Rear() {
        if(isEmpty()) return -1;

        return v[back];
    }

    bool isEmpty() {
        return !curSize;
    }

    bool isFull() {
        return curSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
