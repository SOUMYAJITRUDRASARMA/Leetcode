# include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    struct Node
    {
        int val;
        Node *next, *prev;
        Node(int v, Node *n = nullptr, Node *p = nullptr){ val = v; next = n; prev = p; }
    };

    Node *head, *tail, *middle;

    FrontMiddleBackQueue() {
        // head has dummy node, containing size of list
        // middle points to previous node of current middle
        head = tail = middle = new Node(0);
    }

    inline void insertAfter(Node *p, Node *n)
    {
        n->next = p->next;
        if(p->next) p->next->prev = n;
        p->next = n;
        n->prev = p;
    }

    inline void deleteAfter(Node *p)
    {
        Node *n = p->next;

        p->next = n->next;
        if(n->next) n->next->prev = p;
        delete n;
    }

    void pushFront(int val) {
        Node *n = new Node(val);

        insertAfter(head, n);
        head->val++;
        if(head->val == 1) tail = tail->next;
        if(head->val == 2) middle = head->next; // here middle is at head, not shifted right
        else
        {
            // as head insertion means middle is shifted right
            if(head->val != 1 && head->val % 2 != 0) middle = middle->prev;
        }
    }

    void pushMiddle(int val) {
        Node *n = new Node(val);

        insertAfter(middle, n);
        head->val++;
        if(head->val == 1) tail = tail->next;
        if(head->val % 2 == 0) middle = middle->next;
    }

    void pushBack(int val) {
        Node *n = new Node(val);

        insertAfter(tail, n);
        tail = tail->next;
        head->val++;
        if(head->val % 2 == 0) middle = middle->next;
    }

    int popFront() {
        if(!head->val) return -1;

        int ans = head->next->val;
        if(head->val == 1) deleteAfter(head), middle = tail = head, head->val--;
        else if(head->val == 2) deleteAfter(head), middle = head, head->val--;
        else if(head->val == 3) deleteAfter(head), middle = head->next, head->val--;
        else
        {
            deleteAfter(head);
            head->val--;
            if(head->val % 2 == 0) middle = middle->next;
        }
        return ans;
    }

    int popMiddle() {
        if(!head->val) return -1;

        int ans = (head->val % 2 == 0)? middle->val: middle->next->val;
        if(head->val == 1) deleteAfter(head), middle = tail = head, head->val--;
        else if(head->val == 2) deleteAfter(head), middle = head, head->val--;
        else if(head->val == 3) deleteAfter(middle), head->val--;
        else
        {
            if(head->val % 2 != 0) deleteAfter(middle);
            else middle = middle->prev, deleteAfter(middle);
            head->val--;
        }
        return ans;
    }

    int popBack() {
        if(!head->val) return -1;

        int ans = tail->val;
        if(head->val == 1) deleteAfter(head), middle = tail = head, head->val--;
        else if(head->val == 2) tail = tail->prev, deleteAfter(tail), middle = head, head->val--;
        else if(head->val == 3) tail = tail->prev, deleteAfter(tail), head->val--;
        else
        {
            tail = tail->prev;
            deleteAfter(tail);
            head->val--;
            if(head->val % 2 == 1) middle = middle->prev;
        }
        return ans;
    }

    void display()
    {
        cout<<"head:  "<<head->val<<endl;
        cout<<"data:  ";
        for(Node *n = head->next;n;n=n->next) cout<<n->val<<", "; cout<<endl;
        cout<<"middle: "<<((middle == head)? "at head": to_string(middle->val))<<endl;
        cout<<"tail: "<<((tail == head)? "at head": to_string(tail->val))<<endl;
        cout<<endl<<endl;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main()
{
    FrontMiddleBackQueue q;

    cout<<"Initial -->"<<endl;
    q.display();

    for(int i=1;i<=10;i++)
    {
        // q.pushFront(i); cout<<"PushFront--> "<<i<<endl;
        // q.pushMiddle(i); cout<<"PushMiddle--> "<<i<<endl;
        q.pushBack(i); cout<<"PushBack--> "<<i<<endl;
        // q.display();
    }

    cout<<"\nAfter insertion -->"<<endl;
    q.display();

    int cnt = 10;
    while(cnt--)
    {
        // cout<<"#"<<(10 - cnt)<<" -->     "<<"PopFront = "<<q.popFront()<<endl;
        cout<<"#"<<(10 - cnt)<<" -->     "<<"PopMiddle = "<<q.popMiddle()<<endl;
        q.display();
    }

    return 0;
}
