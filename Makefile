PROG=hello
OBJDIR=.obj
CC=g++-8

CFLAGS = -Wall --std=c++0x -fpermissive `pkg-config fuse --cflags` -DFUSE_USE_VERSION=26 -I /usr/local/Cellar/boost/1.68.0_1/include -L /usr/local/Cellar/boost/1.68.0_1/lib -I ..
LDFLAGS = `pkg-config fuse --libs`

$(shell mkdir -p $(OBJDIR)) 

OBJS = $(OBJDIR)/hello.o $(OBJDIR)/helloFS.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(PROG)

-include $(OBJS:.o=.d)

$(OBJDIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $*.cpp -o $(OBJDIR)/$*.o
	$(CC) -MM $(CFLAGS) $*.cpp > $(OBJDIR)/$*.d
	@mv -f $(OBJDIR)/$*.d $(OBJDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.o:|' < $(OBJDIR)/$*.d.tmp > $(OBJDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $(OBJDIR)/$*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $(OBJDIR)/$*.d
	@rm -f $(OBJDIR)/$*.d.tmp

clean:
	rm -rf $(PROG) $(OBJDIR)

