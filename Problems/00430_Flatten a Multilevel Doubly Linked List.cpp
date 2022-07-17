/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *helper(Node *head)
    {
        // returns the tail after flattening, as head doesnot change
        Node *tail = head, *hChild, *tChild, *tmp;
        while(head)
        {
            if(head->child)
            {
                hChild = head->child, tChild = helper(hChild);
                head->child = nullptr;
                tmp = head->next;
                head->next = hChild, hChild->prev = head;
                tChild->next = tmp; if(tmp) tmp->prev = tChild;

                head = tChild;
            }

            if(!head->next) return head;
            head = head->next;
        }

        return nullptr;
    }

    Node* flatten(Node* head) {
        if(!head) return nullptr;
        helper(head);
        return head;
    }
};
