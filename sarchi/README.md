# Sarchi

![Sarchi Image](./img/img.png?raw=true "Sarchi Image")
![Sarchi Doom One theme Image](./img/img-doomOne.png?raw=true "Sarchi Doom One theme Image")

<br>
A simple neofetch-like program.
Only Works in linux.
I use arch so it works in arch but should work in all linux distros

# Configuration
- Configure the program and components being loaded by changing sarchi.hpp
- Change the logo being loaded by making your own ascii logo in logos/ and include that in sarchi.hpp
- Always build the program after changing any of the source or header files

# Dependencies (Very optional)
- [wmctrl](https://github.com/saravanabalagi/wmctrl)
- [cperc](https://github.com/Keshavig/SP/tree/main/cperc)

If you prefer not to download these programs, simply remove the corresponding lines from sarchi.hpp and adjust the settings to your preference.

# Build
In sarchi directory, run following command
By default it install the binary in ~/.local/bin but the path can be easily changed in Makefile
```bash
make clean install
```
