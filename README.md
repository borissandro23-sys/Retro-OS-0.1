# Retro OS 0.1

**Retro OS** is a Linux-based, bootable gaming system inspired by RetroArch and console-style gaming distributions.

The project uses the Linux kernel for hardware support and Libretro/RetroArch for emulation. Retro OS will provide its own startup experience, game library, controller setup and system settings.

> Early development project. The current repository still contains a tiny freestanding-kernel experiment from the first prototype; it is not the bootable gaming system yet.

## Direction

- **Base system:** Debian GNU/Linux (x86_64)
- **Emulation:** RetroArch + Libretro cores
- **Initial interface:** RetroArch Ozone/XMB menu, customized for Retro OS
- **Input:** USB gamepads and keyboard
- **Image format:** bootable x86_64 ISO for VirtualBox and PC hardware

## Planned components

| Component | Purpose |
|---|---|
| Linux kernel | Hardware, storage, USB, graphics and audio support |
| RetroArch | Libretro frontend and core loader |
| Libretro cores | Emulation of supported systems |
| Retro OS shell | Startup, library, settings and shutdown experience |
| Game library | Organize user-provided games, artwork and metadata |

## First milestones

1. [ ] Build a minimal x86_64 Linux live ISO
2. [ ] Boot directly into a console-style Retro OS interface
3. [ ] Include RetroArch and a small set of redistributable Libretro cores
4. [ ] Configure keyboard and common USB gamepads
5. [ ] Add game library scanning and per-system playlists
6. [ ] Add persistent saves and configuration
7. [ ] Test in VirtualBox and on physical PCs

## Build plan

The first Linux-based image will be built with Debian Live tooling in GitHub Actions. This avoids requiring a Linux installation on the developer's Windows PC.

The old freestanding C kernel experiment is kept in the repository as a learning prototype. It is not used as the kernel of the Linux-based release.

## Legal notes

RetroArch and Libretro cores have their own licenses. Each core must be distributed in accordance with its individual license. Retro OS will not include copyrighted game ROMs or BIOS files; users must provide files they are legally entitled to use.

## Contributing

See the repository issues and roadmap before proposing new features.
