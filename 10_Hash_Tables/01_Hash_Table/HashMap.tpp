#include "HashMap.hpp"
#include <iostream>

template <typename K, typename V>
HashMap<K, V>::HashMap(int size) : n(0) {
    data.resize(size, nullptr);

    deleted = new HashNode<K, V>(K(), V());
}


template <typename K, typename V>
bool HashMap<K, V>::empty() const {
    return n == 0;
}

template <typename K, typename V>
bool HashMap<K, V>::full() const {
    return n == data.size();
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const {
    return key % data.size();
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    if (full()) {
        return;
    }

    // Find the hash
    int index = hash(key);

    while (data[index] && data[index] != deleted) {
        index = (index + 1) % data.size();  // Go to the next position
    }

    // Insert the node
    data[index] = new HashNode<K,V>(key, value);
    n++;
}

template <typename K, typename V>
void HashMap<K, V>::print() const {
    for (int i = 0; i < data.size(); i++) {
        std::cout << i << " ";
        if (data[i] == nullptr) {
            std::cout << "nullptr\n";
        }
        else if (data[i] == deleted) {
            std::cout << "deleted\n";
        }
        else {
            std::cout << "{ " << data[i]->key << "; " << data[i]->value << " }\n";
        }
    }
}
