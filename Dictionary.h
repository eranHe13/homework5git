//
// Created by noame on 12/26/2021.
//

#ifndef HW_3_DICTIONARY_H
#define HW_3_DICTIONARY_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "KeyNode.h"

using namespace std;
//a
template<class KEY>
class Dictionary {

private:

    KeyNode<KEY> *head;
    int counter;
public:
    //constructor
    Dictionary();

    //destructor
    ~Dictionary();
// add the key in the right place in the list
    void insertAtFront(KEY & key,int data);

    void insertAtAfter(KEY & nextNode, KEY & node,int data);
// print the dictionary
    void printDic() const;
//get the size of the dic
    int size();
//find key in the dic
    KEY &findBy(KEY &key);
//delete node by key from the dic
    bool deleteKey(KEY &key);
// copy the dic
    Dictionary<KEY> & operator=(const Dictionary<KEY>& other);
// delete all the node from the dic
    void clear();
// find key with specific location;
    KEY & operator[](int index);

    int operator[](int index)const;
    // "print" operator ostream out
    friend ostream &operator<<(ostream &out, const Dictionary<KEY> &dictionary) {
        KeyNode<KEY> *temp = dictionary.head;
        while (temp != NULL) {
            out << *temp->getKey() << " " << temp->getValue() << endl;
            temp = temp->next;
        }
        return out;
    }

};

template<class KEY>
Dictionary<KEY>::Dictionary() : head(NULL), counter(0) {}

template<class KEY>
Dictionary<KEY>::~Dictionary() {
    KeyNode<KEY> *node = head;
    KeyNode<KEY> *temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        delete temp;
    }
    counter=0;
    head=NULL;
}


template<class KEY>
void Dictionary<KEY>::insertAtFront(KEY & keyToAdd,int data) {

    if (head == NULL) {
        head = new KeyNode<KEY>();
        head->key=keyToAdd;
        head->value=data;
        head->next = NULL;
        head->prev = NULL;
        counter++;
        return;

    } else {

        /// four cases
        /// 1. insert to the begging of the list
        /// 2. insert on middle of list( before bigger element)
        /// 3. insert in the end of the list
        /// 4 .equle to the key - return and end the function ;

        //case 1 - enter in the begging of the list
        if (keyToAdd < head->key) {
            KeyNode<KEY> *newKey = new KeyNode<KEY>();
            newKey->key=keyToAdd;
            newKey->value=data;
            newKey->next = head;
            head->prev = newKey;
            head = newKey;
            counter++;
            return;
        }

        KeyNode<KEY> *temp = head;


        while (temp->next != NULL) {
            if (keyToAdd == temp->key) {//same key return

                return;
            }
            if (keyToAdd < temp->key) {
                insertAtAfter(temp->key, keyToAdd,data);
                return;
            }
            temp = temp->next;
        }
        //add last in the array;
        KeyNode<KEY> *newKey = new KeyNode<KEY>();
        newKey->key=keyToAdd;
        newKey->value=data;
        temp->next = newKey;
        newKey->prev = temp;
        counter++;
        newKey->next = NULL;

    }
}

template<class KEY>
int Dictionary<KEY>::size() {
    return counter;
}

template<class KEY>
void Dictionary<KEY>::insertAtAfter(KEY & nextNode, KEY & newNode,int data) {


    KeyNode<KEY> *temp = head;
    while (temp->next->key != nextNode) {
        temp = temp->next;
    }
    KeyNode<KEY> *newKey = new KeyNode<KEY>();
    newKey->key=newNode;
    newKey->value=data;
    newKey->next = temp->next;
    newKey->prev = temp;
    temp->next = newKey;
    counter++;

}

template<class KEY>
void Dictionary<KEY>::printDic() const {
    KeyNode<KEY> *temp = head;
    while (temp->next != NULL) {
        cout << temp->key << " " << temp->value << endl;
        temp = temp->next;
    }

}

template<class KEY>
KEY &Dictionary<KEY>::findBy(KEY &key) {
    KeyNode<KEY> *temp = head;

    while (temp->next != NULL) {
        if (temp->key == key) {
            int toReturn = temp->value;
            delete temp;
            return toReturn;
        }
    }
    delete temp;
    return -1;
}

template<class KEY>
bool Dictionary<KEY>::deleteKey(KEY &key) {
    //if the Node to delete is the head ;
    if (counter == 0) {
        //list empty
        return false;
    }
    KeyNode<KEY> *temp = head;
    if (head != NULL && head->key == key) {
        head->next = head;
        head->prev = NULL;
        delete temp;
        temp = NULL;
        counter--;
        return true;
    }
}

template<class KEY>
void Dictionary<KEY>::clear() {
    while (head) {
        KeyNode<KEY> *temp = head;
        head = head->next;
        delete temp;
    }
    counter = 0;
    head = NULL;
}

template<class KEY>
Dictionary<KEY> &Dictionary<KEY>::operator=(const Dictionary<KEY> &OldNode) {
    if (this != &OldNode) {
        clear();
        KeyNode<KEY> *temp = OldNode.head;

        while (temp) {
            insertAtFront(temp->key,temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template<class KEY>
KEY &Dictionary<KEY>::operator[](int index) {
    if (index < 0 || index >= counter) {
     //out of range
        return NULL ;
    }
    KeyNode<KEY> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->key;
}

template<class KEY>
int Dictionary<KEY>::operator[](int index) const {
    if (index < 0 || index >= counter) {
        //out of range
        return -1;
    }
    KeyNode<KEY> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->value;
}



#endif //HW_3_DICTIONARY_H
