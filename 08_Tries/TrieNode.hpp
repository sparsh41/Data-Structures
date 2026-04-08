#ifndef TRINODE_HPP
#define TRINODE_HPP

#define ALPHABET_SIZE 26

class TrieNode {
    public:
        TrieNode() : end_of_word(false) {
            // Initialize children with nullptr
            for (TrieNode* ch : children) {
                ch = nullptr;
            }
        }

        TrieNode* children[ALPHABET_SIZE];
        bool end_of_word;
};

#endif