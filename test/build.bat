set CommonCompilerFlags=-nologo /Zi 
set CommonLinkerFlags=-incremental:no

cl %CommonCompilerFlags% -DBUILD_WINDOWS=1 -DBUILD_LINUX=0 -D_CRT_SECURE_NO_WARNINGS stn_unittest.cpp /link %CommonLinkerFlags%
cl %CommonCompilerFlags% -DBUILD_WINDOWS=1 -DBUILD_LINUX=0 -D_CRT_SECURE_NO_WARNINGS stn_memory_unittest.cpp /link %CommonLinkerFlags%