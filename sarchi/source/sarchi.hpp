#pragma once

#include <vector>
#include <string>

#include "../logos/ArchSmall.hpp"
#include "shellcmd.hpp"

typedef struct components {
   std::string componentName;
   std::string componentValue;
   std::string componentColor;
} components;



/* Fix whatever the fuck happens when you set logocolor to none*/
const std::string LOGOCOLOR = "#1abc9c";
const std::string SPACE = "NONE";

// Removing newlines since without that we get '[ zsh' NEWLINE and then ']'
const std::string username = shellcmd("echo $USER | tr -d '\n'");

/* yup... */
const std::string distroName = shellcmd("cat /etc/*-release | grep 'PRETTY_NAME' | sed 's/PRETTY_NAME=//g' | tr -d '\n' | sed 's|\"||g'");
const std::string wmName = shellcmd("wmctrl -m | head -1 | awk '{print $2}' | tr -d '\n'"); /* Make sure to install wmctrl */

const size_t NUM_SPACES = 4; // the no of spaces between the logo and info stuff
const std::vector<components> ComponentSet = {
   /* Component's Name              Component's Value                            Component's Color */
   { "   Os:       ",            " "+distroName+"   ",                           "#1abc9c"},
   { "   Name:     ",            " "+username+"     ",                           "#9ece6a"},
   { "   Terminal: ",            " Kitty            ",                           "#f7768e"},
   { "   Theme:    ",            " Tokyonight-dark  ",                           "#7dcfff"},
   { "   Wm:       ",            " "+wmName+"       ",                           "#3d59a1"},
   { "   Shell:    ",            " Zsh              ",                           "#ff9e64"},
};
