#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> result;
        dfs("JFK", adj, result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(string u, map<string, multiset<string>>& adj, vector<string>& result) {
        while (!adj[u].empty()) {
            string v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
            dfs(v, adj, result);
        }
        result.push_back(u);
    }
};
