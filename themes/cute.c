#include "../core/theme.h"

Theme theme_cute = {
    "cute",
    "\033[38;5;114m",
    "\033[38;5;221m",
    "\033[38;5;203m",
    .label = "\033[38;5;220m", // Amarillo cálido
    "\033[38;5;218m",
    "█",
    "░",
    .temp_low  = "\033[38;5;114m",
    .temp_mid  = "\033[38;5;221m",
    .temp_high = "\033[38;5;203m"
};
