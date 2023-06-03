#include<vector>
using namespace std;
class Solution {
public:
    void DFS(vector<int> curr, vector<vector<int>>& ans, vector<vector<int>>& graph, int u,int n){
        if( u == n){
            ans.push_back(curr);
            return;
        }
        for(auto it : graph[u]){
            curr.push_back(it);
            DFS(curr,ans,graph,it,n);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(0);
        int n = graph.size()-1;
        DFS(curr,ans,graph,0,n);
        return ans;
    }
};