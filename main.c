#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

#include "core/sensor_types.h"
#include "providers/provider.h"
#include "core/theme.h"

// renderer
void render_terminal(SensorData sensors[], int count);

struct termios original_termios;

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    
    // Mostrar cursor
    printf("\033[?25h");

    // Salir alternate screen
    printf("\033[?1049l");

    fflush(stdout);
}

void enable_raw_mode()
{
    tcgetattr(STDIN_FILENO, &original_termios);

    atexit(disable_raw_mode);

    struct termios raw = original_termios;

    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Entrar alternate screen
    printf("\033[?1049h");

    // Ocultar cursor
    printf("\033[?25l");

    fflush(stdout);
}

int key_pressed()
{

    struct timeval tv = {0L, 0L};

    fd_set fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}

int main()
{
    setvbuf(stdout, NULL, _IOFBF, 1024);

    SensorData sensors[MAX_SENSORS];

    enable_raw_mode();
    apply_theme();

    while (1)
    {
        int count = get_sensors_data(
            sensors,
            MAX_SENSORS);

        render_terminal(sensors, count);

        fflush(stdout);

        usleep(500000);

        if (key_pressed())
        {

            char c = getchar();

            if (c == 'q')
            {
                break;
            }

            if (c == 't')
            {
                load_next_theme();
            }
        }
    }

    return 0;
}
