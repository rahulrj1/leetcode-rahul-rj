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
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q; q.push(node);
        mp[node] = new Node(node->val);
        
        while(!q.empty()) {
            Node* currNode = q.front(); q.pop();
            for(Node* nb: currNode->neighbors) {
                if(mp.find(nb) == mp.end()) {mp[nb] = new Node(nb->val); q.push(nb);}
                mp[currNode]->neighbors.push_back(mp[nb]);
            }
        }
        
        return mp[node];
    }
};