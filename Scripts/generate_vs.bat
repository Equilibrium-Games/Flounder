cd ../
mkdir Build
cd Build
cmake .. -G "Visual Studio 15 2017 Win64" -DBUILD_SHARED_LIBS:BOOL=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build .
pause
