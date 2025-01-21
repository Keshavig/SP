#pragma once

#include <vector>
#include <string>

#include "logos/ArchNeofetch.hpp"

typedef struct components {
   std::string componentName;
   std::string componentValue;
   std::string componentColor;
} components;



const std::string LOGOCOLOR = "#7aa2f7";
const std::string SPACE = "NONE";

const size_t NUM_SPACES = 4; // the no of spaces between the logo and info stuff
const std::vector<components> ComponentSet = {
   //Component's Name            // Component's Value                // Component's Color
   { "",                         "ke@archi",                       "#ff007c"},
   { "Name: ",                   "Ke",                             "#f7768e"},
   { "Os: ",                     "Arch Linux",                     "#914c54"},
   { "Terminal: ",               "Kitty",                          "#ff9e64"},
   { "Font: ",                   "JetBrainsMono Nerd Font",        "#e0af68"},
   { "Shell: ",                  "Zsh",                            "#9ece6a"},
   { "Theme: ",                  "Tokyonight-dark",                "#1abc9c"},
   { "TextEditor : ",            "Neovim",                         "#41a6b5"},
   { "WindowManager: ",          "Dwm",                            "#449dab"},
};
