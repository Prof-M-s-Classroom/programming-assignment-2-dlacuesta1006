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

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        std::ifstream file(filename);

        //Prints if the file could not open
        if (!file.is_open()) {
            std::cout << "Could not open file" << filename << std::endl;
            return;
        }
        std::unordered_map<int, Node<T>*> nodeMap;
        //To hold the event of every line in story.txt
        std::string line;

        while (std::getline(file, line)){
            std::stringstream ss(line);
            std::string eventStr, desc, leftStr, rightStr;

            //Following the format of the story.txt
            std::getline(ss, eventStr, delimiter);
            std::getline(ss, desc, delimiter);
            std::getline(ss, leftStr, delimiter);
            std::getline(ss, rightStr, delimiter);

            if (eventStr.empty() || leftStr.empty() || rightStr.empty()) {
                std::cout << "Invalid Line: " << line << "\n";
                continue;
            }

            //Changes the string numbers into int
            int eventNumber = std::stoi(eventStr);
            int leftNumber = std::stoi(leftStr);
            int rightNumber = std::stoi(rightStr);

            T story(desc, eventNumber, leftNumber, rightNumber);

            Node<T>* node = new Node<T>(story);

            nodeMap[eventNumber] = node;
        }

        //loop goes through the nodeMap and connects each node to its corresponding children.
        for (auto& pair : nodeMap){
            Node<T>* node = pair.second;
            if (nodeMap.count(node->data.leftEventNumber)) {
                node->left = nodeMap[node->data.leftEventNumber];
            }
            if (nodeMap.count(node->data.rightEventNumber)) {
                node->right = nodeMap[node->data.rightEventNumber];
            }
        }

        root = nodeMap.count(1) ? nodeMap[1] : nullptr;
        if (root == nullptr) {
            std::cout <<"Could not find root node\n" << std::endl;
        }
    }



    // TODO: Function to start the game and traverse the tree based on user input
    void playGame()
    {
        if (!root){
            std::cout << "No story";
            return;
        }

        Node<T>* current = root;
        while (current){
            std::cout << current->data.description << "\n";
            if (!current->left && !current->right) {
                std::cout << "Game Over!"<< std::endl;
            }


            std::cout << "choose path:\n";
            if (current->left) std::cout<< "1: Proceed left\n";
            if (current->right) std::cout<< "2: Proceed right\n";

            int choice;
            std::cout << "Type 1 or 2";
            std::cin >> choice;

            if (std::cin.fail() || (choice != 1 && choice != 2)){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid Option. Please enter 1 or 2.\n";
                continue;
            }


            if (choice == 1 && current->left) {
                current = current->left;
            }else if (choice == 2 && current->right){
                current = current->right;
            } else{
                std::cout << "Path does not Exist, Use another path\n";
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H