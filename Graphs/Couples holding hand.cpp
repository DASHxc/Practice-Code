
#include<vector>
#include<unordered_map>
#include<stack>
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
    void unionMerge(int x, int y, int& cnt){
        int parentX = findParent(x);
        int parentY = findParent(y);
        if(parentX == parentY)
            return;
        if(rank[parentX] <= rank[parentY]){
            parent[parentX] = parentY;
            rank[parentY]++;
        }else{
            parent[parentY] = parentX;
            rank[parentX]++;
        }
        cnt--;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        int cnt = n;
        for(int i=0;i<2*n;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i=0;i<n;i++){
            int x = row[2*i];
            int y = row[2*i + 1];
            unionMerge(x/2,y/2,cnt);
        }
        return n - cnt;
    }
};