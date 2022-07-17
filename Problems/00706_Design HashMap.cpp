class MyHashMap {
public:
    // coaleased chaining
    struct Node
    {
        int data;
        int val;
        Node *next;
        Node(int d, int v, Node *n = nullptr){ data = d; val = v; next = n; }
    };

    int capacity;
    int MOD;
    vector<Node *> v;

    MyHashMap() {
        MOD = 1201;
        capacity = MOD;
        v.resize(capacity);
        fill(v.begin(), v.end(), nullptr);
    }

    inline int hashFn(int key)
    {
        return key % MOD;
    }

    void put(int key, int value) {
        int pos = hashFn(key);
        Node *n = v[pos];
        while(n)
        {
            if(n->data == key){ n->val = value; return; }
            n = n->next;
        }

        n = new Node(key, value, v[pos]);
        v[pos] = n;
    }

    int get(int key) {
        int pos = hashFn(key);
        Node *n = v[pos];
        while(n)
        {
            if(n->data == key) return n->val;
            n = n->next;
        }

        return -1;
    }

    void remove(int key) {
        int pos = hashFn(key);
        Node *n = v[pos], *m;
        if(!n) return;
        if(n->data == key){ v[pos] = n->next; delete n; return; }
        while(n->next)
        {
            if(n->next->data == key){ m = n->next; n->next = m->next; delete m; return; }
            n = n->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
