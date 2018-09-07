
#include <stdio.h>

#include <string>
#include <vector>

#define TRIE_MAX_CHAR_NUM   26

struct TrieNode {
    bool isEnd;
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    TrieNode(): isEnd(false) {
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
    }
    ~Trie() {
        for(int i = 0; i < _node_vec.size(); i++) {
            delete _node_vec[i];
        }
    }
    void insert(std::string word) {
        TrieNode* node = &_root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(node->child[index] == NULL) {
                node->child[index] = new_node();
            }
            node = node->child[index];
        }
        node->isEnd = true;
    }
    bool search(std::string word) {
        TrieNode* node = &_root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(node->child[index] == NULL) {
                return false;
            }
            node = node->child[index];
        }
        return node->isEnd;
    }
    bool startsWith(std::string prefix) {
        TrieNode* node = &_root;
        for(int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if(node->child[index] == NULL) {
                return false;
            }
            node = node->child[index];
        }
        return true;
    }
private:
    TrieNode* new_node() {
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode*> _node_vec;
    TrieNode _root;
};

int main(){
	Trie trie;
	trie.insert("abcde");
	printf("%d\n", trie.search("abcde"));
	printf("%d\n", trie.startsWith("abc"));
	printf("%d\n", trie.startsWith("abcdef"));
	printf("%d\n", trie.startsWith("abcde"));
	return 0;
}
