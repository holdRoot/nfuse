//
// Created by Mohammad Yazdani on 2019-02-10.
//

#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <vector>
#include <string>
#include <unistd.h>
#include "LList.h"

class BPTree;

typedef long long int NVal;

class Node : public LList
{
private:
    NVal value;
    void *data;
    BPTree *lo;
    BPTree *hi;

    Node *
    getPrev();

    Node *
    getNext();

    void
    putBehind(Node *node);

    void
    putForward(Node *node);
public:
    Node(NVal value, void *data);

    NVal
    getValue() const;

    BPTree *
    getLo() const;

    BPTree *
    getHi() const;

    Node *
    closest(NVal val);

    Node *
    push(Node *node);

    void
    pop();

    void
    split();

    // TODO : For test
    void
    print(std::string offset, bool forward);
};

#endif //BTREE_NODE_H
