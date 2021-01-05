#ifndef STN_MEMORY_H
#define STN_MEMORY_H

// TODO(Oskar): Add support for memory pools.
// TODO(Oskar): Add supprot for stack based arena.

struct memory_arena
{
    void *Memory;
    u32 MemorySize;
    u32 MemoryAllocPosition;
    u32 MemoryLeft;
    u32 MinimumAlignment;
};

STN_INTERNAL memory_arena
MemoryArenaInit(void *Memory, u32 MemorySize, u32 Alignment = 8)
{
    memory_arena Arena = {};

    Arena.Memory = Memory;
    Arena.MemorySize = MemorySize;
    Arena.MemoryLeft = MemorySize;
    Arena.MinimumAlignment = Alignment;

    return (Arena);
}

STN_INTERNAL void *
MemoryArenaAllocate(memory_arena *Arena, u32 Size, u32 Alignment = 1)
{
    void *Memory = 0;

    if (Alignment < Arena->MinimumAlignment)
    {
        Alignment = Arena->MinimumAlignment;
    }

    if (Arena->MemoryAllocPosition + Size <= Arena->MemorySize)
    {
        Memory = (void *)((char *)Arena->Memory+Arena->MemoryAllocPosition);
        u32 BytesOffAlignment = (uintptr_t)Memory % (uintptr_t)Alignment;
        if (BytesOffAlignment != 0)
        {
            u32 Padding = Alignment - BytesOffAlignment;
            Memory = (char *)Memory + Padding;
            Size += Padding;
        }

        Arena->MemoryAllocPosition += Size;
        Arena->MemoryLeft -= Size;
    }

    return (Memory);
}

STN_INTERNAL void *
MemoryArenaAllocateAndZero(memory_arena *Arena, u32 Size, u32 Alignment = 1)
{
    void *Memory = MemoryArenaAllocate(Arena, Size, Alignment);
    if (Memory)
    {
        MemorySet(Memory, 0, Size);
    }

    return (Memory);
}

STN_INTERNAL void
MemoryArenaFreeBytes(memory_arena *Arena, u32 Size)
{
    if (Size > Arena->MemoryAllocPosition)
    {
        Arena->MemoryAllocPosition = 0;
        Arena->MemoryLeft = Arena->MemorySize;
    }
    else
    {
        Arena->MemoryAllocPosition -= Size;
        Arena->MemoryLeft += Size;
    }
}

STN_INTERNAL void
MemoryArenaClear(memory_arena *Arena)
{
    Arena->MemoryAllocPosition = 0;
    Arena->MemoryLeft = Arena->MemorySize;
}

STN_INTERNAL void
MemoryArenaZero(memory_arena *Arena)
{
    MemorySet(Arena->Memory, 0, Arena->MemorySize);
}

STN_INTERNAL char *
MemoryArenaAllocateCStringCopy(memory_arena *Arena, char *String)
{
    u32 StringLength = CalculateCStringLength(String);
    char *StringCopy = (char *)MemoryArenaAllocate(Arena, StringLength+1);
    
    if(StringCopy)
    {
        MemoryCopy(StringCopy, String, StringLength);
        StringCopy[StringLength] = 0;
    }
    
    return (StringCopy);
}

STN_INTERNAL b32
MemoryArenaWrite(memory_arena *Arena, void *Source, u32 Size)
{
    b32 Success = 0;
    
    if (Arena->MemoryLeft >= Size)
    {
        void *Destination = MemoryArenaAllocate(Arena, Size);
        MemoryCopy(Destination, Source, Size);
        Success = 1;
    }

    return (Success);
}

STN_INTERNAL b32
MemoryArenaRead(memory_arena *Arena, void *Destination, u32 Size)
{
    b32 Success = 0;

    if (Arena->MemoryLeft >= Size)
    {
        void *Source = MemoryArenaAllocate(Arena, Size);
        MemoryCopy(Destination, Source, Size);
        Success = 1;
    }

    return (Success);
}

#endif // STN_MEMORY_H