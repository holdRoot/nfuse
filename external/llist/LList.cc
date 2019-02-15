//
// Created by Mohammad Yazdani on 2019-02-10.
//

#include "LList.h"
LList::LList() : prev(nullptr), next(nullptr) {}
LList *
LList::getPrev() const
{
    return prev;
}
void
LList::setPrev(LList *prev)
{
    LList::prev = prev;
}
LList *
LList::getNext() const
{
    return next;
}
void
LList::setNext(LList *next)
{
    LList::next = next;
}
