#include "list.h"
#include <iostream>
using namespace std;



List::List(const List &list): p(nullptr) {
    std::cout << "Копируется." << std::endl;
    if(list.p == nullptr){
        return;
    }
    listElement* currElement;
    currElement = list.p;
    p = new listElement;
    p->data = currElement->data;
    p->next = nullptr;

    listElement* lastElement = p;
    while(currElement->next != nullptr){
        lastElement->next = new listElement;
        currElement = currElement->next;
        lastElement = lastElement->next;
        lastElement->data = currElement->data;
        lastElement->next = nullptr;
    }   
}

List::List(List && list): p(list.p) {
        cout << "Перенос" << endl;
        list.p = nullptr;
    }

 void List::pushBack(int newData) {
    if(p == 0) {
        p = new listElement; 
        p->data = newData;
        p->next = 0;
    }       
    else {
        listElement* currElement;
        currElement = p;
        while(currElement->next!= 0) {
            currElement = currElement->next;
        }
        listElement* newElement;
        newElement = new listElement;
        newElement->data = newData;
        newElement->next = 0;
        currElement->next = newElement; 
    }
}

void List::pushFront(int newData) {
    listElement* newElement;
    newElement = new listElement;
    newElement->data = newData;
    newElement->next = p;
    p = newElement;
}

void List::printInfo() {
    listElement* currElement = p;
    while(currElement != 0){
        cout << currElement->data << " ";
        currElement = currElement->next;
    }   
    cout << endl;
}

int List::popBack() {
    if(p == 0) {
        return -1;
    }
    else {
        listElement* currElement = p;
        listElement* newElement = currElement->next;
        while (newElement->next != 0) {
            currElement = newElement;
            newElement = currElement->next;
        }
        currElement->next = 0;
        int result = newElement->data;
        delete newElement;
        return result;
    }
}

int List::popFront() {
    if(p == 0) {
        return -1;
    }
    else {
        listElement* currElement = p;
        p = currElement->next;
        int result = currElement->data;
        delete currElement;
        return result;
    }
}

void List::insertByIndex(int number, int index) {
    listElement* currElement = p;
    int num = 1;
    if(index == 0) {
        listElement* newElement;
        newElement = new listElement;
        newElement->data = number;
        newElement->next = p;
        p = newElement;
    }
    else{
        while(num != index) {
            currElement = currElement->next;
            ++ num;
            }
        listElement* newElement;
        newElement = new listElement;
        newElement->data = number;
        newElement->next = currElement->next;
        currElement->next = newElement;
        }
}

int List::deleteByIndex (int index) {
    if(p == 0) {
        return - 1;
    }
    listElement* currElement = p; 
    if(index == 0){
        p = currElement->next;
        int data = currElement->data;
        delete currElement;
        return data;
    }
    for(int i = 0; i < index - 1; ++i) {
        currElement = currElement->next;
    }
    listElement* deleteElement = currElement->next;
    (*currElement).next = deleteElement->next;
    int data = deleteElement->data;
    delete deleteElement;
    return data;
}

int List::size() {
    int size = 0;
    listElement* currElement = p;
    while(currElement != 0){
        size++;
        currElement = currElement->next;
    }
    return size;
}

int List::getElementByIndex(int index){
    if(p == 0){
        return -1;
    }
    int size = 0;
    listElement* currElement = p;
    while(size != index){
        size++;
        currElement = currElement->next;
    }
    return currElement->data;
}