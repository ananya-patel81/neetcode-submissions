class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        int resInd = 0;

        for(int i=0;i<s.size();i++){
            int l=i, r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > resLen){
                    resInd = l;
                    resLen = (r-l+1);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1 ;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > resLen){
                    resInd = l;
                    resLen = (r-l+1);
                }
                l--;
                r++;
            }  
        }

        return s.substr(resInd,resLen);     
        
    }
};
