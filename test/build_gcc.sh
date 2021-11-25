g++ ./stn_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_unittest
g++ ./stn_memory_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_memory_unittest
g++ ./stn_string_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_string_unittest
g++ ./stn_string_sse_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_string_sse_unittest
g++ ./stn_math_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_math_unittest
g++ ./stn_random_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_random_unittest
gcc ./stn_c_unittest.c -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_c_unittest
