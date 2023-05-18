#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
class Solution {
public:
    vector<int> parent;
    vector<long long> rank;
    int findParent(int i){
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    void unionMerge(int i,int j){
        int iP = findParent(i);
        int jP = findParent(j);
        if(iP == jP)
            return;
        if(rank[iP] >= rank[jP]){
            parent[jP] = iP;
            rank[iP]= rank[iP] + rank[jP];
            rank[jP]=0;
        }else{
            parent[iP] = jP;
            rank[jP] = rank[iP] + rank[jP];
            rank[iP]=0;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i=0;i<edges.size();i++){
            unionMerge(edges[i][0],edges[i][1]);
        }
        vector<long long> temp;
        for(int i=0;i<n;i++){
            if(rank[i] != 0){
                temp.push_back(rank[i]);
            }
        }
        if(temp.size() == 1)
            return 0;
        long long ans = (long long)(n)*(n-1)/2;
        for(int i=0;i<temp.size();i++){
                ans -= (long long)temp[i] * (long long)(temp[i] - 1)/2;
        }
        return ans;
    }
};