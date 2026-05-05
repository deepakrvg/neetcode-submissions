class Node {
private:
    vector<Node*> links;
    bool end;

public:
    Node() {
        links.assign(26, NULL);
        end = false;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void setKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getKey(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        end = true;
    }

    bool isEnd() {
        return end;
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->setKey(c, new Node());
            }
            node = node->getKey(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->getKey(ch);
        }
        return true;
    }
};
