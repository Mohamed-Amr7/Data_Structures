#include "binary_search_tree.h"
#include <cassert>

void testIsEmpty() {
    BST<int> testTree;
    assert(testTree.isEmpty());

    testTree.insert(42);
    assert(!testTree.isEmpty());
}

void testTop() {
    BST<int> testTree;

    testTree.insert(42);
    assert(testTree.top() == 42);

    testTree.insert(23);
    assert(testTree.top() == 42);
}

void testSize() {
    BST<int> testTree;
    assert(testTree.size() == 0);

    testTree.insert(42);
    assert(testTree.size() == 1);

    testTree.insert(23);
    assert(testTree.size() == 2);
}

void testInsert() {
    BST<int> testTree;
    assert(testTree.insert(42));
    assert(!testTree.insert(42));

    testTree.insert(23);
    testTree.insert(56);
    assert(testTree.insert(12));
}
void testClear(){
    BST<int> testTree;
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4);
    testTree.insert(2);
    testTree.insert(7);
    testTree.insert(6);
    testTree.insert(8);
    testTree.clear();
    assert(testTree.isEmpty());
}
void testHeight(){
    BST<int> testTree;
    testTree.insert(5);
    testTree.insert(3);
    testTree.insert(4);
    testTree.insert(2);
    testTree.insert(7);
    testTree.insert(6);
    testTree.insert(8);
    testTree.insert(13);
    assert(testTree.height() == 4);

    testTree.clear();
    assert(testTree.height() == 0);
    testTree.insert(42);
    assert(testTree.height() == 1);
}

void testRemove() {
    BST<int> testTree;
    assert(!testTree.remove(99));
    testTree.insert(42);
    testTree.insert(23);
    testTree.insert(56);
    assert(!testTree.remove(99));
    assert(testTree.remove(42));
    assert(testTree.remove(56));
    assert(testTree.remove(23));

    testTree.insert(42);
    testTree.insert(23);
    testTree.insert(56);
    testTree.insert(12);
    testTree.insert(37);
    assert(testTree.remove(23));
    assert(!testTree.contains(23));
    assert(testTree.contains(42));
    assert(testTree.contains(56));
    assert(testTree.contains(12));
    assert(testTree.contains(37));
    assert(testTree.remove(42));
    assert(!testTree.contains(42));
    assert(testTree.remove(12));
    assert(!testTree.contains(12));
    assert(testTree.contains(56));
    assert(testTree.contains(37));
}


void testContains() {
    BST<int> testTree;
    assert(!testTree.contains(42));

    testTree.insert(42);
    assert(testTree.contains(42));

    testTree.insert(23);
    testTree.insert(56);
    assert(testTree.contains(23));
    assert(!testTree.contains(99));
}

void runAllTests() {
    testIsEmpty();
    testTop();
    testSize();
    testClear();
    testInsert();
    testContains();
    testHeight();
    testRemove();
}

int main(){
    runAllTests();
}
