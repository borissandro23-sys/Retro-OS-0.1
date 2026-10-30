#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((volatile uint16_t*)0xB8000)
#define COLOR(fg, bg) ((uint8_t)(((bg) << 4) | (fg)))

static size_t cursor_row = 0;
static size_t cursor_col = 0;
static uint8_t terminal_color = COLOR(15, 1);

static void clear_screen(void) {
    const uint16_t blank = (uint16_t)(' ' | ((uint16_t)terminal_color << 8));
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; ++i) {
        VGA_MEMORY[i] = blank;
    }
    cursor_row = 0;
    cursor_col = 0;
}

static void put_char(char c) {
    if (c == '\n') {
        cursor_col = 0;
        if (++cursor_row >= VGA_HEIGHT) cursor_row = 0;
        return;
    }

    VGA_MEMORY[cursor_row * VGA_WIDTH + cursor_col] =
        (uint16_t)c | ((uint16_t)terminal_color << 8);

    if (++cursor_col >= VGA_WIDTH) {
        cursor_col = 0;
        if (++cursor_row >= VGA_HEIGHT) cursor_row = 0;
    }
}

static void print(const char* text) {
    while (*text) put_char(*text++);
}

void kernel_main(void) {
    terminal_color = COLOR(15, 1);
    clear_screen();

    print(" RETRO OS 0.1\n");
    print(" --------------------------------------------------------------\n");
    print("\n");
    print("      Welcome to Retro OS!\n");
    print("\n");
    print("      The kernel booted successfully.\n");
    print("      Architecture : x86 (32-bit)\n");
    print("      Boot protocol: GRUB / Multiboot2\n");
    print("\n");
    print(" --------------------------------------------------------------\n");
    print(" STATUS: KERNEL RUNNING\n");
    print("\n");
    print(" Next milestone: keyboard input and a tiny command shell.\n");

    for (;;) {
        __asm__ volatile ("hlt");
    }
}
