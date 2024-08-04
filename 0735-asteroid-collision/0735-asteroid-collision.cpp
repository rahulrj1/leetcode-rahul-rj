class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int &a: asteroids) {
            if(a > 0) res.push_back(a);
            else {
                bool isADestroyed = false;
                while(!res.empty() && res.back() > 0) {
                    if(res.back() < -a) res.pop_back();
                    else if(res.back() > -a) {isADestroyed = true; break;}
                    else {res.pop_back(); isADestroyed = true; break;}
                }
                if(!isADestroyed) res.push_back(a);
            }
        }
        return res;
    }
};