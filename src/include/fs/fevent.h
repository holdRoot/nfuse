#include "fsdefs.h"

class FEvent
{
private:
    EVENT_ID id;
    
public:
    static void setup();

    FEvent(/* args */);
    ~FEvent();
};

FEvent::FEvent(/* args */)
{
}

FEvent::~FEvent()
{
}
