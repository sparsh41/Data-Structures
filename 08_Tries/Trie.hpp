#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <vector>
#include "TrieNode.hpp"

class Trie {
    public:
        Trie();
        Trie(const std::vector<std::string>& v);

        void insert(const std::string& s);
        bool search(const std::string& s) const;

        bool empty() const;

        int countWords() const;
        int longestWord() const;
        void remove(const std::string& word);

        void print() const;

    private:
        TrieNode* root;
        void print(TrieNode* node, std::string& word) const;
        int countWords(const TrieNode* node) const;
        int longestWord(const TrieNode* node, int depth) const;
        TrieNode* remove(TrieNode* node, const std::string& word, int depth);
        bool empty(TrieNode* node) const;
};

#endif