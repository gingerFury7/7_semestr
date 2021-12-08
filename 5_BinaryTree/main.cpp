#include <iostream>
#include "string"
#include "List.h"
#include "BinaryTree.h"

using namespace std;


int main() {
    List list;
    srand(time(NULL));
    int n = 10;
    for (int i = 0; i < n; i++){
        list.push_front( rand() % 1000);
    }
    list.print();
    list.search(57);
}
