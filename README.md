`cvulkan.h` and `cvulkan.c` written by [botondmester](https://github.com/botondmester)

## Building
```
sudo apt install libvulkan1 vulkan-validationlayers
./compile.sh
./a.out
```

## Running on Wayland (swaywm)
```
VK_DRIVER_FILES=/usr/share/vulkan/icd.d/nvidia_icd.json ./a.out
```

## Known issues
- 100% CPU usage on my computer even though VSync should be enabled
- Resizing can randomly freeze the application
- Doesn't run on my swaywm (wayland) setup without the `VK\_DRIVER\_FILES=...` thing
