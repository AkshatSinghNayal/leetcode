class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9+7;
        long long grp1 = 0 , grp2 = 0 , countInversions = 0;

        for(auto& it : nums ){
            if(it<a){
                countInversions = (countInversions+grp1+grp2)%MOD;
            }
            else if( it <= b ){
                countInversions = (countInversions + grp2)%MOD;
                grp1++; 
            }
            else{
                grp2++;
            }
        }

        return (int)countInversions;
    }
};