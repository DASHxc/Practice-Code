#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    bool isCycle(int u,vector<vector<int>>& graph,vector<int>& visited,int n){
        visited[u] = 1;
        for(auto it : graph[u]){
            if(visited[it] == 1)
                return true;
            if(!visited[it] && isCycle(it,graph,visited,n))
                return true;
        }
        visited[u] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            if(isCycle(i,graph,visited,n))
                continue;
            else
                ans.push_back(i);
        }
        return ans;
    }
};

//second approch using outdegree and reverseGraph technique.
//faster than previous


// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> reverseGraph[n];
//         vector<int> outdegree(n,0);
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             for(auto it : graph[i]){
//                 reverseGraph[it].push_back(i);
//             }
//             outdegree[i] = graph[i].size();
//             if(outdegree[i] == 0)
//                 q.push(i);
//         }
//         vector<int> safeNode(n,0);
//         while(!q.empty()){
//             int temp = q.front();
//             q.pop();
//             safeNode[temp] = 1;
//             for(auto it : reverseGraph[temp]){
//                 outdegree[it]--;
//                 if(outdegree[it] == 0)
//                     q.push(it);
//             }
//         }
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             if(safeNode[i] == 1)
//                 ans.push_back(i);
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };