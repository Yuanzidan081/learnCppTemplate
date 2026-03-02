#include <iostream>
#include "foldtraverse.hpp"
#include "addspace.hpp"
int main()
{
    // foldtraverse.hpp Test
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->left->right = new Node(3);
        // traverse binary tree: root->left->right
        Node* node = traverse(root, left, right);
        std::cout << "root->left->right value: " << node->value << std::endl;

        Node* node2 = traverse(root, left);
        std::cout << "root->left value: " << node2->value << std::endl;

        Node *node3 = traverse(root);
        std::cout << "root value: " << node3->value << std::endl;
    }
    // addspace.hpp Test
    {
        print(1, 2.5, "hello", 'A');
    }
    return 0;
}
