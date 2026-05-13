class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> is_visited(rooms.size(), 0);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int key = q.front();
            q.pop();
            
            if (is_visited[key]) continue;

            for (auto i: rooms[key]){
                if (!is_visited[i]) q.push(i);
            }
            is_visited[key] = true;
        }

        for (bool b: is_visited) if (!b) return false;

        return true;
        
    }
};

