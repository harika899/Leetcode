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
    
    Node* clone(Node* node, unordered_map<int,Node*>& mp)
    {
        Node* newNode = new Node(node->val);
        mp.insert({node->val,newNode});
        
        for(auto itr : node->neighbors)
        {
            if(mp.find(itr->val) == mp.end())
            {
                Node* cn = clone(itr,mp);
                newNode->neighbors.push_back(cn);
            }
            else
                newNode->neighbors.push_back(mp[itr->val]);
        }
        
        return newNode;
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
            return nullptr;
        
        unordered_map<int,Node*> mp;
        
        return clone(node, mp);
        
    }
};