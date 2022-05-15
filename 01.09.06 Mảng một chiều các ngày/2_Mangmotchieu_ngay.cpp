#include <iostream>
#include <iomanip>
using namespace std;

struct Ngay
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct Ngay NGAY;

void Nhap(NGAY[], int&);
void Nhap(NGAY&);
void Xuat(NGAY[], int);
void Xuat(NGAY);
int ktNhuan(NGAY);
int SoNgayToiDaTrongThang(NGAY);
int SoNgayToiDaTrongNam(NGAY);
int SoThuTuTrongNam(NGAY);
int KhoangCach(NGAY, NGAY);
int SoThuTu(NGAY);
void GanNhauNhat(NGAY[], int, NGAY&, NGAY&);
void XaNhauNhat(NGAY[], int, NGAY&, NGAY&);

int main()
{
	NGAY a[100];
	NGAY x, y;
	int n;
	Nhap(a, n);
	cout << "\nMang mot chieu ngay vua nhap la: \n";
	Xuat(a, n);

	cout << "\nHai ngay gan nhau nhat la:  \n";
	GanNhauNhat(a, n, x, y);
	Xuat(x);
	cout << endl;
	Xuat(y);
	cout << "\nHai ngay gan xa nhat la:  \n";
	XaNhauNhat(a, n, x, y);
	Xuat(x);
	cout << endl;
	Xuat(y);

	return 0;
}

void Nhap(NGAY & x)
{
	cout << "Nhap ngay : ";
	cin >> x.Ngay;
	cout << "Nhap thang : ";
	cin >> x.Thang;
	cout << "Nhap nam : ";
	cin >> x.Nam;
}

void Xuat(NGAY x)
{
	cout << setw(6);
	cout << "\n Ngay = " << x.Ngay;
	cout << "\n Thang = " << x.Thang;
	cout << "\n Nam = " << x.Nam;
}

void Nhap(NGAY a[], int& n) // 124
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap duong thang A[" << i << "]:\n";
		Nhap(a[i]);
	}
}

void Xuat(NGAY a[], int n) // 125
{
	for (int i = 0; i < n; i++)
	{
		cout << "Ngay a[" << i << "]:";
		Xuat(a[i]);
		cout << endl;
	}
}

int ktNhuan(NGAY x)
{
	if (x.Nam % 4 == 0 && x.Nam % 100 != 0)
		return 1;
	if (x.Nam % 400 == 0)
		return 1;
	return 0;
}

int SoNgayToiDaTrongThang(NGAY x)
{
	int ngaythang[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (ktNhuan(x))
		ngaythang[1] = 29;
	return ngaythang[x.Thang - 1];
}

int SoNgayToiDaTrongNam(NGAY x)
{
	if (ktNhuan(x))
		return 366;
	return 365;
}

int SoThuTuTrongNam(NGAY x)
{
	int stt = 0;
	for (int i = 1; i <= x.Thang - 1; i++)
	{
		NGAY temp = { 1,i,x.Nam };
		stt += SoNgayToiDaTrongThang(temp);
	}
	return (stt + x.Ngay);
}

int SoThuTu(NGAY x)
{
	int stt = 0;
	for (int i = 1; i <= x.Nam - 1; i++)
	{
		NGAY temp = { 1,1,i };
		stt = stt + SoNgayToiDaTrongNam(temp);
	}
	return (stt + SoThuTuTrongNam(x));
}


int KhoangCach(NGAY x, NGAY y)
{
	int a = SoThuTu(x);
	int b = SoThuTu(y);
	return abs(a - b);
}

void GanNhauNhat(NGAY a[], int n,NGAY & x, NGAY & y)
{
	x = a[0];
	y = a[1];
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (KhoangCach(a[i], a[j]) < KhoangCach(x, y))
			{
				x = a[i];
				y = a[j];
			}
}

void XaNhauNhat(NGAY a[], int n, NGAY & x, NGAY & y)
{
	x = a[0];
	y = a[1];
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (KhoangCach(a[i], a[j]) > KhoangCach(x, y))
			{
				x = a[i];
				y = a[j];
			}
}
