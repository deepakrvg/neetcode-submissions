class Solution {
public:
    int key = 10;

    string encode(vector<string>& strs) {
        string encode_string = "";
        for (string s : strs) {
            encode_string += to_string(s.size()) + "#" + s;
        }
        return encode_string;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size();
        // loop through all chars
        while (i < n) {
            // get size of current string
            int num = 0;
            int j = i;
            string len_text = "";
            while (s[j] != '#') {
                len_text += s[j];
                j++;
            }
            int len = stoi(len_text);
            i = j + 1;
            
            // remove # and generate string
            string word;
            while (len--) {
                word += s[i];
                i++;
            }

            // add string to ans
            ans.push_back(word);
        }
        return ans;
    }
};
