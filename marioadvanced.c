#include <cs50.h>
#include <stdio.h>

int yukseklik;
int column;
int row;
int bosluk;
int main(void)
{
    do
    {
    yukseklik = get_int("Kulenin yuksekligi kac olmasini istersiniz?: ");
    }
    while(yukseklik < 0 || yukseklik > 8);

    for(row = 0; row < yukseklik; row++)
    {
        for(bosluk = 0; bosluk < yukseklik - row - 1; bosluk++)
        {
            printf(" ");
        }
        for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");
        for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}