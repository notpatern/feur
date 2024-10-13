cmake ./ -G "MinGW Makefiles"
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ./
mingw32-make
PAUSE
