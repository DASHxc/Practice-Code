
//First Approach o(n*n) BFS
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    void DFS(vector<int> graph[], int u, vector<int>& visited, int level, int& ht ){
        visited[u] = 1;
        ht = max(ht,level);
        for(auto v:graph[u]){
            if(visited[v] == 0){
                DFS(graph,v,visited,level+1,ht);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        int size = edges.size();
        vector<int> graph[n];
        for(int i=0;i<size;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ht = 0;
        int minHeight = INT_MAX;
        for(int i=0;i<n;i++){
            int level = 0;
            vector<int> visited(n,0);
            ht=0;
            DFS(graph,i,visited,level,ht);
            if(ht <= minHeight){
                if(ht == minHeight){
                    ans.push_back(i);
                }else{
                    ans.clear();
                    ans.push_back(i);
                }
                minHeight = ht;
            }
        }
        return ans;
    }
};

//Second Approach
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        int size = edges.size();
        if(n == 1){
            ans.push_back(0);
            return ans;
        }
        vector<int> graph[n];
        vector<int> depth(n,0);
        for(int i=0;i<size;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            depth[edges[i][0]]++;
            depth[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(depth[i] == 1)
                q.push(i);
        }
        while(n > 2){
            int qsize = q.size();
            n -= qsize;
            for(int i = 0;i<qsize;i++){
                int temp = q.front();
                q.pop();
                for(auto it: graph[temp]){
                    depth[it]--;
                    if(depth[it] == 1)
                        q.push(it);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
