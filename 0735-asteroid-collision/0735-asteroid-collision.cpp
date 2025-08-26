class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {
        vector<int> st; 
        int left = 0; 
        while (left < aster.size()) {
            bool destroyed = false;

            if (aster[left] < 0) {
                // keep checking as long as last asteroid is moving right
                while (!st.empty() && st.back() > 0) {
                    if (abs(st.back()) < abs(aster[left])) {
                        st.pop_back(); 
                        continue; // check again with new top
                    }
                    if (abs(st.back()) == abs(aster[left])) {
                        st.pop_back(); 
                    }
                    destroyed = true; 
                    break; // current asteroid is gone
                }
            }

            if (!destroyed) {
                st.push_back(aster[left]);
            }
            left++;
        }
        return st; 
    }
};
