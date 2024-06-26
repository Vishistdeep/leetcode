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
     unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node){
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto ele:node->neighbors)
                 clone->neighbors.push_back(mp.count(ele)?mp[ele]:dfs(ele));
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node or !node->neighbors.size())
                   return !node?NULL:new Node(node->val);
        return dfs(node);
    }
};