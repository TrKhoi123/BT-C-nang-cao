#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

float test_strof(char chuoi[], char **ptr)
{
    char chuoi_chua[10000];
    int index = 0;
    int mu = 0, tong = 0;
    while((int)**ptr == 32) // Khi nào trước số là khoảng trắng -> tăng *ptr = p = &chuoi[] tức tăng địa chỉ
    {
        *ptr += 1;
    }
    while((int)**ptr != 32 && (int)**ptr >= 48 && (int)**ptr <= 57)
    {
        chuoi_chua[index] = **ptr;
        // printf("\nGiatri : %c", chuoi_chua[index]);
        index++;
        
        *ptr += 1;
    }

    // printf("\nDo dai : %d", strlen(chuoi_chua));
    for(int z = strlen(chuoi_chua)-1; z >= 0; z--)
    {
        tong += ((int)chuoi_chua[z] - 48)*pow(10,mu);
        mu++;
    }
    return tong;
}

int main()
{
    char chuoi[] = "123 456 789";
    printf("\nChuoi : %s", chuoi);
    char* p = &chuoi[0];

    float f1 = test_strof(chuoi, &p);
    printf("\nf1 = %f", f1);
    printf("\nVi tri p sau khoang trang 1 bac = %c", *(p+1));

    float f2 = test_strof(chuoi, &p);
    printf("\nf2 = %f", f2);
    printf("\nVi tri p sau khoang trang 1 bac = %c", *(p+1));

    float f3 = test_strof(chuoi, &p);
    printf("\nf3 = %f", f3);
}