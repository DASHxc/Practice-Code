#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> ans(n,{INT_MAX,INT_MAX});
        vector<int> redGraph[n];
        vector<int> blueGraph[n];
        for(int i=0;i<redEdges.size();i++){
            redGraph[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0;i<blueEdges.size();i++){
            blueGraph[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        queue<pair<int,char>> q;
        q.push({0,'R'});
        q.push({0,'B'});
        ans[0] = {0,0};
        int currDist = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int temp = q.front().first;
                char tempColor = q.front().second;
                q.pop();
                if(tempColor == 'R'){
                    for(auto it : redGraph[temp]){
                        if(ans[it].first > currDist+1){
                            ans[it].first = currDist+1;
                            q.push({it,'B'});
                        }
                    }
                }else{
                    for(auto it : blueGraph[temp]){
                        if(ans[it].second > currDist+1){
                            ans[it].second = currDist+1;
                            q.push({it,'R'});
                        }
                    }
                }
            }
            currDist++;
        }
        vector<int> finalAns(n,-1);
        for(int i=0;i<n;i++){
            if(ans[i].first == INT_MAX && ans[i].second == INT_MAX)
                finalAns[i] = -1;
            else
                finalAns[i] = min(ans[i].first,ans[i].second);
        }
        return finalAns;
    }
};