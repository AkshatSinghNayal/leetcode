class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int>mp;
        unordered_map<char,int>mp1;

        for(auto& it : suits) mp1[it]++; 
        if(mp1.size() ==1 ) return "Flush"; 

        bool three = false , two = false ; 
        for(auto& it : ranks){ 
            mp[it]++;
            if(mp[it] == 2 ) two = true;
            if(mp[it] == 3 ) three = true;
        }

        if( three ){
            return "Three of a Kind"; 
        }
        if(two){
            return "Pair";
        }

        return "High Card";
        
    }
};