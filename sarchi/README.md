# Sarchi

![Sarchi Image](./img/img.png?raw=true "Sarchi Image")

<br>
A simple neofetch-like program.
Only Works in linux.
I use arch so it works in arch but should work in all linux distros

# Configuration
- Configure the program by changing `sarchi.hpp` or by just changing the source file (`sarchi.cpp`)
- Make sure to build the program after changing `sarchi.hpp` or `sarchi.cpp`

# Build
Go into source directory and then run following command
```bash
clang++ sarchi.cpp colors.cpp shellcmd.cpp -o sarchi -Wall -Wextra -Werror -O3

```

# TODO 

- Add support for running bash commands \[KINDA DONE\]
- Add MakeFile
