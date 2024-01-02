#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include <string>
#include <vector>
#include "binary_search_tree.h"

class KeyValueStore {
public:
    KeyValueStore(); // constructor

    // sets a key-value pair in the store
    int set(const std::string& key, const std::string& value);
    
    // gets the value associated with a given key
    int get(const std::string& key, std::string& result);
    
    // removes a key and its associated value from the store
    int del(const std::string& key);
    
    // updates the value associated with a key
    int update(const std::string& key, const std::string& new_value);
    
    // retrieves the log of operations performed on the key-value store
    std::vector<std::string> get_log();

private:
    BinarySearchTree<std::string, std::string> bst; // binary search tree to store key-value pairs
    std::vector<std::string> log; // log of operations performed on the key-value store

    // gets the current time as a formatted string
    std::string get_current_time();
};

#endif
