class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr; 
        unordered_map<int,int>mp;
        sort(temp.begin(),temp.end());
        int rank =0 , last = INT_MAX; 


        for(auto& it : temp){
            if( last == it ) continue;
            else{
                ++rank;
                mp[it] = rank;
                last = it;
            }
        }
        int i = 0; 
        for(auto& it : arr ){
            arr[i] = mp[it]; 
            i++; 
        }
        return arr; 

    }
};