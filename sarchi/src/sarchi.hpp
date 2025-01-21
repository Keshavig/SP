#pragma once

#include <vector>
#include <string>

#include "../logos/ArchSmall.hpp"

typedef struct components {
   std::string componentName;
   std::string componentValue;
   std::string componentColor;
} components;



const std::string LOGOCOLOR = "#ff007c";
const std::string SPACE = "NONE";

const size_t NUM_SPACES = 4; // the no of spaces between the logo and info stuff
const std::vector<components> ComponentSet = {
   //Component's Name            // Component's Value                // Component's Color
   { "",                            "[ ke@archi ]       ",                           "#7dcfff"},
   { "[ Name ]     -> ",            "[ ke ]             ",                           "#1abc9c"},
   { "[ Terminal ] -> ",            "[ Kitty ]          ",                           "#1abc9c"},
   { "[ Theme ]    -> ",            "[ Tokyonight-dark ]",                           "#3d59a1"},
   { "[ Wm ]       -> ",            "[ Dwm ]            ",                           "#3d59a1"},
   { "[ Shell ]    -> ",            "[ Zsh ]            ",                           "#ff9e64"},
};
