class AllOne {
    set<pair<int, string>> st;
    map<string,int> table;
public:
    AllOne() {

    }

    void inc(string key) {
        if(table.count(key))
            st.erase({table[key], key});
        st.insert({++table[key], key});
    }

    void dec(string key) {
        st.erase({table[key], key});
        if(--table[key])
            st.insert({table[key], key});
    }

    string getMaxKey() {
        return st.empty() ? "":st.rbegin()->second;
    }

    string getMinKey() {
        return st.empty() ? "":st.begin()->second;
    }
};

/* Other Soln (in JAVA) -->
class AllOne {
    private static class Node {
        String key;
        int count;
        Node previous;
        Node next;

        public Node(String key, int count) {
            this.key = key;
            this.count = count;
        }

        public String toString() {
            return key + "-" + count;
        }
    }

    public static class DoublyLinkedList {
        Node head;
        Node tail;

        public Node add(String key, int count) {
            Node newNode = new Node(key, count);
            if (head == null) {
                head = tail = newNode;
            } else {
                newNode.previous = tail;
                tail.next = newNode;
                tail = newNode;
            }
            return tail;
        }

        public Node removeNode(Node nodeToRemove) {
            if (nodeToRemove == null)
                return null;

            if (nodeToRemove == head) {
                head = head.next;
            } else if (nodeToRemove == tail) {
                tail = tail.previous;
            } else {
                nodeToRemove.previous.next = nodeToRemove.next;
                nodeToRemove.next.previous = nodeToRemove.previous;
            }
            nodeToRemove.previous = null;
            nodeToRemove.next = null;
            return nodeToRemove;
        }

        public Node addToHead(Node node) {
            if (head == null) {
                head = tail = node;
            } else {
                node.next = head;
                head.previous = node;
                head = node;
            }
            return head;
        }

        public Node addNextToHead(Node node) {
            node.previous = head;
            node.next = head.next;
            head.next.previous = node;
            head.next = node;
            return node;
        }

        public boolean isEmpty() {
            return head == null && tail == null;
        }
    }

    private final Map<String, Node> keyToNode;
    private final DoublyLinkedList nodes;
    private int maxKey;


    public AllOne() {
        keyToNode = new HashMap<>();
        nodes = new DoublyLinkedList();
        maxKey = 1;
    }

    public void inc(String key) {
        if (keyToNode.containsKey(key)) {
            Node node = keyToNode.get(key);
            node.count += 1;
            if (node.count > maxKey) {
                maxKey = node.count;
                keyToNode.put(key, nodes.addToHead(nodes.removeNode(node)));
            } else if (node.count == maxKey) {
                keyToNode.put(key, nodes.addNextToHead(nodes.removeNode(node)));
            }
        } else {
            Node node = nodes.add(key, 1);
            keyToNode.put(key, node);
        }
    }

    public void dec(String key) {
        Node node = keyToNode.get(key);
        node.count -= 1;
        if (node == nodes.head)
            maxKey = node.count;

        if (node.count <= nodes.tail.count) {
            Node removedNode = nodes.removeNode(node);
            if (node.count == 0) {
                keyToNode.remove(key);
                return;
            }
            keyToNode.put(key, nodes.add(removedNode.key, removedNode.count));
        }
    }

    public String getMaxKey() {
        return nodes.isEmpty() ? "" : nodes.head.key;
    }

    public String getMinKey() {
        return nodes.isEmpty() ? "" : nodes.tail.key;
    }
} */

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
