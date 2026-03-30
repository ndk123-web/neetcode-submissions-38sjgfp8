class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (auto ast : asteroids) {
            while (!res.empty() && res.back() > 0 && ast < 0 ) {
                int diff = res.back() + ast;
                if (diff < 0) {
                    res.pop_back();
                }
                else if (diff > 0) {
                    ast = 0;
                }
                else {
                    res.pop_back();
                    ast = 0;
                }
            }

            if (ast != 0){
                res.push_back(ast);
            }
        }

        return res;
    }
};