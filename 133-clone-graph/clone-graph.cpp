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


//1. make a copy of given node
//2. push  node in queue so that we can bfs and create copies for its neihhbours
//3. add in map{original node, copy node } evrey time a new node is created  to avaoid cycle 
//4 loop through adj of each node and create copies
//5. now new copy created for nodes are not connected we neeeed to give connections also , so as soon as we create a copy of adj we push that into the neighbour list of copy of node
//6. we also push the original nodes into the queue for bfs
// O(N*M) and O(N*M)
class Solution {
   
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        queue<Node*> q;
        unordered_map<Node*, Node*> m; // {original node, copy node}
        // step 1 
        Node* copy = new Node(node->val);
        // step 2
        q.push(node); // push original in q
        // step 3
        m[node]=copy;
        
        // step 4
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            // step 5
            for(auto neighbour:p->neighbors){
                // if the neighbour node doesnt have a copy yet 
                if(m.find(neighbour)==m.end()){
                    // create a copy of  neighbour of a node
                Node* neighbour_copy = new Node(neighbour->val);
               
                //  addthe cur neight and its copy in map
                m[neighbour] = neighbour_copy;
                //step 6 push the neighbour in the map
                q.push(neighbour); // push original neigbour
                }
                 // push it in adj list of copy of the popped node in bioth cases ie if its copy alrd existed or newly created
                 // m[p] - denotes copy of popped node 
                m[p]->neighbors.push_back(m[neighbour]);     
                
            }
        }
        
        
        return copy;
        
    }
};