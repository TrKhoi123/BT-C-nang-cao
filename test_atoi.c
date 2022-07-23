#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
    Y tuong : int(Decimal) cua ky tu '0' -> '9' la 48 -> 57 => chi can -48 se ra so 
              Ta cho vong lap chay tu duoi len va nhan 10^x voi x bat dau = 0 va tang dan len
    VD : 28976
         So = 6*10^0 + 7*10^1 + 9*10^2 + 8*10^3 + 2*10^4

*/

int test_atoi(char mang[])
{
    int so = 0;
    int mu = 0;
    for(int i = strlen(mang) - 1; i >= 0; i--)
    {
        so += ((int)mang[i] - 48)*pow(10,mu);
        mu++;
    }
    return so;
}

int main()
{
    char mang[] = "19283746";
    printf("Mang : %s", mang);
    printf("\nSo : %d", test_atoi(mang));
}