class BrowserHistory {
public:
    struct Node
    {
        string data;
        Node *next, *prev;
        Node(string &d){ data = d; next = prev = nullptr; }
    };

    Node *cur;

    BrowserHistory(string homepage) {
        cur = new Node(homepage);
    }

    void visit(string url) {
        Node *n = new Node(url);
        cur->next = n, n->prev = cur;
        cur = n;
    }

    string back(int steps) {
        while(cur->prev && steps--) cur = cur->prev;
        return cur->data;
    }

    string forward(int steps) {
        while(cur->next && steps--) cur = cur->next;
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
