#include <iostream>
#include "list.h"

int main () {
    List list;
    list.pushBack(1); 
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(7);
    list.deleteByIndex(6);
    list.printInfo();

    std::cout << "размер: " << first.size() << std::endl;

    List listCopy(list);
    listCopy.printInfo();
    std::cout << std::endl;
    listCopy.deleteByIndex(2);
    listCopy.printInfo();
    std::cout << std::endl;
    list.printInfo();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    listCopy.deleteByIndex(0);
    listCopy.printInfo();
    std::cout << std::endl;
    list.printInfo();

    List listMove(std::move(list));
    list.printInfo();
    listMove.printInfo();
}