#pragma once

#include <vector>
#include <string>

typedef struct components {
   std::string componentName;
   std::string componentValue;
   std::string componentColor;
} components;


const std::vector<std::string> ARCHLINUX_LOGO = {

   "         /\\      ",
   "        /  \\     ",
   "       /    \\    ",
   "      /  __  \\   ",
   "     /  (  )  \\  ",
   "    /___|  |___\\ "
};

const std::string LOGOCOLOR = "#7aa2f7";

const size_t NUM_SPACES = 1; // the no of spaces between the logo and info stuff
const std::vector<components> ComponentSet = {
   { "Name: ",        "Ke",                         "#73daca"},
   { "Os: ",          "Arch Linux",                 "#73daca"},
   { "Terminal: ",    "Kitty",                      "#ff9e64"},
   { "Font: ",        "JetBrainsMono Nerd Font",    "#ff9e64"},
   { "Shell: ",       "Zsh",                        "#9ece6a"},
   { "Wm: ",          "Dwm",                        "#9ece6a"},
};
