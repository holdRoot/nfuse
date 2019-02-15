
#!/bin/bash

rm -rf build
rsync -r ./ sys2:~/nfuse
ssh sys2 "cd nfuse; ./debug.sh"
rsync -r sys2:~/nfuse/ .
scp sys2:~/nfuse/compile_commands.json .
