#include <stdio.h>
#include <vector>
#include <string>

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    bool isEnd;
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    TrieNode(): isEnd(false) {
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
    }
    ~WordDictionary() {
        for(int i = 0; i < _node_vec.size(); i++) {
            delete _node_vec[i];
        }
    }
    void addWord(std::string word) {
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
		return Trie_DFS(node, word.c_str());
    }
private:
    bool Trie_DFS(TrieNode* node, const char *word) {
		if(*word == '\0') {
			return node->isEnd;
		}
		if(*word == '.') {
			for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++ ) {
				if (node->child[i] != NULL && Trie_DFS(node->child[i], word + 1)) {
					return true;
				}
			}
		}
		else {
			int index = *word - 'a';
			if (node->child[index] != NULL &&
				Trie_DFS(node->child[index], word + 1)) {
				return true;
			}
		}
		return false;
    }
    TrieNode* new_node() {
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode*> _node_vec;
    TrieNode _root;
};

int main(){
	WordDictionary word_dictionary;
	word_dictionary.addWord("bad");
	word_dictionary.addWord("dad");
	word_dictionary.addWord("mad");
	printf("%d\n", word_dictionary.search("pad"));
	printf("%d\n", word_dictionary.search("bad"));
	printf("%d\n", word_dictionary.search(".ad"));
	printf("%d\n", word_dictionary.search("b.."));
	return 0;
}
