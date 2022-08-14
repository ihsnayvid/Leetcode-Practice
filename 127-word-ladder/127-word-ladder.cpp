class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.count(endWord) == 0)  return {};
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()) {
            for(int i=0; i<q.size(); i++) {
                vector<string> curr = q.front();
                q.pop();
                // cout<<"curr back "<<curr.back()<<endl;
                if(curr.back() == endWord) {
                    return curr.size();                    
                }                                                               

                string word = curr.back();
                st.erase(word);

                for(int i = 0; i < word.size(); i++) {
                    string newWord = curr.back();

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        newWord[i] = ch;
                        if(st.count(newWord)) {
                            q.push(curr);
                            q.back().push_back(newWord);
                        }
                    }
                }
                // for(auto i: curr)
                //     cout<<i<<" ";
                // cout<<endl;
            }
            
            // if(!ans.empty())
            //     break;
        }
        
        return ans;
    }
};