class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;                       // indices, heights strictly increasing
        int best = 0;

        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : heights[i];   // sentinel 0 flushes the stack

            while (!st.empty() && heights[st.top()] >= cur) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                best = max(best, h * width);
            }
            st.push(i);
        }
        return best;
    }
};