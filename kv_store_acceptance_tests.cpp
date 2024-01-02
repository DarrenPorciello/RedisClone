#include <iostream>
#include <vector>
#include "kv_store.h"

void testSetAndGet() {
    KeyValueStore store;
    std::string getResult;
    store.set("key1", "value1");
    store.get("key1", getResult);
    if (getResult == "value1") {
        std::cout << "Test Set and Get: Passed\n";
    } else {
        std::cout << "Test Set and Get: Failed\n";
    }
}

void testGetNonExistentKey() {
    KeyValueStore store;
    std::string getResult;
    store.get("nonExistentKey", getResult);
    if (getResult.empty()) {  // Assuming get returns empty string for non-existent keys
        std::cout << "Test Get Non-Existent Key: Passed\n";
    } else {
        std::cout << "Test Get Non-Existent Key: Failed\n";
    }
}

void testUpdate() {
    KeyValueStore store;
    std::string getResult;
    store.set("key2", "value2");
    store.update("key2", "newValue2");
    store.get("key2", getResult);
    if (getResult == "newValue2") {
        std::cout << "Test Update: Passed\n";
    } else {
        std::cout << "Test Update: Failed\n";
    }
}

void testLogFunction() {
    KeyValueStore store;
    store.set("key4", "value4");
    store.update("key4", "newValue4");
    store.del("key4");
    
    std::vector<std::string> logResult = store.get_log();
    // Implement a check for the logResult based on the expected log output
    // For example, check if the log contains entries for set, update, and delete operations
    std::cout << "Log output: \n";
    for (const auto& logEntry : logResult) {
        std::cout << logEntry << "\n";
    }
    std::cout << "Test Log Function: (Manual verification required)\n";
}

int main() {
    testSetAndGet();
    testGetNonExistentKey();
    testUpdate();
    testLogFunction();

    return 0;
}
