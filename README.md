# cute-sensors

A lightweight terminal UI for Linux hardware sensors with a cute and themeable interface.

---

## Features

- Real-time CPU/GPU temperature monitoring
- Lightweight C implementation
- ANSI color themes (cute / midnight)
- Smooth terminal rendering (low flicker)
- Theme switching at runtime (`t`)
- Exit with `q`

---

## Themes

- **cute** → warm, soft colors
- **midnight** → dark, technical, blue-based palette

Themes affect:
- Labels (CPU, GPU, etc.)
- Temperature colors
- Bar style (█ / ░)
- Header styling

---

## Controls

- `q` → quit
- `t` → switch theme

---

## Build

### Using Make
```bash
make
```

### Manual build
```bash
gcc main.c providers/sensors_provider.c renderers/terminal_renderer.c core/theme.c themes/*.c -o cute-sensors -Wall -Wextra -O2
```

---

## Run

```bash
./cute-sensors
```

---

## Requirements

- Linux
- gcc
- lm-sensors package

Install dependencies:

```bash
sudo apt install lm-sensors
```

---

## Idea

This project explores building a minimal terminal monitoring tool in C with a themeable architecture, inspired by modern TUI tools.

The focus is on:
- simplicity
- performance
- visual customization
- learning low-level terminal rendering

---

## Future ideas

- CPU usage graphs
- Memory usage
- Disk I/O stats
- Network monitoring
- Double-buffer rendering 
- Plugin-based sensor providers
- Config file for themes

---

## Author

Built as a learning project focused on terminal UI design and Linux system monitoring.