class Node {
private:
    vector<Node*> links;
    bool endFlag;
    bool isEmpty;

public:
    Node() {
        links.assign(26, nullptr);
        endFlag = false;
        isEmpty = false;
    }

    bool containsKey(char ch) {
        if (ch == '.') {
            return isEmpty;
        }
        else {
            return (links[ch - 'a'] != nullptr);
        }
    }

    void setKey(char ch, Node* node) {
        links[ch - 'a'] = node;
        isEmpty = true;
    }

    Node* getKey(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        endFlag = true;
    }

    bool isEnd() {
        return endFlag;
    }

    bool containsAnyChar() {
        return isEmpty;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
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
        node->setEnd();
    }
    
    bool solve(const string& suffix, int index, Node* node) {
        Node* temp = node;
        for (int j = index; j < suffix.size(); j++) {
            if (suffix[j] == '.') {
                for (int i = 0; i < 26; i++) {
                    Node* t = temp->getKey('a' + i);
                    if (t != nullptr && solve(suffix, j + 1, t)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (!temp->containsKey(suffix[j])) {
                    return false;
                }
                temp = temp->getKey(suffix[j]);
            }
        }
        return temp->isEnd();
    }

    bool search(string word) {
        Node* node = root;
        return solve(word, 0, node);
    }
};
