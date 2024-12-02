class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt = 0;
        for(int i=0; i<sentence.length(); i++) {
            if(i == 0 || sentence[i-1] == ' ') {
                cnt++;
                
                // check if sentence[i] and searchWord are equal
                bool isEqual = true;
                for(int j=0; j<searchWord.length(); j++) {
                    if(i+j >= sentence.length() || sentence[i+j] != searchWord[j]) {
                        isEqual = false; 
                        i = i+j;
                        break;
                    }
                }
                if(isEqual) return cnt;
                
            }
        }
        return -1;
    }
};