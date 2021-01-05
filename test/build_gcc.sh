g++ ./stn_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_unittest
g++ ./stn_memory_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -o ./stn_memory_unittest
g++ ./stn_string_unittest.cpp -DBUILD_LINUX=1 -DBUILD_WINDOWS=0 -Wc++11-compat-deprecated-writable-strings -o ./stn_string_unittest