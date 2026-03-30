class Solution {
private:

    map<pair<int,int>, bool> memo;

    bool dfs(vector<int>& piles, int x, int y, int i, int j, bool turn) {
        if (i == 0 && j == -1) {
            return (x > y) ? true: false;
        }

        if (memo.find({x,y}) != memo.end()) {
            return memo[{x,y}];
        }

        vector<int> tempPiles = piles;

        if (turn) {
            tempPiles.erase(tempPiles.begin() + i);
            bool takeFirst = dfs(tempPiles, x+piles[i], y, 0, tempPiles.size()-1, !turn);

            tempPiles = piles;
            tempPiles.erase(tempPiles.begin() + j);
            bool takeLast = dfs(tempPiles, x+piles[j], y, 0, tempPiles.size()-1, !turn);
            return memo[{x,y}] = takeFirst || takeLast;
        }

        else {
            tempPiles.erase(tempPiles.begin() + i);
            bool takeFirst = dfs(tempPiles, x, y + piles[i], 0, tempPiles.size()-1, !turn);

            tempPiles = piles;
            tempPiles.erase(tempPiles.begin() + j);
            bool takeLast = dfs(tempPiles, x, y+piles[j], 0, tempPiles.size()-1, !turn);
            return memo[{x,y}] = takeFirst || takeLast;
        }

    }
public:
    bool stoneGame(vector<int>& piles) {
       return dfs(piles, 0,0,0,piles.size()-1,true); 
    }
};