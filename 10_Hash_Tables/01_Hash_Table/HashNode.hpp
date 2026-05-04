#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template <typename K, typename V>
class HashNode {
    public:
        HashNode(const K& key, const V& val) : key(key), value(val) {}

    K key;
    V value;
};

#endif