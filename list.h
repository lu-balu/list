#ifndef LIST_H
#define LIST_H

struct listElement {
    int data;
    listElement* next; 
};

class List {
public:
    List() : p(0) {}
    List(const List &list);
    List(List && list);

    void pushBack(int newData); 
    void pushFront(int newData);
    void printInfo();
    int popBack();
    int popFront();
    void insertByIndex(int number, int index);
    int deleteByIndex(int index);
    int size();
    int getElementByIndex(int index);

private:
    listElement* p;
};

#endif // LIST_H