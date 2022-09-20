class Solution {    
public:
    
    void dfs(vector<vector<int>>& rooms, unordered_set<int> & keys, unordered_set<int> & visited, int idx) {
        visited.insert(idx);
        for (int i : rooms[idx]) keys.insert(i);
        for (int i : keys){
            if (visited.find(i) == visited.end()) 
                dfs(rooms, keys, visited, i);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> visited;
        dfs(rooms, keys, visited, 0);
        return visited.size() == rooms.size();
    }
};