class Solution {
public:
    bool isAnagram(string s, string t) {
        // make hash maps for both 
        int n=s.length();
        int m=t.length();

        if(n!=m){
            return false;
        }

        unordered_map<char,int> smpp;
        unordered_map<char,int> tmpp;

        for(int i=0; i<=n; i++){
            smpp[s[i]]++;
        }

        for(int i=0; i<=m; i++){
            tmpp[t[i]]++;
        }


        // compare each character's frequency in the hash maps and 
        //return false as soon as anything does not match

        for(int i=0; i<=n; i++){
            if(smpp[s[i]]!=tmpp[s[i]]){
                return false;
            }
        }

        return true;
        
    }
};
