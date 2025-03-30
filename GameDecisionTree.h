#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    unordered_map<int, Node<T>*> nodeMap;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Could not open file!" << endl;
            return;
        }
        cout << "file: " <<filename << endl;


        string line;
        while (getline(file,line)) {
            stringstream ss(line);
            string desc;
            int num, left, right;

            getline(ss, desc, delimiter);
            ss >> num >> left >> right;

            Story story(desc, num, left, right);

            if (nodeMap.find(num) == nodeMap.end()) {
                nodeMap[num] = new Node<T>(story);
            } else {
                nodeMap[num]->data = story;
            }
            if (root == nullptr) {
                root = nodeMap[num];
            }
        }
        for (auto& pair : nodeMap) {
            Story& story = pair.second->data;
            if (story.leftEventNumber != -1) {
                if (nodeMap.find(story.leftEventNumber) == nodeMap.end()) {
                    nodeMap[story.leftEventNumber] = new Node<T>(Story("Missing", story.leftEventNumber, -1, -1));
                }
                pair.second->left = nodeMap[story.leftEventNumber];
            }
            if (story.rightEventNumber != -1) {
                if (nodeMap.find(story.rightEventNumber) == nodeMap.end()) {
                    nodeMap[story.rightEventNumber] = new Node<T>(Story("Missing", story.rightEventNumber, -1, -1));
                }
                pair.second->right = nodeMap[story.rightEventNumber];
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* current = root;
        while (current) {
            cout << "Event " << current->data.eventNumber << ": " << current->data.description << endl;
            if (!current->left && !current->right) {
                cout << "Game Failed!" << endl;
                break;
            }
            cout << "Press 1 for left or 2 for right: ";
            int choice;
            cin >> choice;

            if (choice == 1 && current->left) {
                current = current->left;
            } else if (choice == 2 && current->right) {
                current = current-> right;
            } else {
                cout << "Invalid Choice." << endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H