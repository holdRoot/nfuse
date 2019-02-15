#include <fs/fcache.h>

#include <iostream>

IOInstr * FCache::cacheQueue = nullptr;

void
FCache::setup()
{
    cacheQueue = new IOInstr();
}

void
FCache::push(IOInstr * io)
{
    cacheQueue->setNext(io);
}

IOInstr *
FCache::flush()
{
    auto head = cacheQueue;

    while(head){
        std::cout << "Wrote -> " << 
        head = head->getNext();
    }
    

    return head;
}
