#include "AVL.h"
#include <cassert>

void testIsEmpty() {
    AVL<int> avlTree;
    assert(avlTree.isEmpty());

    avlTree.insert(42);
    assert(!avlTree.isEmpty());
}

void testTop() {
    AVL<int> avlTree;

    avlTree.insert(42);
    assert(avlTree.top() == 42);

    avlTree.insert(23);
    assert(avlTree.top() == 42);
}

void testSize() {
    AVL<int> avlTree;
    assert(avlTree.size() == 0);

    avlTree.insert(42);
    assert(avlTree.size() == 1);

    avlTree.insert(23);
    assert(avlTree.size() == 2);
}

void testInsert() {
    AVL<int> avlTree;
    assert(avlTree.insert(42));
    assert(!avlTree.insert(42));

    avlTree.insert(23);
    avlTree.insert(56);
    assert(avlTree.insert(12));
}

void testContains() {
    AVL<int> avlTree;
    assert(!avlTree.contains(42));

    avlTree.insert(42);
    assert(avlTree.contains(42));

    avlTree.insert(23);
    avlTree.insert(56);
    assert(avlTree.contains(23));
    assert(!avlTree.contains(99));
}

void testHeight(){
    AVL<int> avlTree;

    avlTree.insert(10);
    avlTree.insert(5);
    avlTree.insert(15);
    avlTree.insert(3);
    avlTree.insert(8);

    assert(avlTree.height() == 2);
    avlTree.insert(20);
    avlTree.insert(25);
    avlTree.insert(30);
    assert(avlTree.height() == 3);
}

void testClear(){
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(4);
    avlTree.insert(2);
    avlTree.insert(7);
    avlTree.insert(6);
    avlTree.insert(8);
    avlTree.clear();
    assert(avlTree.isEmpty());
}

void testRemove() {
    AVL<int> avlTree;
    assert(!avlTree.remove(99));
    avlTree.insert(42);
    avlTree.insert(23);
    avlTree.insert(56);
    assert(!avlTree.remove(99));
    assert(avlTree.remove(42));
    assert(avlTree.remove(56));
    assert(avlTree.remove(23));

    avlTree.insert(42);
    avlTree.insert(23);
    avlTree.insert(56);
    avlTree.insert(12);
    avlTree.insert(37);
    assert(avlTree.remove(23));
    assert(!avlTree.contains(23));
    assert(avlTree.contains(42));
    assert(avlTree.contains(56));
    assert(avlTree.contains(12));
    assert(avlTree.contains(37));
    assert(avlTree.remove(42));
    assert(!avlTree.contains(42));
    assert(avlTree.remove(12));
    assert(!avlTree.contains(12));
    assert(avlTree.contains(56));
    assert(avlTree.contains(37));
}

void testTraverseInorder() {
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(8);

    vector<int> result = avlTree.traverse(AVL<int>::INORDER);
    vector<int> expected = {2, 3, 4, 5, 6, 7, 8};
    assert(result == expected);
}

void testTraversePreorder() {
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(8);

    vector<int> result = avlTree.traverse(AVL<int>::PREORDER);
    vector<int> expected = {5, 3, 2, 4, 7, 6, 8};
    assert(result == expected);
}

void testTraversePostorder() {
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(8);

    vector<int> result = avlTree.traverse(AVL<int>::POSTORDER);
    vector<int> expected = {2, 4, 3, 6, 8, 7, 5};
    assert(result == expected);
}

void testTraverseLevelorder() {
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(2);
    avlTree.insert(4);
    avlTree.insert(6);
    avlTree.insert(8);

    vector<int> result = avlTree.traverse(AVL<int>::LEVELORDER);
    vector<int> expected = {5, 3, 7, 2, 4, 6, 8};
    assert(result == expected);
}

void runAllTests() {
    testIsEmpty();
    testTop();
    testSize();
    testInsert();
    testContains();
    testHeight();
    testClear();
    testRemove();
    testTraverseInorder();
    testTraversePreorder();
    testTraversePostorder();
    testTraverseLevelorder();
}

int main(){
    runAllTests();
}
