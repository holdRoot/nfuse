//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_LLIST_H
#define BTREE_LLIST_H

class LList
{
protected:
    LList * prev;
    LList * next;
public:
    LList();
    LList *
    getPrev() const;
    void
    setPrev(LList *prev);
    LList *
    getNext() const;
    void
    setNext(LList *next);
};

#endif //BTREE_LLIST_H
