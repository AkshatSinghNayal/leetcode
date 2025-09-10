class Solution {
private:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    
    vector<int> findpse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    
    vector<int> findnge(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    
    vector<int> findpge(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        vector<int> nge = findnge(arr);
        vector<int> pge = findpge(arr);
        
        long long totalMin = 0;
        long long totalMax = 0;
        
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            totalMin += leftMin * rightMin * arr[i];
            
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            totalMax += leftMax * rightMax * arr[i];
        }
        
        return totalMax - totalMin;
    }
};