#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int i){
        if(i==parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    bool unionMerge(int i,int j){
        int p1 = findParent(i);
        int p2 = findParent(j);
        if(p1 == p2)
            return false;
        if(rank[p1] >= rank[p2]){
            parent[p2] = p1;
            rank[p1]++;
        }else{
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : rooms[temp]){
                if(unionMerge(temp,it))
                    q.push(it);
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i] != 0)
                return false;
        }
        return true;
    }
};


//Better solution simply use DFS... why didn't i think of it...
// class Solution {
// public:
//     void DFS(int u,vector<vector<int>>& graph, vector<int>& visited,int n){
//         visited[u] = 1;
//         for(auto it : graph[u])
//             if(!visited[it])
//                 DFS(it,graph,visited,n);
//     }
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         vector<int> visited(n,0);
//         DFS(0,rooms,visited,n);
//         for(auto it : visited){
//             if(it == 0)
//                 return false;
//         }
//         return true;
//     }
// };