class CountSquares {
   private:
    map<vector<int>, int> freqMap;
    vector<vector<int>> points;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        freqMap[point] += 1;
        points.push_back(point);
    }

    int count(vector<int> query) {
        // square means each side must equal
        int count = 0;
        int x2 = query[0];
        int y2 = query[1];

        for (vector<int>& point : points) {
            int x = point[0];
            int y = point[1];

            // check for valid diagonal
            if (abs(x - x2) == abs(y - y2) && x != x2) {

                // get the same distance (in square in each direction dist is same)
                int dist = abs(x - x2);

                count += freqMap[{x2, y}] * freqMap[{x, y2}];
            }
        }

        return count;
    }
};
