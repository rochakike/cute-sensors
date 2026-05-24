#include "../core/theme.h"

Theme theme_midnight = {
    "midnight",
    "\033[38;5;75m",
    "\033[38;5;111m",
    "\033[38;5;203m",
    .label = "\033[38;5;81m", // Azul eléctrico fuerte
    "\033[38;5;75m",
    "█",
    "·",
    .temp_low  = "\033[38;5;81m",
    .temp_mid  = "\033[38;5;111m",
    .temp_high = "\033[38;5;196m"
};
