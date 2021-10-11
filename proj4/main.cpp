#include "BinarySearchTree.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>

int main() {
    // Generate 100 unique random numbers
    std::vector<int> nums;
    srand(time(NULL));
    while (nums.size()< 10) {
        int x;
        do {
            x = rand() % 200 + 1;
        } while (std::find(nums.begin(), nums.end(), x) != nums.end());
        nums.push_back(x);
    }

    BinarySearchTree<int> tree;

    std::cout << "Random Numbers:" << "\n";
    for (int i : nums) {
        std::cout << i << " ";
        tree.add(i);
    }

    std::cout << "\n-------------------------\n";

    std::cout << "Preorder: ";
    tree.preorderTraverse();
    std::cout << "\n";
    std::cout << "Inorder: ";
    tree.inorderTraverse();
    std::cout << "\n";
    std::cout << "Postorder: ";
    tree.postorderTraverse();

    std::cout << "\n\nHeight: " << tree.getHeight() << "\n";
    std::cout << "Total Node Count: " << tree.getNumberOfNodes() << "\n";
    std::cout << "Root Node: " << tree.getRootData() << "\n";

}