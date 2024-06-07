class Solution {
public:
    class trieNode {
        public:
        trieNode* child[26];
        bool isEnd;
        
        trieNode() {
            for(int i=0; i<26; i++) child[i] = nullptr;
            isEnd = false;
        }
    };
    
    string findWord(trieNode* rootNode, string s) {
        string res = "";
        for(char &c: s) {
            if(rootNode->child[c-'a']) rootNode = rootNode->child[c-'a'], res += c;
            else return s;
            
            if(rootNode->isEnd) return res;
        }
        return s;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        trieNode* rootTrieNode = new trieNode();
        for(string &word: dictionary) {
            trieNode* temp = rootTrieNode;
            for(char &c: word) {
                if(!(temp->child[c-'a'])) temp->child[c-'a'] = new trieNode();
                temp = temp->child[c-'a'];
            }
            temp->isEnd = true;
        }
        
        
        string res = "", s = "";
        for (char c: sentence) {
            if(c == ' ') {
                res += findWord(rootTrieNode, s) + " ";
                s = "";
            }
            else {
                s.push_back(c);
            }
        } 
        res += findWord(rootTrieNode, s);
        return res;
    }
};