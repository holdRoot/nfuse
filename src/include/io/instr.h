#include <llist/LList.h>
#include <fsdefs.h>

class IOInstr : public LList
{
  private:
    const bsize offset;
    const bsize count;
    char *buff;

  public:
    IOInstr(const bsize &offset, const bsize &count, char *buff);
    ~IOInstr();

    const bsize getOffset();
    const bsize getCount();
    const char * getBuff();
};
