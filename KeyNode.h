
#ifndef HW_3_KEYNODE_H
#define HW_3_KEYNODE_H
#include <iostream>
#include "ostream"
template<typename KEY>
class Dictionary;
template<typename KEY>

class KeyNode{
friend class Dictionary<KEY>;
//a
private:
    KEY key;
    int value;
    KeyNode<KEY>* next;
    KeyNode<KEY>* prev;
public:
    KEY getKey() const{return key;}

    int getValue() const{return value;}



    KeyNode() {
        next=NULL;
        prev=NULL;
    }
    KeyNode(KEY key,int value) : key(key),value(value) {
        next=NULL;
        prev=NULL;
    }
    KeyNode(KEY key) : key(key){
        next=NULL;
        prev=NULL;
    }
    KeyNode & operator=(const KeyNode & other){
        this->key=other.key;
        this->next=other.next;
        this->value=other.value;
        return *this;

    }
};
#endif
