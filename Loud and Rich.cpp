//incomplete solution TLE at 71 test case, no memorization applied
// class Solution {
// public:
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         vector<int> ans;
//         int n = quiet.size();
//         vector<int> graph[n];
//         for(int i=0;i<richer.size();i++){
//             graph[richer[i][1]].push_back(richer[i][0]);
//         }
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             q.push(i);
//             int minQuiet = quiet[i];
//             int minNode = i;
//             while(!q.empty()){
//                 int temp = q.front();
//                 q.pop();
//                 for(auto it : graph[temp]){
//                     if(quiet[it] < minQuiet){
//                         minQuiet = quiet[it];
//                         minNode = it;
//                     }
//                     q.push(it);
//                 }
//             }
//             ans.push_back(minNode);
//         }
//         return ans;
//     }
// };


//Simple DFS with memorization
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    pair<int,int> DFS(int u, vector<int> graph[],vector<int> quiet,vector<pair<int,int>>& dp){
        if(dp[u].first != -1 && dp[u].second != -1){
            return dp[u];
        }
        pair<int,int> ans = {quiet[u],u};
        for(auto it : graph[u]){
            auto temp = DFS(it,graph,quiet,dp);
            if(temp.first < ans.first){
                ans.first = temp.first;
                ans.second = temp.second;
            }
        }
        return dp[u] = ans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> ans;
        int n = quiet.size();
        vector<int> graph[n];
        for(int i=0;i<richer.size();i++){
            graph[richer[i][1]].push_back(richer[i][0]);
        }
        vector<pair<int,int>> dp(n,{-1,-1});
        for(int i=0;i<n;i++){
            pair<int,int> minVal = DFS(i,graph,quiet,dp);
            ans.push_back(minVal.second);
        }
        return ans;
    }
};