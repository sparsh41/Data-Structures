#include "Trie.hpp"
#include <cstring>
#include <cctype>

Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(const std::vector<std::string>& v) {
    root = new TrieNode();
    for (std::string str : v) {
        insert(str);
    }
}

void Trie::insert(const std::string& s) {
    TrieNode* cur = root;

    for (char ch : s) {
        if (!isalpha(ch)) {
            continue;
        }

        int i = tolower(ch) - 'a';
        if (!cur->children[i]) {
            cur->children[i] = new TrieNode();
        }
        cur = cur->children[i];
    }
    cur->end_of_word = true;
}

bool Trie::search(const std::string& s) const {
    TrieNode* cur = root;

    for (char ch : s) {
        int i = tolower(ch) - 'a';

        if (!cur->children[i]) {
            return false;
        }
        cur = cur->children[i];
    }
    return cur->end_of_word;
}

void Trie::print() const {
    std::string word;
    print(root, word);
}

void Trie::print(TrieNode* node, std::string& word) const {
    if (!node) {
        return;
    }
    if (node->end_of_word) {
        std::cout << word << std::endl;
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            word = word + char(i + 'a');
            
            print(node->children[i], word);
            
            word.pop_back();
        }
    }
}

bool Trie::empty() const {
    return empty(root);
}

bool Trie::empty(TrieNode* node) const {
    for (TrieNode* child : node->children) {
        if (child) {
            return false;
        }
    }
    return true;
}

int Trie::countWords() const{
    return countWords(root);
}

int Trie::countWords(const TrieNode* node) const{
    if (!node) {
        return 0;
    }

    int count = (node->end_of_word)? 1 : 0;

    for (const auto& i : node->children) {
        count += countWords(i);
    }

    return count;
}

void Trie::remove(const std::string& word) {
    if (word.empty() || !root) {
        return;
    }
    
    root = remove(root, word, 0);
}

TrieNode* Trie::remove(TrieNode* node, const std::string& word, int depth) {
    if (!node) {
        return nullptr;
    }
    
    if (depth == word.length()) {
        node->end_of_word = false;

        if (empty(node) && (node != root)) {
            delete node;
            return nullptr;
        }

        return node;
    }
    
    int index = tolower(word[depth]) - 'a';
    node->children[index] = remove(node->children[index], word, depth + 1);

    if (empty(node) && !node->end_of_word && node != root) {
        delete node;
        return nullptr;
    }

    return node;
}

int Trie::longestWord() const {
    return longestWord(root, 0);
}

int Trie::longestWord(const TrieNode* node, int depth) const{
    if (!node) {
        return 0;
    }
    
    int max = (node->end_of_word)? depth : 0;

    for (const auto& i : node->children) {
        if (i) {
            int ch_max = longestWord(i, depth + 1);
            
            if (ch_max > max) {
                max = ch_max;
            }
        }
    }
    

    return max;
}