//735. Asteroid Collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Stack to store surviving asteroids
        vector<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {

            // Right-moving asteroid can never collide immediately
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } 
            else {
                // Destroy all smaller right-moving asteroids
                while (!st.empty() && st.back() > 0 &&
                       st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                // Both asteroids destroy each other
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                // Current left-moving asteroid survives
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
                // If st.back() > abs(asteroids[i]),
                // the current asteroid is destroyed (do nothing)
            }
        }

        return st;
    }
};