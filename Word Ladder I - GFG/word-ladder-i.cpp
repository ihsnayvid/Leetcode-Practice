//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        if(!st.count(targetWord)) return 0;
        
        q.push(startWord);
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                string word = q.front();
                q.pop();
                
                if(word == targetWord) return ans;
                for(int i=0; i<word.size(); i++){
                    string newWord = word;
                    for(char c = 'a'; c <= 'z'; c++){
                        newWord[i] = c;
                        if(st.count(newWord)){
                            q.push(newWord);
                            st.erase(newWord);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends