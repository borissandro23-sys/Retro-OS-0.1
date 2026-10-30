# Retro OS 0.1

A small educational operating-system project. The first milestone is a bootable **32-bit x86 BIOS ISO** that starts a freestanding C kernel and writes directly to VGA text memory.

> This is an early prototype, not a daily-use operating system.

## Current milestone

- GRUB 2 / Multiboot2 boot protocol
- Freestanding C kernel (no host operating-system runtime)
- VGA text-mode welcome screen
- Reproducible ISO build through GNU Make
- GitHub Actions build artifact

## Build on Ubuntu/Debian

Install the tools:

```sh
sudo apt update
sudo apt install build-essential grub-pc-bin grub-common xorriso
```

Build:

```sh
make
```

The image is created at `build/retro-os.iso`.

## Run in VirtualBox

1. Create a new VM named **Retro OS**.
2. Select **Other / Unknown (32-bit)** as the OS type.
3. Allocate 64–128 MB RAM.
4. Under Storage, attach `build/retro-os.iso` to the virtual optical drive.
5. Keep the VM firmware in BIOS mode (disable EFI).
6. Start the VM.

## Project layout

- `boot/boot.S` — Multiboot2 header and 32-bit entry point
- `kernel/kernel.c` — first C kernel and VGA text output
- `linker.ld` — kernel memory layout
- `grub/grub.cfg` — GRUB menu
- `Makefile` — local build
- `.github/workflows/build.yml` — automated ISO build

## Roadmap

1. [x] Boot a freestanding kernel and show a welcome screen
2. [ ] Keyboard input and command shell
3. [ ] Basic memory-map parsing and memory manager
4. [ ] Interrupts and timer
5. [ ] Simple graphics interface
6. [ ] Filesystem support

## License

MIT — see [LICENSE](LICENSE).
