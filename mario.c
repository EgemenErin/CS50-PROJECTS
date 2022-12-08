#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int tall, sira, yukseklik, bosluk;
    do
    {
        tall = get_int("How tall would you like the tower to be? ");
    }
    while(tall < 1 || tall > 8);

    for(sira = 0; sira < tall; sira++)
    {
        for(bosluk = 0; bosluk < tall - sira - 1; bosluk++)
        {
            printf(" ");
        }
        for(yukseklik = 0; yukseklik <= sira; yukseklik++)
        {
            printf("#");
        }
        printf("\n");
    }
}