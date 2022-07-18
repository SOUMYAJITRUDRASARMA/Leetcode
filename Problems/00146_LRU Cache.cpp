class LRUCache {
// private:         // writing private is optional as class is by default private unless you mention public or protected access specifiers explicitly

    int capacity;   // object creation will instantiate capacity of the pages to be accomodated at a time
    list<int> pages;    // pages will store the current LRU window, whose front page will be MRU and back page will be the LRU
    unordered_map<int, pair<int, list<int>::iterator>> cache;   // hashmap storing the (key, pair<value, iterator_or_position_of_the_key_in_pages_list>)

// in LRU algorithm, list is going to be used like abstract front-end while most of the task will be done by the hashmap at the back-end

public:
    LRUCache(int capacity) {    // parameterized constructor i.e., every created object will require to pass capacity as a parameter
        this->capacity = capacity;
    }

    int get(int key) {      // function to retrieve page if it exists
        if(cache.find(key) != cache.end()){     // if the page is already exists
            pages.erase(cache[key].second);     // remove the page from position cache[key].second. Note here that list takes iterator (an address) instead of value for erasing the item that is why we are storing iterator in our cache hashmap
            pages.push_front(key);      // after removing, push it in the front of pages list to make it MRU page
            cache[key].second = pages.begin();  // also update the position/iterator for the key in cache hashmap
            return cache[key].first;    // return key's correspoding value. The value here is to be retrieved as the first of pair<value, list<int>::iterator>
        }

        return -1;      // else return -1 i.e., page not found
    }

    void put(int key, int value) {      // function to insert page
        if(cache.find(key) != cache.end()){     // when the page is already present
            pages.erase(cache[key].second);     // remove the page from position cache[key].second. Note here that list takes iterator instead of value for erasing the item that is why we are storing iterator in our cache hashmap
            pages.push_front(key);      // after removing, push it in the front of pages list to make it MRU page
            cache[key] = {value, pages.begin()};    // also update the value and position/iterator for the key in cache hashmap
        }
        else{       // when the page is not present
            if(pages.size() == capacity){   // and the pages list capacity is full
                cache.erase(pages.back());  // remove LRU page from cache hashmap. Note here that hashmap takes key (an integer) instead of iterator for erasing the item. The item that we want to remove here is the LRU which is nothing but at the back of the pages list
                pages.pop_back();           // remove LRU page/pages.back() from pages list
            }

            pages.push_front(key);      // after making a space for new page, just insert it into the front of pages list to make it MRU page
            cache[key] = {value, pages.begin()};    // also update the value and position/iterator for the key in cache hashmap
        }
    }
};



/* // How is this giving TLE ???
struct Node
{
    int data;
    struct Node *next;
    Node(int d){ data = d; next = nullptr; }
};

class LLQ
{
    // queue using LL and HMap
    public:
    Node *head, *tail; // ll used as queue | dummy head (size)
    unordered_map<int, Node *> m; // maps key to prev node for easier deletion

    LLQ()
    {
        Node *n = new Node(0);
        tail = head = n;
    }

    int size(){ return head->data; }

    Node *delAfterAndReturn(Node *n)
    {
        if(!n->next) return nullptr;
        if(n->next == tail) tail = n;
        Node *tmp = n->next;
        n->next = tmp->next;
        if(tmp->next) m[tmp->next->data] = n;
        tmp->next = nullptr;
        head->data--;
        m.erase(tmp->data);
        return tmp;
    }

    void push(int data)
    {
        tail->next = new Node(data);
        m[data] = tail;
        tail = tail->next;
        head->data++;
    }

    void push(Node *n)
    {
        n->next = nullptr;
        tail->next = n;
        m[n->data] = tail;
        tail = tail->next;
        head->data++;
    }

    int top()
    {
        return head->next->data;
    }

    void pop()
    {
        if(!head->next) return;
        Node *n = delAfterAndReturn(head); // cnt reduced here :)
        m.erase(n->data);
        delete n;
        // head->data--; // no need here
    }
};

class LRUCache {
    LLQ llq;
    int cap;
    unordered_map<int, int> mAct;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if(mAct.find(key) != mAct.end())
        {
            llq.push(llq.delAfterAndReturn(llq.m[key]));
            return mAct[key];
        }
        else return -1;
    }

    void put(int key, int value) {
        if(mAct.find(key) != mAct.end())
        {
            mAct[key] = value;
            llq.push(llq.delAfterAndReturn(llq.m[key]));
        }
        else
        {
            mAct[key] = value;
            if(llq.size() == cap){ int e = llq.top(); mAct.erase(e); llq.pop(); }
            llq.push(key);
        }
    }
}; */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
