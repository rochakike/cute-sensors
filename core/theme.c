#include "theme.h"

// Externos
extern Theme theme_cute;
extern Theme theme_midnight;

Theme* themes[] = {
    &theme_cute,
    &theme_midnight
};

int theme_index = 0;
Theme current_theme;

void apply_theme() {
    current_theme = *themes[theme_index];
}

void load_next_theme() {

    theme_index++;

    if (theme_index >= (int)(sizeof(themes)/sizeof(themes[0]))) {
        theme_index = 0;
    }

    apply_theme();
}
