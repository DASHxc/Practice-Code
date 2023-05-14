//very good question... using the fake edges to create a directed graph and 
//then starting from 0 edge to see if the edge placed is correct or not.
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    void DFS(int &temp,vector<pair<int,char>> graph[],int node,vector<int>& visited){
        visited[node] = 1;
        for(auto it : graph[node]){
            //cout<<"*"<<it<<endl;
            if(!visited[it.first]){
                if(it.second == 'R')
                    temp++;
                DFS(temp,graph,it.first,visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int cnt = 0;
        vector<pair<int,char>> graph[n];
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back({connections[i][1],'R'}); //real
            graph[connections[i][1]].push_back({connections[i][0],'F'}); //fake
        }
        vector<int> visited(n,0);
        DFS(cnt,graph,0,visited);
        return cnt;
    }
};