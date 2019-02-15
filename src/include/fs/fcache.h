#include <io/instr.h>

class FCache
{
private:
    // TODO : Here should be a queue
    static IOInstr * cacheQueue;
public:
    static void setup();

    // TODO : These operations are atomic
    void push(IOInstr * io);
    IOInstr * flush();
};
