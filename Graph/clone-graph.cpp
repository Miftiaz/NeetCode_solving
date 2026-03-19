//link:https://neetcode.io/problems/clone-graph/question

/*

Main idea is to:
- copy the nodes (complete new copy)
- update the neighbor list of the newly created node.
- exact copy of the graph.

*/

/*

DFS
--------

We'll maintain a hashmap to see which nodes are already copied.
In every depth, if the node is visited (it's in the hashmap) return the node
                else, visit it and then call it's neighbors.

Visit:
1. create a new node using the node's values.
2. update the hashmap (mark the node as visited).
3. for every neighbors of the node call the function again and assign the neighbors to the copy nodes neighbors.
    (if they are visited they will return the nodes. else they will be visited and so on.)

*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map <Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew){
        if(node == nullptr) return nullptr;

        if(oldToNew.count(node)) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }
};

/*

BFS
-----

1. Use the map to denote which nodes are copied.
2. Copy the start node, add it to the queue.
3. until the queue is empty:
    i. get the front node (It's copied for sure as it was copied before being pushed in the queue)
    ii. for every neighbor of the current node, if they are not copied, copy them and push them in the queue.
                        At the same time, update the neighbor of the current node's copy node.
4. Return the start node's copy node.                    

*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        map <Node*, Node*> oldToNew;
        queue<Node*> q;

        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for(Node* nei : curr->neighbors){
                if(oldToNew.find(nei) == oldToNew.end()){
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[nei]);
            }
        }

        return oldToNew[node];
    }
};