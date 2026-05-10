class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>>st; 
        int k = 0; 
        for(auto& it : points ){
            if(it == target) return 0; 
            st.insert(it); 
        }
        if(st.size() <= 1 ) return -1;
        vector<vector<int>> ans(st.begin(),st.end()); 

        while(true){
            int n = ans.size();
            bool found = false; 
            for(int i = 0 ; i<n-1 ; i++ ){
                for(int j = i+1; j< n ; j++ ){
                    vector<int>mid(3); 
                    for(int k = 0 ; k<3 ; k++ ){
                        mid[k] = (ans[i][k] + ans[j][k])/2; 
                    }
                    if( mid == target) return k+1;

                    if(!st.count(mid)) {
                        st.insert(mid); 
                        found = true; 
                        ans.push_back(mid);  
                    }

                }
            }
            if(!found) return -1; 
            k++; 
        } 
        return -1; 
    }
};