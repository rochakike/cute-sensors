#ifndef THEME_H
#define THEME_H

// Estructura base de un tema
typedef struct {
    const char* name;

    const char* cpu;
    const char* gpu;
    const char* nvme;
    const char* label;
    const char* header;

    const char* bar_full;
    const char* bar_empty;

    // Escala de temperatura
    const char* temp_low;
    const char* temp_mid;
    const char* temp_high;
} Theme;

// Tema activo global (lo usa el renderer)
extern Theme current_theme;

// API del sistema de temas
void apply_theme();
void load_next_theme();

#endif
