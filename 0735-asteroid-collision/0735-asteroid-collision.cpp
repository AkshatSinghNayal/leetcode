class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<pair<int,bool>>st;

        int i  = 0 ; 
        while( i < nums.size() ){
            int ele = nums[i] ; 
            bool sign = ( ele < 0 ) ? false : true; 
            bool equal = false;
            while(!st.empty() and st.top().second == true and sign == false) {
                if( abs(st.top().first) < abs(ele)){
                    st.pop();
                }
                else if( abs(st.top().first) == abs(ele) ){
                    st.pop(); 
                    equal = true;
                    break;
                }
                else{
                    equal=true;
                    break;
                }
            }
            if(!equal) st.push({ele , sign });
            i++; 
        }

        // while(!st.empty() ){
        //     cout<<st.top().first << "->" << st.top().second<<" ";
        //     st.pop();
        // }

        vector<int>ans ; 
        while(!st.empty()){
            ans.push_back(st.top().first ); 
            st.pop(); 
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};