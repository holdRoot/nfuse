#include <instr.h>

IOInstr::IOInstr(const bsize &offset, const bsize &count, char *buff)
    : offset(offset), count(count), buff(buff)
{}

IOInstr::~IOInstr()
{
    delete buff;
}

const bsize
IOInstr::getOffset()
{
    return offset;
}

const bsize
IOInstr::getCount()
{
    return count;
}

const char *
IOInstr::getBuff()
{
    return buff;
}
