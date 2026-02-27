//link: https://neetcode.io/problems/lru-cache/question

/*

To make things easier, we made a Node class.
Every node class will have
- a key
- a value,
- a previous node
- a next node
In the class we defined a constructor creating a double list with one node (so, prev, next = null pointer). 
We made all these public so that outside Node, values can be modified

The main LRUCache will have-
- a capacity 
- a hash map to store the keys and the pointer to the node having the key and corresponding value
- a dummy left node (0,0)
- a dummy right node (0,0)
- two private functions insert, remove,
- two public functions put, get, put
- a constructor 

Insert function simply inserts a node before the right dummy node in the double linked list. As it's the most recently used.

Remove function simply removes the node from the double linked list from any place.

The constructor-
1. Gets the capacity and make it the attribute cap.
2. Clears the cache (the hash map) as no node is there.
3. Simply connects the left dummy pointer with the right dummy pointer in both direction.

The get function- 
1. If the key already exists in the cache, 
    - simply delete the node from the list using remove function.
    - insert the node before the right dummy node using the insert function.
        This deletion and insertion simply moves the node to the designated position.
    - return the value of the node.
2. If the key doesn't exist, return -1;

The put function-
1. If it exists in the list, we delete it.
2. Insert the node in the last.
3. update the pointer to this node where it's inserted.
4. If capacity exceeds, 
    - delete the node after the left dummy node.
    - remove the key from the cache.
    - delete the instance of the node.
*/

class Node {
public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map <int, Node*> cache;
    Node* left = new Node (0, 0);;
    Node* right = new Node (0, 0);;

    void insert(Node* node) {
        Node* prv = right->prev;
        node->prev = prv;
        node->next = right;
        right->prev = node;
        prv->next = node;
    }

    void remove(Node* node) {
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv; 
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if(cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

