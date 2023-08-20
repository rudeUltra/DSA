class Solution {
    bool dfs(int curr, vector<char> &color, vector<int> adjList[], vector<int> &ans) {
        color[curr] = 'G';
        for(int next: adjList[curr]) {
            if(color[next] == 'G' || (color[next] == 'W' && dfs(next, color, adjList, ans)))
                return true;
        }
        ans.push_back(curr);
        color[curr] = 'B';
        return false;
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0; i < n; i++) {
            if(group[i] == -1) {
                group[i] = m++;
            }
        }
        vector<int> itemList[n], groupList[m], itemOrder, groupOrder, ans;
        for(int i = 0; i < n; i++) {
            for(int j: beforeItems[i]) {
                itemList[j].push_back(i);
                if(group[i] != group[j])
                    groupList[group[j]].push_back(group[i]);
            }
        }
        vector<char> itemVisited(n, 'W'), groupVisited(m, 'W');
        for(int i = 0; i < n; i++) {
            if(itemVisited[i] == 'W' && dfs(i, itemVisited, itemList, itemOrder))
                return {};
        }
        reverse(itemOrder.begin(), itemOrder.end());
        unordered_map<int, vector<int>> Map;
        for(int i: itemOrder) {
            Map[group[i]].push_back(i);
        }
        for(int i = 0; i < m; i++) {
            if(groupVisited[i] == 'W' && dfs(i, groupVisited, groupList, groupOrder))
                return {};
        }
        reverse(groupOrder.begin(), groupOrder.end());
        for(int i: groupOrder) {
            for(int j: Map[i])
                ans.push_back(j);
        }
        return ans;
    }
};