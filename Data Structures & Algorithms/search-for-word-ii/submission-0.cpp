class Node {
private:
    Node* links[26] = {nullptr};
    string word = "";

public:
    Node() {
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    void setKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getKey(char ch) {
        return links[ch - 'a'];
    }

    void setWord(string w) {
        word = w;
    }

    string getWord() {
        return word;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->setKey(ch, new Node());
            }
            node = node->getKey(ch);
        }
        node->setWord(word);
    }

    // bool findWord(string word) {
    //     Node* node = root;
    //     for (char ch : word) {
    //         if (!node->containsKey(ch)) {
    //             return false;
    //         }
    //         node = node->getKey(ch);
    //     }
    //     return node->isEnd();
    // }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, Node* node, vector<string>& ans) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') {
            return;
        }

        char ch = board[i][j];

        if (!node->containsKey(ch)) {
            return;
        }
        node = node->getKey(ch);

        if (node->getWord() != "") {
            ans.push_back(node->getWord());
            node->setWord("");
        }

        board[i][j] = '#';
        dfs(board, i - 1, j, node, ans);
        dfs(board, i + 1, j, node, ans);
        dfs(board, i, j - 1, node, ans);
        dfs(board, i, j + 1, node, ans);
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();

        for (string word : words) {
            trie->addWord(word);
        }

        int n = board.size();
        int m = board[0].size();

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, trie->root, ans);
            }
        }

        return ans;
    }
};
