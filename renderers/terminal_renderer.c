#include <stdio.h>
#include <string.h>

#include "../core/sensor_types.h"
#include "../core/theme.h"

#define BAR_WIDTH 24

void print_bar(float temp, const char* color)
{
    int filled = (int)(temp / 4);

    if (filled > BAR_WIDTH)
        filled = BAR_WIDTH;

    // Parte llena (color dinámica)
    for (int i = 0; i < filled; i++)
        printf("%s%s\033[0m", color, current_theme.bar_full);

    // Parte vacía (theme)
    for (int i = filled; i < BAR_WIDTH; i++)
        printf("%s", current_theme.bar_empty);
}

const char* get_temp_color(float temp)
{
    if (temp >= 75)
        return current_theme.temp_high;

    if (temp >= 60)
        return current_theme.temp_mid;

    return current_theme.temp_low;
}

const char* get_color(const char* label, float temp)
{
    if (strstr(label, "Core") || strstr(label, "CPU"))
        return current_theme.cpu;

    if (strstr(label, "GPU"))
        return current_theme.gpu;

    (void)temp;

    return current_theme.nvme;
}

void print_header()
{
    printf(
        "%s%s\033[0m ",
        current_theme.header,
        "cute-sensors");

    printf("\033[38;5;244mv0.1\033[0m\n\n");
}

void render_footer()
{
    printf(
        "\033[38;5;244m[q]uit   [t]heme: %s\033[0m",
        current_theme.name);
}

void render_terminal(SensorData sensors[], int count)
{
    printf("\033[H"); 

    print_header();

    for (int i = 0; i < count; i++)
    {
        printf("\033[2K");

        //  LABEL (theme fijo)
        printf("%s%-14s\033[0m ",
               current_theme.label,
               sensors[i].label);

        //  TEMP COLOR (dinámico)
        const char *temp_color = get_temp_color(sensors[i].temperature);

        printf("%s%5.1f°C\033[0m ",
               temp_color,
               sensors[i].temperature);

        //  BAR (usa color de temp)
        print_bar(sensors[i].temperature, temp_color);

        printf("\n");
    }

    printf("\n");

    printf("\033[2K");

    render_footer();

}
