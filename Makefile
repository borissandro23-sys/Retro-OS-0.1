CC := gcc
LD := ld
GRUB_FILE := grub-file

CFLAGS := -m32 -std=gnu11 -ffreestanding -fno-pie -fno-stack-protector -fno-asynchronous-unwind-tables -O2 -Wall -Wextra
ASFLAGS := -m32 -ffreestanding -fno-pie
LDFLAGS := -m elf_i386 -T linker.ld

BUILD := build
ISO_ROOT := $(BUILD)/iso
KERNEL := $(BUILD)/kernel.elf
ISO := $(BUILD)/retro-os.iso

.PHONY: all clean check

all: $(ISO)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/boot.o: boot/boot.S | $(BUILD)
	$(CC) $(ASFLAGS) -c $< -o $@

$(BUILD)/kernel.o: kernel/kernel.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): $(BUILD)/boot.o $(BUILD)/kernel.o linker.ld
	$(LD) $(LDFLAGS) -o $@ $(BUILD)/boot.o $(BUILD)/kernel.o

check: $(KERNEL)
	$(GRUB_FILE) --is-x86-multiboot2 $(KERNEL)

$(ISO): $(KERNEL) grub/grub.cfg
	mkdir -p $(ISO_ROOT)/boot/grub
	cp $(KERNEL) $(ISO_ROOT)/boot/kernel.elf
	cp grub/grub.cfg $(ISO_ROOT)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_ROOT)

clean:
	rm -rf $(BUILD)
