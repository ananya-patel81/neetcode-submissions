class Solution {
public:
    bool isPalindrome(string s) {
       string newst="";
       for(char c : s){
            if(isalnum(c)){
                newst+= tolower(c);
            }
            
       } 

       return newst == string(newst.rbegin(),newst.rend());
        
    }
};
