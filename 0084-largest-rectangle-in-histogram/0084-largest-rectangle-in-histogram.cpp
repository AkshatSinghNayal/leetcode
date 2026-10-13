
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>previous(n,-1);
        vector<pair<int,int>>nxt(n);
        stack<pair<int,int>>st; 

        int i = n-1; 
        while(i>=0){
            while(!st.empty() and heights[st.top().second] >= heights[i]){
                st.pop();
            }

            nxt[i] = {heights[i], st.empty() ? n : st.top().second}; 
            st.push({heights[i],i});
            i--; 
        }

        int maxi = 0;
        i = 0; 
        stack<pair<int,int>>().swap(st);

        while(i<n){
            while(!st.empty() and heights[st.top().second] >= heights[i]){
                st.pop(); 
            }

            previous[i] = st.empty() ? -1 : st.top().second;

            int cal = heights[i]*(nxt[i].second-previous[i]-1);
            maxi = max(cal,maxi);

            st.push({heights[i],i});
            i++; 
        }

        return maxi;
    }
};
