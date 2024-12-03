cd out || exit
make
SDL_VIDEODRIVER=wayland ./rika-village
