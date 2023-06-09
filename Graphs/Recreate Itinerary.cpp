//very good question
#include<vector>
#include<unordered_map>
#include<stack>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> mp;
        int n = tickets.size();
        for(int i=0;i<n;i++){
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> st;
        st.push("JFK");
        vector<string> ans;
        while(!st.empty()){
            string temp = st.top();
            if(mp[temp].size() == 0){
                ans.push_back(temp);
                st.pop();
            }else{
                auto it = mp[temp].begin();
                st.push(*it);
                mp[temp].erase(it);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};