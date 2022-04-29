#pragma once
#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
class araba
{
public:
	string marka;
	string model;
	int yil;
	int beygir;
	double motor;
	string yakit_tuketimi;
	int fiyat;
	int stok;
	araba()
	{

	}
	void araba_ayarla(string, string, int, int, double, string, int);
	void ozellik_bas(int);
};
class kullanicilar
{
public:
	int id;
	int sifre;
	string isim;
	string soyisim;
	int bakiye;
	int arac;

	kullanicilar()
	{

	}
};
extern araba arac[10];
extern kullanicilar kullanici[20];
void arac_ayarla();
int okuma();
int kullanici_kontrol(int, int);
int kullanici_kontrol1(int);
void kullanici_yaz(int, int, string, string);
void kullanici_guncelle(int, int);
void arac_stok_guncelle();
void ana_menu(int, int);
void giris();