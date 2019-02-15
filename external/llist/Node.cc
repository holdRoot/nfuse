//
// Created by Mohammad Yazdani on 2019-02-10.
//
#include <iostream>
#include "Node.h"

Node::Node(NVal value, void *data)
    : value(value), data(data), lo(nullptr), hi(nullptr) {}

NVal
Node::getValue() const
{
    return value;
}

void
Node::print(std::string offset, bool forward)
{
    std::cout << offset << getValue() << std::endl;
    if (forward && getNext())
        getNext()->print(offset, forward);
    else if (!forward && getPrev())
        getPrev()->print(offset, forward);
}

Node *
Node::push(Node *node)
{
    if (node->value > value)
    {
        if (getNext())
        {
            getNext()->push(node);
        }
        else
        {
            putForward(node);
        }
    }
    else
    {
        if (getPrev() && getPrev()->value > node->value)
        {
            getPrev()->push(node);
        }
        else
        {
            putBehind(node);
        }
    }
    return nullptr;
}
Node *
Node::getPrev()
{
    return (Node *) prev;
}
Node *
Node::getNext()
{
    return (Node *) next;
}
void
Node::putBehind(Node *node)
{
    auto org_behind = getPrev();
    if (org_behind)
    {
        org_behind->setNext(node);
        node->setPrev(org_behind);
    }
    setPrev(node);
    node->setNext(this);
}
void
Node::putForward(Node *node)
{
    auto org_forward = getNext();
    if (org_forward)
    {
        org_forward->setPrev(node);
        node->setNext(org_forward);
    }
    setNext(node);
    node->setPrev(this);
}
void
Node::pop()
{
    auto left = getPrev();
    auto right = getNext();
    left->setNext(right);
    right->setPrev(left);
}
void
Node::split()
{
    auto left = getPrev();
    auto right = getNext();
    left->setNext(nullptr);
    right->setPrev(nullptr);
    setPrev(nullptr);
    setNext(nullptr);
    // TODO : set lo and hi
}
Node *
Node::closest(NVal val)
{
    if (val > value)
    {
        if (getNext())
        {
            return getNext()->closest(val);
        }
        else
        {
            return this;
        }
    }
    else
    {
        if (getPrev() && getPrev()->value > val)
        {
            return getPrev()->closest(val);
        }
        else
        {
            return this;
        }
    }
}
BPTree *
Node::getLo() const
{
    return lo;
}
BPTree *
Node::getHi() const
{
    return hi;
}
