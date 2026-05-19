class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> pointsCount;
    vector<pair<int, int>> points;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointsCount[x][y]++;
        points.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int total = 0;

        for (auto& p : points) {
            int x = p.first;
            int y = p.second;

            if (px == x || py == y) continue;

            if (abs(px - x) != abs(py - y)) continue;

            total += pointsCount[x][py] * pointsCount[px][y];
        }
        return total;
    }
};
