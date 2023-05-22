#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
//union find method does not work here.
// class Solution {
// public:
//     vector<int> parent;
//     vector<int> rank;
//     int findParent(int i){
//         if(i==parent[i])
//             return i;
//         return parent[i] = findParent(parent[i]);
//     }
//     void unionMerge(int i,int j){
//         int iP = findParent(i);
//         int jP = findParent(j);
//         if(iP == jP)
//             return;
//         if(rank[iP] >= rank[jP]){
//             parent[jP] = iP;
//             rank[iP]++;
//         }else{
//             parent[iP] = jP;
//             rank[jP]++;
//         }
//     }
//     int calDist(int x1,int x2,int y1,int y2){
//         return (abs(x1-x2) + abs(y1-y2));
//     }
//     int maximumDetonation(vector<vector<int>>& bombs) {
//         int n = bombs.size();
//         for(int i=0;i<n;i++){
//             parent.push_back(i);
//             rank.push_back(1);
//         }
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int dist = calDist(bombs[i][0],bombs[j][0],bombs[i][1],bombs[j][1]);
//                 if(dist <= bombs[i][2] + bombs[j][2])
//                     unionMerge(i,j);
//             }
//         }
//         unordered_map<int,int> mp;
//         for(int i=0;i<n;i++){
//             mp[parent[i]]++;
//         }
//         int ans = INT_MIN;
//         for(auto it : mp){
//             ans = max(ans,it.second);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long long calDist(long long x1,long long y1,long long x2,long long y2){
        return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    }
    void DFS(int u, vector<int>& visited,vector<vector<int>>& bombs,int& currAns){
        for(int i=0;i<bombs.size();i++){
            if(i == u || visited[i])
                continue;
            long long dist = calDist(bombs[u][0],bombs[u][1],bombs[i][0],bombs[i][1]);
            if(dist <= (long long)bombs[u][2] * (long long)bombs[u][2]){
                visited[i] = 1;
                currAns = currAns + 1;
                DFS(i,visited,bombs,currAns);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            visited[i] = 1;
            int currAns = 1;
            DFS(i,visited,bombs,currAns);
            ans = max(ans, currAns);
        }
        return ans;
    }
};