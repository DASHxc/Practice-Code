#include<vector>
#include<unordered_map>
#include<stack>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int i){
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    void unionMerge(int i, int j){
        int p1 = findParent(i);
        int p2 = findParent(j);
        if(rank[p1] < rank[p2]){
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }else{
            rank[p1] += rank[p2];
            parent[p2] = p1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        pair<int,int> ans;
        vector<int> retAns;
        int n = edges.size();
        for(int i=0;i<n+1;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i=0;i<n;i++){
            int first = findParent(edges[i][0]);
            int second = findParent(edges[i][1]);
            if(first == second) 
                retAns = {edges[i][0],edges[i][1]};
            else
                unionMerge(first, second);
        }
        return retAns;
    }
};