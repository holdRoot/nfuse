
#!/bin/bash

rsync -r . sys2:~/nfuse
ssh sys2 "cd nfuse; ./debug.sh"
rsync -r sys2:~/nfuse .
