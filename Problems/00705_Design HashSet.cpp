class MyHashSet {
public:
    // coaleased chaining
    struct Node
    {
        int data;
        Node *next;
        Node(int d, Node *n = nullptr){ data = d; next = n; }
    };

    int capacity;
    int MOD;
    vector<Node *> v;

    MyHashSet() {
        MOD = 1201;
        capacity = MOD;
        v.resize(capacity);
        fill(v.begin(), v.end(), nullptr);
    }

    inline int hashFn(int key)
    {
        return key % MOD;
    }

    void add(int key) {
        int pos = hashFn(key);
        Node *n = v[pos];
        while(n)
        {
            if(n->data == key) return;
            n = n->next;
        }

        n = new Node(key, v[pos]);
        v[pos] = n;
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

    bool contains(int key) {
        int pos = hashFn(key);
        Node *n = v[pos];
        while(n)
        {
            if(n->data == key) return true;
            n = n->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
