#include <stdio.h>

int main()
{
    int a = 0xDDCCAABB;
    int x;
    int y;
    unsigned char c;

    for (int i = 0; i < 32; i += 8)
    {
        c = (a >> i) & 0xFF;
        printf("byte[%d] = %x\n", (i / 8) + 1, c);
    }

    printf("enter 1 byte 16th number: ");

    scanf("%x", &x);

    a = (a & 0xDD00AABB);

    a = (a >> 16) | x;

    a = (a << 16) | 0xAABB;

    printf("change 3rd bytes: %x\n", a);

    return 0;
}