/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) { 
        if(!node) return node;
        // bfs 
        queue<Node*> q;
        q.push(node);

        unordered_map<Node*, Node*> m;
        Node* newNode = new Node(node->val);
        m[node] = newNode;

// all nodes in queue has copies alrd created

        while(!q.empty()){
            auto n  = q.front();
            q.pop();

            
            for(auto adj: n->neighbors){
                // if copy not exist for neignours 
                if(m.find(adj)== m.end()){
                    Node* newNeighbour = new Node(adj->val);
                    newNeighbour->neighbors.push_back(m[n]);
                    q.push(adj);
                    m[adj] = newNeighbour;


                }
                else{
                    m[adj]->neighbors.push_back(m[n]);
                }
            }

           
        }

        return m[node];
    }
};