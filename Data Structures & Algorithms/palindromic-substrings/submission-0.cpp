class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int resLen=0;
        int resInd=-1;
        for(int i=0;i<s.size();i++){
            int l=i, r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > resLen){
                    resInd = l;
                    resLen = (r-l+1);
                
                }
                l--;
                r++;
                count++;
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
                count++;
            }  
        }
        return count;
    }
};
