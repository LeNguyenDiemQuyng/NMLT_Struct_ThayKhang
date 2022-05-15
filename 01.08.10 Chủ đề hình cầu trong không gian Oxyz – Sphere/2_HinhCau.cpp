#include<iostream>
#include<cmath>
using namespace std;

struct diemkhonggian //120
{
    float x;
    float y;
    float z;
};
typedef struct diemkhonggian DIEMKHONGGIAN;

struct hinhcau //120
{
    DIEMKHONGGIAN I;
    float R;
};
typedef struct hinhcau HINHCAU;

void NhapDiem(DIEMKHONGGIAN&);
void XuatDien(DIEMKHONGGIAN);
void Nhap(HINHCAU&);
void Xuat(HINHCAU);
float DienTich(HINHCAU);
float TheTich(HINHCAU);
float KhoangCach(DIEMKHONGGIAN, DIEMKHONGGIAN);
int KtThuoc(HINHCAU, DIEMKHONGGIAN);
int TuongDoi(HINHCAU, HINHCAU);


int main()
{
    HINHCAU c1;
    cout << "Nhap hinh cau thu nhat: \n";
    Nhap(c1);
    cout << "Hinh cau thu nhat la: \n";
    Xuat(c1);

    HINHCAU c2;
    cout << "\nNhap hinh cau thu hai: \n";
    Nhap(c2);
    cout << "Hinh cau thu hai la: \n";
    Xuat(c2);

    cout << "\nDien tich xung quanh hinh cau thu nhat la:";
    cout << DienTich(c1);

    cout << "\nThe tich xung quanh hinh cau thu nhat la:";
    cout << TheTich(c1);

    DIEMKHONGGIAN a;
    cout << "\nNhap diem a: \n";
    NhapDiem(a);

    if (KtThuoc(c1, a))
        cout << "\nDiem a thuoc duong tron thu nhat";
    else
        cout << "\nDiem a khong thuoc duong tron thu nhat";

    cout << "\nVi tri tuong doi giua hai hinh cau la: ";
    if (TuongDoi(c1, c2) == 0)
        cout << "\nHai hinh cau trung nhau";
    else if (TuongDoi(c1, c2) == 1)
        cout << "\nHai hinh cau roi nhau";
    else if (TuongDoi(c1, c2) == 2)
        cout << "\nHai hinh cau tiep xuc ngoai";
    else if (TuongDoi(c1, c2) == 3)
        cout << "\nHai hinh cau cat nhau";
    else if (TuongDoi(c1, c2) == 4)
        cout << "\nHai hinh cau tiep xuc trong";
    else
        cout << "\nHai hinh cau chua trong nhau";

    return 0;
}

void NhapDiem(DIEMKHONGGIAN& a)
{
    cout << "Nhap hoanh do: ";
    cin >> a.x;
    cout << "Nhap tung do: ";
    cin >> a.y;
    cout << "Nhap cao do: ";
    cin >> a.z;
}

void XuatDiem(DIEMKHONGGIAN a)
{
    cout << "\nHoanh do la: ";
    cout << a.x;
    cout << "\nTung do la: ";
    cout << a.y;
    cout << "\nCao do la: ";
    cout << a.z;
}

void Nhap(HINHCAU& c) //121
{
    cout << "Nhap tam:\n";
    NhapDiem(c.I);
    cout << "Nhap ban kinh: ";
    cin >> c.R;
}

void Xuat(HINHCAU c) //122
{
    cout << "\nTam:";
    XuatDiem(c.I);
    cout << "\nBan kinh: " << c.R;
}

float DienTich(HINHCAU c) //123
{
    return float(4 * 3.14 * c.R * c.R);
}

float TheTich(HINHCAU c) //124
{
    return float((float)4 / 3 * 3.14 * c.R * c.R * c.R);
}

float KhoangCach(DIEMKHONGGIAN a, DIEMKHONGGIAN b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int KtThuoc(HINHCAU c, DIEMKHONGGIAN P) //125
{
    float kc = KhoangCach(c.I, P);
    if (kc <= c.R)
        return 1;
    return 0;
}

int TuongDoi(HINHCAU c1, HINHCAU c2) //126
{
    float kc = KhoangCach(c1.I, c2.I);
    if (kc == 0 && c1.R == c2.R)
        return 0;
    if (kc > (c1.R + c2.R))
        return 1;
    if (kc == (c1.R + c2.R))
        return 2;
    if (kc < (c1.R + c2.R) && kc>abs(c1.R - c2.R))
        return 3;
    if (kc == abs(c1.R - c2.R))
        return 4;
    return 5;
}

