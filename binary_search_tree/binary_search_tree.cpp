#include "binary_search_tree.h"

using namespace std;

template<class T>
BST<T>::Node::Node(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

template<class T>
T BST<T>::Node::getData() {
    return data;
}

template<class T>
unique_ptr<typename BST<T>::Node> BST<T>::Node::getLeft() {
    return left;
}

template<class T>
unique_ptr<typename BST<T>::Node> BST<T>::Node::getRight(){
    return right;
}

template<class T>
void BST<T>::Node::setLeft(unique_ptr<Node> left_ptr) {
    left = left_ptr;
}

template<class T>
void BST<T>::Node::setRight(unique_ptr<Node> right_ptr) {
    right = right_ptr;
}

template<class T>
BST<T>::BST() {
    root = nullptr;
    node_count = 0;
}

template<class T>
unique_ptr<typename BST<T>::Node> BST<T>::insert(unique_ptr<Node>& node, T new_value) {
    if (node == nullptr) {
        // If the current node is null, create a new node with the given value.
        node = make_unique<Node>(new_value);
        return true;
    }

    if (new_value < node->getData()) {
        // Recursively insert into the left subtree.
        node->setLeft(insert(node->getLeft(), new_value));
    } else {
        // Recursively insert into the right subtree.
        node->setRight(insert(node->getRight(), new_value));
    }
    return node;
}

