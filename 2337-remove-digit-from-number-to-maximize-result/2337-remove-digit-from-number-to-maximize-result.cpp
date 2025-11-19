class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        int last=0;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                last=i;
                if(i<number.size()&&number[i]<number[i+1]) return number.substr(0,i)+number.substr(i+1);
            }
        }    
        return number.substr(0,last)+number.substr(last+1);
    }
};