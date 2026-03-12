`cvulkan.h` and `cvulkan.c` written by [botondmester](https://github.com/botondmester)

## Building
```
sudo apt install libvulkan1 vulkan-validationlayers
./compile.sh
./main
```

## Running on Wayland (swaywm)
```
VK_DRIVER_FILES=/usr/share/vulkan/icd.d/nvidia_icd.json ./main
```

## Known issues
- vkQueuePresentKHR spins the CPU to 100% usage while waiting for the next VSync'd frame. Need manual sleep
- When the window is tiled on Sway, the lower part of the screen stays un-updated like old solitaire
- Resizing can randomly freeze the application on both Cinnamon DE, X11 and Sway, Wayland
- Doesn't run on my swaywm (wayland) setup without the `VK_DRIVER_FILES=...` thing
