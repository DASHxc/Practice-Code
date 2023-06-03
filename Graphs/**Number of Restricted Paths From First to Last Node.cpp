#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//final attempt by using the way method.
class Solution {
public:
    int mod = 1e9 + 7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> graph[n+1];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            graph[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        vector<int> dist(n+1,INT_MAX);
        vector<int> ways(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
        q.push({0,n});
        dist[n] = 0;
        ways[n] = 1;
        while(!q.empty()){
            pair<int,int> temp = q.top();
            q.pop();
            if(temp.first > dist[temp.second])
                continue;
            for(auto it : graph[temp.second]){
                if(dist[it.second] > temp.first + it.first){
                    dist[it.second] = temp.first + it.first;
                    q.push({dist[it.second],it.second});
                }
                if(temp.first > dist[it.second])
                    ways[temp.second] = (ways[temp.second] + ways[it.second])%mod;
            }
        }
        return ways[1];
    }
};

//second attempt to do memorization in first attempt. Memory limit error
// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int DFS(int src,int dst,vector<pair<int,int>> graph[],vector<int>& dp,vector<int> dist,int& currAns){
//         if(dp[src] != -1)
//             return dp[src];
//         if(src == dst){
//             return 1;
//         }
//         int ans = 0;
//         for(auto it : graph[src]){
//             if(dist[src] > dist[it.second]){
//                 ans = (ans + DFS(it.second,dst,graph,dp,dist,currAns)) % mod;
//             }
//         }
//         return dp[src] = ans;
//     }
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
//         vector<pair<int,int>> graph[n+1];
//         for(int i=0;i<edges.size();i++){
//             graph[edges[i][0]].push_back({edges[i][2],edges[i][1]});
//             graph[edges[i][1]].push_back({edges[i][2],edges[i][0]});
//         }
//         vector<int> dist(n+1,INT_MAX);
//         priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
//         q.push({0,n});
//         dist[n] = 0;
//         while(!q.empty()){
//             pair<int,int> temp = q.top();
//             q.pop();
//             for(auto it : graph[temp.second]){
//                 if(dist[it.second] > temp.first + it.first){
//                     dist[it.second] = temp.first + it.first;
//                     q.push({dist[it.second],it.second});
//                 }
//             }
//         }
//         int ans = 0;
//         vector<int> dp(n+1,-1);
//         return DFS(1,n,graph,dp,dist,ans);
//     }
// };

//first attempt no memorization using simple djkstra traversal... not all test cases passed.
// class Solution {
// public:
//     void DFS(int src,int dst,vector<pair<int,int>> graph[],vector<int>& visited,vector<int> dist,int& currAns){
//         if(src == dst){
//             currAns++;
//         }
//         visited[src] = 1;
//         for(auto it : graph[src]){
//             if(!visited[it.second] && dist[src] > dist[it.second]){
//                 DFS(it.second,dst,graph,visited,dist,currAns);
//             }
//         }
//         visited[src] = 0;
//     }
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
//         vector<pair<int,int>> graph[n+1];
//         for(int i=0;i<edges.size();i++){
//             graph[edges[i][0]].push_back({edges[i][2],edges[i][1]});
//             graph[edges[i][1]].push_back({edges[i][2],edges[i][0]});
//         }
//         vector<int> dist(n+1,INT_MAX);
//         priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
//         q.push({0,n});
//         dist[n] = 0;
//         while(!q.empty()){
//             pair<int,int> temp = q.top();
//             q.pop();
//             for(auto it : graph[temp.second]){
//                 if(dist[it.second] > temp.first + it.first){
//                     dist[it.second] = temp.first + it.first;
//                     q.push({dist[it.second],it.second});
//                 }
//             }
//         }
//         int ans = 0;
//         vector<int> visited(n+1,0);
//         DFS(1,n,graph,visited,dist,ans);
//         return ans;
//     }
// };