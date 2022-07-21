class Skiplist {
public:
    struct Node
    {
        int val;
        Node(){}
        Node(int val){  this->val = val;}
        vector<Node*> next;//next[t] points to the next element in the t-th layer
    };

    void append(Node* prev, int layer, Node* node)
    {
        while(node->next.size() <= layer)  node->next.push_back(NULL);
        node->next[layer] = prev->next[layer];
        prev->next[layer] = node;
    }

    bool search(Node* prev, int i,int target)
    {
        while(prev->next[i] != NULL && prev->next[i]->val < target)   prev = prev->next[i];
        if(prev->next[i] != NULL && prev->next[i]->val == target) return true;
        if(i > 0)   return search(prev,i-1,target);
        return false;
    }

    bool add(Node *prev, int i, Node *node)
    {
        int val = node->val;
        while(prev->next[i] != NULL && prev->next[i]->val < val)   prev = prev->next[i];
        if(i == 0 || add(prev,i-1,node) && rand()%2 == 1){
            append(prev,i,node);
            return true;
        }else   return false;
    }

    bool erase(Node *prev, int i, int val)
    {
        while(prev->next[i] != NULL && prev->next[i]->val < val)   prev = prev->next[i];
        if(i > 0 && erase(prev,i-1,val) == true)    return true;
        if(prev->next[i] != NULL && prev->next[i]->val == val)
        {
            Node* node = prev->next[i];
            prev->next[i] = node->next[i];
            if(node->next.size() == i+1)
            {
                delete node;
                return true;
            }
        }
        return false;
    }

    Node* head;

    Skiplist() {
        const int INF = 0x3f3f3f3f;
        head = new Node(-INF);
        head->next.resize(50);
    }

    bool search(int target) {
        // printf("search(%d)\n",target);
        int layers = head->next.size();
        return search(head, layers-1,target);
        return false;
    }

    void add(int num) {
        // printf("add(%d)\n",num);
        int layers = head->next.size();
        add(head, layers-1,new Node(num));
        // assert(add(head, layers-1,new Node(num))==false);
    }

    bool erase(int num) {
        // printf("erase(%d)\n",num);
        int layers = head->next.size();
        return erase(head,layers-1,num);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
