#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    void DFS(int i,int currDist, vector<int>& distance,vector<int>& edges){
        if(i!=-1 && distance[i] == -1){
            distance[i] = currDist;
            DFS(edges[i],currDist+1,distance,edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        DFS(node1,0,dist1,edges);
        DFS(node2,0,dist2,edges);
        int ans = INT_MAX;
        int finalAns = -1;
        
        for(int i=0;i<n;i++){
            int currMax = INT_MAX;
            if(dist1[i] != -1 && dist2[i] != -1){
                currMax = max(dist1[i],dist2[i]);
            }
            if(ans > currMax){
                ans = currMax;
                finalAns = i;
            }
        }
        return finalAns;
    }
};