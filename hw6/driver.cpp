#include "binarytree.h"
#include "binarysearchtree.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

void visit(int nodeData);

int main(){
    BinarySearchTree<int> numberTree;
    const auto now = std::chrono::system_clock::now();
    const std::time_t currTimeSeed = std::chrono::system_clock::to_time_t(now);
    srand(currTimeSeed); //removed need for static cast B)

    std::vector<int> numberSet;

    while(numberSet.size() < 100) {
        int randomInt = std::rand() % 200 + 1;
        if (std::find(numberSet.begin(), numberSet.end(), randomInt) == numberSet.end()) {
            numberSet.push_back(randomInt);
        }
    }

    for(int i = 0; i < numberSet.size(); i++) {
        numberTree.add(numberSet[i]);
    }
    std::fstream output;
    output.open("output.txt", std::ios_base::out);
    output << "Height: " << numberTree.getHeight() << std::endl;
    output << "Preorder Traversal: " << std::endl;
    output.close();
    numberTree.preOrderTraverse(&visit);

    output.open("output.txt", std::ios_base::app);
    output << "Inorder Traversal: " << std::endl;
    output.close();
    numberTree.inOrderTraverse(&visit);

    output.open("output.txt", std::ios_base::app);
    output << "Postorder Traversal: " << std::endl;
    output.close();
    numberTree.postOrderTraverse(&visit);

    return 0;
}
void visit(int nodeData) {
    //std::cout << nodeData << ",";
    std::fstream output;
    output.open("output.txt", std::ios_base::app);
    output << nodeData << ",";
    output.close();
}