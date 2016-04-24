class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isLeaf;
    
    TrieNode() {
        memset(next,0,sizeof(next));
        isLeaf = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* par = root;
        int idx = 0;
        for(int i=0; i<word.size(); ++i){
            idx = word[i]-'a';
            if(par->next[idx]==NULL){
                par->next[idx] = new TrieNode();
            }
            par = par->next[idx];
        }
        par->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* par = root;
        int idx  = 0;
        for(int i=0; i<word.size(); ++i){
            idx = word[i]-'a';
            if(par->next[idx]==NULL){
                return false;
            }
            par = par->next[idx];
        }
        if(par->isLeaf)
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* par = root;
        int idx  = 0;
        for(int i=0; i<prefix.size(); ++i){
            idx = prefix[i]-'a';
            if(par->next[idx]==NULL){
                return false;
            }
            par = par->next[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
