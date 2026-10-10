class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<pair<int,int>>temp;
        int n = nums1.size(); 
        for(int i = 0 ;i<n ;i++ ){
            temp.push_back({nums1[i],nums2[i]}); 
        }
        sort(temp.begin() , temp.end(), [&](const auto& a , const auto& b ){
            auto [f1 , f2] = a; 
            auto [ y1, y2] = b; 
            return abs(f1-f2) > abs(y1-y2); 
        }); 

        for(auto&[ first , second] : temp ){
            cout<< first<< " " << second << " "; 
            cout<<endl; 
        }
        long long total= 0;
        int lasti = 0; 

       long long k = 1LL * k1 + k2;
long long sum = 0;

for (auto& [first, second] : temp) {
    sum += abs(first - second);
}

if (k >= sum) {
    for (auto& [first, second] : temp) {
        first = second;
    }
}
else {
    long long level = abs(temp[0].first - temp[0].second);

    for (int i = 0; i < n; i++) {
        long long next = (i + 1 < n)
            ? abs(temp[i + 1].first - temp[i + 1].second)
            : 0;

        long long need = (level - next) * (i + 1);

        if (k >= need) {
            k -= need;
            level = next;
        }
        else {
            level -= k / (i + 1);
            int rem = k % (i + 1);

            for (int j = 0; j < n; j++) {
                auto& [first, second] = temp[j];

                int diff = min((long long)abs(first - second), level);

                if (j < rem) diff--;

                if (first >= second)
                    first = second + diff;
                else
                    first = second - diff;
            }

            break;
        }
    }
}
        while(lasti<n){
            long long toadd = (temp[lasti].first - temp[lasti].second );
            total=total+( toadd*toadd) ; 
            lasti++;
        }

        return total;
       
    }
};