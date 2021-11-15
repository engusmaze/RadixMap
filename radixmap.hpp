#pragma once
#include <cstring>

char *toBinaryChar(int value)
{
    char *arr = new char[4];
    arr[0] = value << 24 >> 24;
    arr[1] = value << 16 >> 24;
    arr[2] = value << 8 >> 24;
    arr[3] = value >> 24;
    return arr;
}

template <typename O>
class MapPart
{
public:
    O *value = new O;
    MapPart<O> *arr[256];
    MapPart()
    {
        // std::cout << "Create MapPart\n";
        for (int i = 0; i < 256; i++)
        {
            arr[i] = nullptr;
        }
    }
    ~MapPart()
    {
        // std::cout << "Delete MapPart\n";
        delete value;
        for (int i = 0; i < 256; i++)
        {
            if (arr[i])
            {
                // std::cout << i << '\n';
                delete arr[i];
            }
        }
    }
};

template <typename O>
class RadixMap
{
public:
    MapPart<O> *start = new MapPart<O>();
    // int bitsize = 8;
    RadixMap()
    {
        // bitsize = sizeof(T) * CHAR_BIT;
    }
    inline O *operator[](const char *key)
    {
        size_t size = strlen(key);

        MapPart<O> *result = start;
        for (size_t i = 0; i < size; i++)
        {
            unsigned char ch = key[i];
            if (!result->arr[ch])
            {
                result->arr[ch] = new MapPart<O>();
            }
            result = result->arr[ch];
        }

        return result->value;
    }
    void set(const char *key, O value)
    {
        *operator[](key) = value;
    }
    ~RadixMap()
    {
        delete start;
    }
};