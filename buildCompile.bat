cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ./
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ./
mingw32-make
PAUSE
