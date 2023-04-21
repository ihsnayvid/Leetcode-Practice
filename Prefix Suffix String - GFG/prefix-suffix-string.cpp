//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
    struct Node{
        Node* links[26];
        bool flag;

        bool containsKey(char ch){
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, Node* node){
            links[ch - 'a'] = node;
        }

        Node* get(char ch){
            return links[ch - 'a'];
        }

        void setEnd(){
            flag = true;
        }
        
        bool isEnd(){
            return flag;
        }
    };

    class Trie {    
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        //O(len of word)
        void insert(string word) {
            Node* node = root;
            for(auto &i: word){
                if(!node->containsKey(i))
                    node->put(i, new Node());

                node = node->get(i);
            }

            node->setEnd();
        }
        
        bool search(string word) {
            Node* node = root;
            for(auto &i: word){
                if(!node->containsKey(i)) return false;
                node = node->get(i);
            }
            return node->isEnd();
        }
        
        bool startsWith(string prefix) {
            Node* node = root;
            for(auto &i: prefix){
                if(!node->containsKey(i)) return false;
                node = node->get(i);
            }
            return true;
        }
    };

class Solution{
public:

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie t;
        int count = 0;
        for(auto &i: s1){
            t.insert(i);
            string s = i;
            reverse(s.begin(), s.end());
            // cout<<s<<" "
            t.insert(s);
        }
        for(auto &i: s2){
            if(t.startsWith(i)) count++;
            else{
                reverse(i.begin(), i.end());
                if(t.startsWith(i)) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends