class Trie {
    
    struct Node {
        struct Node* letters[26];
        bool isLeaf;
    };
    
    
    Node* makeNode() {
        Node* node = new Node();
        for (int i = 0; i < 26; i++) {
            node->letters[i] = nullptr;
        }
        node->isLeaf = false;
        return node;
    };
    
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = makeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        int level = word.size();
        for (int i = 0; i < level; i++) {
            int key = word[i] - 'a';
            if (cur->letters[key] == nullptr) {
                cur->letters[key] = makeNode();
            }
            
            if (i == level - 1) {
                cur->letters[key]->isLeaf = true;
            }
            cur = cur->letters[key];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int key = word[i] - 'a';
            if (cur->letters[key] == nullptr) {
                return false;
            }
            if (i == word.size() - 1 && !cur->letters[key]->isLeaf) return false;

            cur = cur->letters[key];
        }
        return cur->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int key = prefix[i] - 'a';
            if (cur->letters[key] == nullptr) {
                return false;
            }
            cur = cur->letters[key];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */