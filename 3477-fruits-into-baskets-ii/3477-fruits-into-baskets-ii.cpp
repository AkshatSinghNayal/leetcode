class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        for(int i = 0 ;i<fruits.size(); i++ ){
            int ele= fruits[i]; 
            bool found  = false;
            for(int j = 0; j<fruits.size() ; j++ ){
                
                if(baskets[j] >= ele ){
                    count++; 
                    baskets[j] = INT_MIN;
                    break;
                }

            }
        }
        // for(auto& it : baskets ) cout<< it << " ";
        return fruits.size() - count; 
    }
};