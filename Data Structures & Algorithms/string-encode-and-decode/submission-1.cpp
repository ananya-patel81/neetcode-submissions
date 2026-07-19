class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans="";
        vector<int> sizes;
        for(string& str : strs){
            sizes.push_back(str.size());
        }
        for(int i : sizes){
            ans+=to_string(i)+',';
        }
        ans+='#';
        for(string& s : strs){
            ans+=s;
        }
        return ans;



    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> res;
        vector<int> sizes;
        int i=0;
        while(s[i]!='#'){
            string curr="";
            while(s[i]!=','){
                curr+=s[i];
                i++;
            }
            int currSize=stoi(curr);
            sizes.push_back(currSize);
            i++;
        }
        i++;
        for(int size : sizes){
            res.push_back(s.substr(i,size));
            i+=size;
        }
        return res;

    }
};
