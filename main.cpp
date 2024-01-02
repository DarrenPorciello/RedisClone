#include "kv_store.h"
#include <iostream>
#include <sstream>

int main() {
    // create an instance of KeyValueStore to manage key-value pairs and logs
    KeyValueStore kv_store;
    std::string command, key, value;

    // loop to interact with the KeyValueStore until the "quit" command is entered
    while (true) {
        std::cout << "enter a command (set/get/delete/update/log/quit): ";
        std::cin >> command;

        // perform actions based on user input commands
        if (command == "set") {
            // get key-value pair from user input
            std::cin >> key >> value;
            // set the key-value pair in the KeyValueStore
            int result = kv_store.set(key, value);
            if (result == 0) {
                std::cout << "key-value pair set." << std::endl;
            } else {
                std::cout << "failed to set key-value pair." << std::endl;
            }
        } else if (command == "get") {
            // get value associated with a key from user input
            std::cin >> key;
            std::string result;
            // retrieve the value associated with the key from the KeyValueStore
            int get_status = kv_store.get(key, result);
            if (get_status == 0) {
                std::cout << "value: " << result << std::endl;
            } else {
                std::cout << "failed to get the value." << std::endl;
            }
        } else if (command == "delete") {
            // remove a key from the KeyValueStore based on user input
            std::cin >> key;
            int result = kv_store.del(key);
            if (result == 0) {
                std::cout << "key deleted." << std::endl;
            } else {
                std::cout << "failed to delete the key." << std::endl;
            }
        } else if (command == "update") {
            // update a key with a new value based on user input
            std::cin >> key >> value;
            int result = kv_store.update(key, value);
            if (result == 0) {
                std::cout << "key updated." << std::endl;
            } else {
                std::cout << "failed to update the key." << std::endl;
            }
        } else if (command == "log") {
            // retrieve and display the log of operations performed on the KeyValueStore
            std::vector<std::string> log = kv_store.get_log();
            if (log.empty()) {
                std::cout << "command log is empty." << std::endl;
            } else {
                std::cout << "command log:" << std::endl;
                for (const std::string& entry : log) {
                    std::cout << entry << std::endl;
                }
            }
        } else if (command == "quit") {
            // exit the program
            break;
        } else {
            // handling invalid commands
            std::cout << "invalid command. please try again." << std::endl;
        }
    }

    return 0;
}
