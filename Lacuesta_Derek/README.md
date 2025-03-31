[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Derek Lacuesta]`  
### **Student ID:** `[130801928]`  

---

## **1. Project Overview**
This project makes us build a text-based RPG that uses binary decision tree to help guide the gameplay. Each action or event in the game corresponds to a node. Player advance by making a choice of left or right or 1 and 2. We use a story.txt file that holds all of the event for the game.



---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → The main.cpp is the starting point of the program it starts the game by creating GameDecisionTree object, also loads the contents of the game from story.txt and starts the game traversal   
- **`GameDecisionTree.h`** → For the GameDecisionTree.h contains most of the bulk of the code and basically runs and makes the game for us.
- **`Node.h`** → The node.h file is a template class. It contains the data of a node with pointers to left and right child nodes
- **`Story.h`** → The story.h file contains the individual story events. It gives us the description of the event and the left, right numbers 
- **`story.txt`** → the story.txt has the eventnumber|description|leftEventNumber|rightEventNumber 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)
The decision tree is built by taking the contents of story.txt line by line. Then each line has a delimiter which is |. Then we make a story object that has values then with a corresponding Node object it is constructed. The nodes created is stored in a map nodeMap so we can have the parent and child nodes linking. If an event has -1 for a left or right child, it is a leaf node which means the end of the path.

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)
The game begins at the root node which would be "You wake up in a forest clearing. There are two paths." then it moves by decision from the player choice on a decision based tree. First the player would select a number 1 or 2 with 1 representing right and 2 represent left. If they chose a path and it does not exist it will show a message. Then when they finish with a leaf node they get a message saying game ended

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)
The GameDecisionTree class have functions that load the story from a file and also manages the game traversal. The loading function reads the story file, then creates Node objects for every Event description there is. Then links them to the given left and right event numbers.

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
I would say one major issue for me that was challenging was the way I was parsing the story file. I fixed/debugged it by adding little checks right after I write my code so I know what it was reading and hoow I could fix it.  

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
You wake up in a forest clearing. There are two paths.
choose path:
1: Proceed left
2: Proceed right
Type 1 or 22
You go right and find an old cabin.
choose path:
1: Proceed left
2: Proceed right
Type 1 or 22
The cabin is empty. You find a trapdoor leading downwards.
choose path:
1: Proceed left
2: Proceed right
Type 1 or 21
The trapdoor leads to an underground labyrinth.
choose path:
1: Proceed left
Type 1 or 21
You navigate the labyrinth and find an exit to a hidden valley.
Game Over!
choose path:
Type 1 or 21
Path does not Exist, Use another path
You navigate the labyrinth and find an exit to a hidden valley.
Game Over!


---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → O(n) n is the number of evnets
- **Searching for an event in the tree** → O(1) the map allows direct access 
- **Game traversal efficiency** → O(h) height of the tree 

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
I tested where the player inputs an invalid option and outputs a error message telling them to use number 1 or 2 

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
