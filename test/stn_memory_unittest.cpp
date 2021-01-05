#include "../HyperTest/code/hypertest.cpp"
#define STN_USE_MEMORY
#include "../stn.h"

struct byte8
{
    u32 Number1;
    u32 Number2;
};

TEST(STN_Memory, MemoryArenaInit)
{
    void *Memory = (void *)malloc(1024);
    memory_arena Arena = MemoryArenaInit(Memory, 1024);

    UNITTEST_ASSERT_EQUAL(Arena.Memory, Memory);
    UNITTEST_ASSERT_EQUAL(Arena.MemorySize, 1024);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 1024);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);

    void *OtherMemory = (void *)malloc(512);
    memory_arena ArenaWithAlignment = MemoryArenaInit(OtherMemory, 512, 16);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.Memory, OtherMemory);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemorySize, 512);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MemoryLeft, 512);
    UNITTEST_ASSERT_EQUAL(ArenaWithAlignment.MinimumAlignment, 16);

    free(Memory);
    free(OtherMemory);
}


TEST(STN_Memory, MemoryArenaAllocate)
{
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256);

    UNITTEST_ASSERT_EQUAL(Arena.Memory, Memory);
    UNITTEST_ASSERT_EQUAL(Arena.MemorySize, 256);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);

    UNITTEST_EXPECT_EQUAL(sizeof(byte8), 8);
    byte8 *AllocatedStruct = (byte8 *)MemoryArenaAllocate(&Arena, sizeof(byte8));
    AllocatedStruct->Number1 = 5;
    AllocatedStruct->Number2 = 10;

    UNITTEST_ASSERT_EQUAL(AllocatedStruct->Number1, 5);
    UNITTEST_ASSERT_EQUAL(AllocatedStruct->Number2, 10);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 8);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - 8);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);
    
    MemoryArenaAllocate(&Arena, 50);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 58);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - 58);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, 8);
    
    free(Memory);
}

TEST(STN_Memory, MemoryArenaAllocateAlignment)
{
    u32 FirstArenaAlignment = 11;
    u32 Padding = 0;
    void *Memory = (void *)malloc(256);
    u32 BytesOffAlignment = (uintptr_t)Memory % (uintptr_t)FirstArenaAlignment;

    if (BytesOffAlignment != 0)
    {
        Padding = FirstArenaAlignment - BytesOffAlignment;
    }

    memory_arena Arena = MemoryArenaInit(Memory, 256, FirstArenaAlignment);
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, FirstArenaAlignment);

    byte8 *AllocatedStruct = (byte8 *)MemoryArenaAllocate(&Arena, sizeof(byte8), 7);
    
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, sizeof(byte8) + Padding);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - (sizeof(byte8) + Padding));
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, FirstArenaAlignment);

    byte8 *AllocatedStruct2 = (byte8 *)MemoryArenaAllocate(&Arena, sizeof(byte8), 1);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, (sizeof(byte8) + Padding + FirstArenaAlignment));
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - (sizeof(byte8) + Padding + FirstArenaAlignment));
    UNITTEST_ASSERT_EQUAL(Arena.MinimumAlignment, FirstArenaAlignment);

    free(Memory);
}

TEST(STN_Memory, MemoryArenaAllocateAndZero)
{
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256);

    char *ZeroedMemory = (char *)MemoryArenaAllocateAndZero(&Arena, 256);
    for (u32 Index = 0; Index < 256; ++Index)
    {
        char *Value = ZeroedMemory + Index;
        UNITTEST_EXPECT_EQUAL(*Value, 0);
    }

    void *SecondMemory = (void *)malloc(256);
    memory_arena SecondArena = MemoryArenaInit(SecondMemory, 256);
    
    // NOTE(Oskar): Make memory not zeroed.
    for (u32 Index = 0; Index < 256; ++Index)
    {
        char *Value = (char *)SecondMemory + Index;
        *Value = Index;
    }

    // NOTE(Oskar): Zero Memory
    char *SecondZeroedMemory = (char *)MemoryArenaAllocateAndZero(&SecondArena, 256);
    for (u32 Index = 0; Index < 256; ++Index)
    {
        char *ZeroedMemoryValue = SecondZeroedMemory + Index;
        char *MemoryValue = (char *)SecondMemory + Index;
        
        UNITTEST_EXPECT_EQUAL(*ZeroedMemoryValue, 0);
        UNITTEST_EXPECT_EQUAL(*MemoryValue, 0);
    }

    free(Memory);
}

TEST(STN_Memory, MemoryArenaFreeBytes)
{
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256);
    MemoryArenaAllocateAndZero(&Arena, 128);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 128);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 128);

    MemoryArenaFreeBytes(&Arena, 50);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 128 - 50);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 128 + 50);
    
    MemoryArenaFreeBytes(&Arena, 500);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256);

    free(Memory);
}

TEST(STN_Memory, MemoryArenaClear)
{
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256);
    MemoryArenaAllocateAndZero(&Arena, 128);

    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 128);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 128);

    MemoryArenaAllocateAndZero(&Arena, 16);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 128 + 16);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 128 - 16);

    MemoryArenaClear(&Arena);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, 0);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256);

    free(Memory);
}

TEST(STN_Memory, MemoryArenaAllocateCStringCopy)
{
    char *String = "Nullsson";
    void *Memory = (void *)malloc(256);
    memory_arena Arena = MemoryArenaInit(Memory, 256);

    char *StringCopy = MemoryArenaAllocateCStringCopy(&Arena, String);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryAllocPosition, CalculateCStringLength(String) + 1);
    UNITTEST_ASSERT_EQUAL(Arena.MemoryLeft, 256 - (CalculateCStringLength(String) + 1));
    UNITTEST_ASSERT_EQUAL(CalculateCStringLength(String), CalculateCStringLength(StringCopy));
    
    for(u32 Index = 0; Index < CalculateCStringLength(String); ++Index)
    {
        UNITTEST_EXPECT_EQUAL(String[Index], StringCopy[Index]);
    }

    free(Memory);
}