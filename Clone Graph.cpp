//Given a reference of a node in a connected undirected graph.
//Return a deep copy (clone) of the graph.
//Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

#include<vector>
#include<unordered_map>
using namespace std;
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

class Solution {
public:
    void dfs(Node* orig, Node* copy, unordered_map<Node*,Node*>& mp){
        mp[orig] = copy;
        for(auto curr: orig->neighbors){
            if(mp.find(curr) != mp.end()){
                (copy->neighbors).push_back(mp[curr]);
            }else{
                Node* temp = new Node(curr->val);
                (copy->neighbors).push_back(temp);
                dfs(curr,temp,mp);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        unordered_map<Node*,Node*> mp;
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for(auto curr : node->neighbors){
            if(mp.find(curr) != mp.end()){
                (copy->neighbors).push_back(mp[curr]);
            }else{
                Node* temp = new Node(curr->val);
                (copy->neighbors).push_back(temp);
                dfs(curr,temp,mp);
            }
        }
        return copy;
    }
};