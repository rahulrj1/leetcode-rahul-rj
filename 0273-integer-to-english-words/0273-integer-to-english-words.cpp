class Solution {
public:
    string helper(string s) {
        if(stoi(s) == 0) return "Zero ";
        string ones[] = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
        string tens1[] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        string tens[] = {"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        
        string temp;
        if(s.length() == 1) return ones[s[0]-'1'];
        if(s[1] == '0') {
            temp = (s[2]-'0' == 0) ? "" : ones[s[2]-'1'];
        } 
        else if(s[1] == '1') {
            int z = stoi(s.substr(1));
            temp = tens1[z-10];
        } else {
            temp = tens[s[1]-'2'] + ((s[2]-'0' == 0) ? "" : ones[s[2]-'1']);
        }
        return (s[0] == '0') ? temp : ones[s[0]-'1'] + "Hundred " + temp; 
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        string s = to_string(num);
        reverse(s.begin(), s.end());
        while(s.length() < 10) s.push_back('0');
        reverse(s.begin(), s.end());
        
        string temp3 = helper(s.substr(7, 3)); // last three chars
        
        string temp2 = helper(s.substr(4, 3)); // second last three chars
        
        string temp1 = helper(s.substr(1, 3)); // third last three chars
        
        string firstChar = helper(s.substr(0, 1)); // first char
        
        string res = (firstChar == "Zero " ? "" : firstChar + "Billion ") + (temp1 == "Zero " ? "" : temp1 + "Million ") + (temp2 == "Zero " ? "" : temp2 + "Thousand ") + (temp3 == "Zero " ? "" : temp3);
        
        res.pop_back();
        return res;
    }
};