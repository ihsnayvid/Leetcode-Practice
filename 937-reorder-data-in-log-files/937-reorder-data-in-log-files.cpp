class Solution {
public:
    static bool cmp(string s1, string s2){
        string before1, before2, after1, after2;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] == ' '){
                after1 = s1.substr(i+1);
                before1 = s1.substr(0,i);
                break;
            }
        }
          
        for(int i=0; i<s2.length(); i++){
            if(s2[i] == ' '){
                after2 = s2.substr(i+1);
                before2 = s2.substr(0,i);
                break;
            }
        }
        
        if(after1 < after2) return true;
        else if(after1 == after2) return before1 < before2;
        return false;        
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> lt, dg;
        for(auto i: logs){
            if(isdigit(i.back()))
                dg.push_back(i);
            else 
                lt.push_back(i);
        }
        
        sort(lt.begin(), lt.end(), cmp);
        lt.insert(lt.end(), dg.begin(), dg.end());
        return lt;
    }
};