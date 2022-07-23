#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
    Ý tưởng hàm test_strod :
        + Tạo 1 vòng lặp ngược từ vị trí cuối của chuỗi đến vị trí đầu với biến i.
        + Tạo 1 mảng trống để chứa các ký tự KHÁC SỐ.
        + Ta tra bảng mã ascii có được decimal của '0' -> '9' là từ 48 -> 57.
        + Nếu decimal(dùng ép kiểu int) của giá trị mảng tại i THUỘC 48 -> 57 (tức là SỐ)
            => Ta cộng dồn reg += ((int)**ptr - 48)*pow(10,mu) với mu là mũ tăng từ 0 lên.
               Trừ 48 để số trong khoảng 0 -> 9
            Ví dụ : 123 thì reg = 1*10^2 + 2*10^1 + 3*10^0
        + Nếu decimal(dùng ép kiểu int) của giá trị mảng tại i KHÁC 48 -> 57 (tức KHÁC SỐ)
            => Ta lưu giá trị đó vào mảng trống đã tạo trước đó. 
               (Lưu ý : do vòng lặp chạy ngược nên sẽ lưu các ký tự ngược từ dưới lên)
        + Sau khi thoát khỏi vòng lặp, ta đảo ngược mảng lại để có chuỗi ký tự không có số.
        + Return giá trị reg là số.
*/

int test_strod(char mang[], char **ptr)
{
    int reg = 0, mu = 0, id = 0;
    char mangchua[100];

    for(int i = strlen(mang) - 1; i >= 0; i--)
    {
        *ptr = &mang[i]; // Giá trị của con trỏ ngôi 1 = địa chỉ của mảng. => = p
                         // Cập nhật vị trí con trỏ 

        if((int)**ptr >= 48 && (int)**ptr <= 57) // **ptr = *p (*ptr = &mang[] = p) = mang[] => tức ký tự 
        {
            reg += ((int)**ptr - 48)*pow(10,mu);
            mu++;
        }

        if(((int)**ptr < 48 || (int)**ptr > 57))
        {
            mangchua[id] = **ptr;
            id++;
        }     
    }

    printf("\nChuoi: %s", strrev(mangchua));
    return reg;
}

int main()
{
    double ref;
    char mang[] = "I love 3000 you";
    char *p = &mang[strlen(mang)-1]; // Trỏ con trỏ tới vị trí cuối cùng của chuỗi

    printf("Mang : %s", mang);
    printf("\nSo : %d", test_strod(mang, &p));
}