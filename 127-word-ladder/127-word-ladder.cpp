class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.count(endWord) == 0)  return 0;
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                string curr = q.front();
                q.pop();
                if(curr == endWord){
                    
                    return ans;
                }
                for(int i = 0; i < curr.size(); i++) {
                    string newWord = curr;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        newWord[i] = ch;
                        if(st.count(newWord))
                            q.push(newWord), st.erase(newWord);
                    }                    
                }
            }
            ans ++;
        }
        
        return 0;
    }
};