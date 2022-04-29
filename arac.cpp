#include"arac.h"
void araba::araba_ayarla(string a, string b, int c, int d, double e, string f, int g)
{
	marka = a;
	model = b;
	yil = c;
	beygir = d;
	motor = e;
	yakit_tuketimi = f;
	fiyat = g;
}
void araba::ozellik_bas(int a)
{
	cout << a << "- " << marka << setw(15) << model << setw(15) << yil << setw(15) << beygir << setw(15) << motor << setw(15) << yakit_tuketimi << setw(15) << fiyat << " tl" << endl;
}
araba arac[10];
kullanicilar kullanici[20];
int okuma()
{
	//Ki�ilerin bulundu�u dosyay� okuma i�lemi
	int k = 1;
	ifstream kisiler, arac_stok;
	kisiler.open("kisiler.txt", ios::app);
	while (!kisiler.eof())
	{
		kisiler >> kullanici[k].id >> kullanici[k].sifre >> kullanici[k].isim >> kullanici[k].soyisim >> kullanici[k].bakiye >> kullanici[k].arac;
		k++;
	}
	kisiler.close();
	//Ara�lar�n stoklar�n�n tutuldu�u dosyay� okuma i�lemi
	arac_stok.open("arac_stok.txt", ios::app);
	for (int i = 1; i < 10; i++)
	{
		arac_stok >> arac[i].stok;
	}
	arac_stok.close();
	return k;
}
int kullanici_kontrol(int id, int sifre)
{
	int kacinci = 1;
	for (int i = 0; i < 21; i++)
	{
		if (id == kullanici[kacinci].id && sifre == kullanici[kacinci].sifre)
		{
			break;
		}
		kacinci++;
	}
	//D�ng� sona geldiyse kullan�c� bulunamam�st�r(kacinci=22).
	if (kacinci == 22)
	{
		return 0;
	}
	else
	{
		return kacinci;
	}
}
int kullanici_kontrol1(int id)
{
	int kacinci = 1;
	for (int i = 0; i < 21; i++)
	{
		if (id == kullanici[kacinci].id)
		{
			break;
		}
		kacinci++;
	}
	//D�ng� sona geldiyse kullan�c� bulunamam�st�r.
	if (kacinci == 22)
	{
		return 0;
	}
	else
	{
		return kacinci;
	}
}
void kullanici_yaz(int id, int sifre, string isim, string soyisim)
{
	//Yeni kullan�c� yazma i�lemi
	ofstream kullanici_yaz;
	kullanici_yaz.open("kisiler.txt", ios::app);
	kullanici_yaz << to_string(id) << " " << to_string(sifre) << " " << isim << " " << soyisim << " " << "0 0" << endl;
	kullanici_yaz.close();
}
void kullanici_guncelle(int kacinci, int kisi_sayisi)
{
	//Kullan�c� s�n�f�nda g�ncel bilgiler mevcut, bundan dolay� eski database i silip yenisini yazma i�lemi
	remove("kisiler.txt");
	ofstream dosya;
	dosya.open("kisiler.txt", ios::app);
	for (int i = 1; i < kisi_sayisi - 1; i++)
	{
		dosya << kullanici[i].id << " " << kullanici[i].sifre << " " << kullanici[i].isim << " " << kullanici[i].soyisim << " " << kullanici[i].bakiye << " " << kullanici[i].arac << endl;
	}
	dosya.close();
}
void arac_stok_guncelle()
{
	//Arac s�n�f�nda g�ncel bilgiler mevcut, bundan dolay� eski database i silip yenisini yazma i�lemi
	remove("arac_stok.txt");
	ofstream arac_oku;
	arac_oku.open("arac_stok.txt", ios::app);
	for (int i = 1; i < 10; i++)
	{
		arac_oku << arac[i].stok << endl;
	}
	arac_oku.close();
}
void ana_menu(int kacinci, int kisi_sayisi)
{
	int secim, secim2, tutar;
	do
	{
		system("CLS");
		cout << "Hosgeldiniz " << kullanici[kacinci].isim << " bey/hanim" << endl << "1 - Bakiye sorgulama" << endl << "2 - Bakiye yukleme" << endl << "3 - Gunluk arac kiralama" << endl << "4 - Arac teslim" << endl << "5 - Cikis" << endl << "Secim: ";
		cin >> secim;
		switch (secim)
		{
		case 1:
			//Bakiye sorgulama i�lemi
			system("CLS");
			cout << "Bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
			system("PAUSE");
			break;
		case 2:
			//Bakiye y�kleme i�lemi
			system("CLS");
			cout << "Tutar: ";
			cin >> tutar;
			kullanici[kacinci].bakiye += tutar;
			//Kullan�c�lar s�n�f� g�ncellendi.
			kullanici_guncelle(kacinci, kisi_sayisi);//Database g�ncellendi.
			system("CLS");
			cout << "Islem basarili." << endl << "Guncel bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
			system("PAUSE");
			break;
		case 3:
			system("CLS");
			cout << "ARAC LISTESI:" << endl;
			arac[1].ozellik_bas(1);
			arac[2].ozellik_bas(2);
			arac[3].ozellik_bas(3);
			arac[4].ozellik_bas(4);
			arac[5].ozellik_bas(5);
			arac[6].ozellik_bas(6);
			arac[7].ozellik_bas(7);
			arac[8].ozellik_bas(8);
			arac[9].ozellik_bas(9);
			cout << "Secim: ";
			cin >> secim2;
			if (arac[secim2].stok == 1 && kullanici[kacinci].arac != secim2 && kullanici[kacinci].arac == 0 && kullanici[kacinci].bakiye >= arac[secim2].fiyat)
			{
				system("CLS");
				cout << "Arac kiralama islemi basarili!" << endl;
				kullanici[kacinci].arac = secim2;//Kullan�c�n�n kiralad��� ara� parametresini de�i�tirme i�lemi
				kullanici[kacinci].bakiye -= arac[secim2].fiyat;//Kullan�c�n�n bakiyesinin g�ncellenmesi
				arac[secim2].stok = 0;//Arac�n sto�unun g�ncellenmesi
				arac_stok_guncelle();//Arac�n sto�unun database de g�ncellenmesi
				kullanici_guncelle(kacinci, kisi_sayisi);//Kullan�c�n�n database de g�ncellenmesi
				cout << "Guncel bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
				system("PAUSE");
			}
			else
			{

				if (kullanici[kacinci].arac == secim2)//Kullan�c�n�n �st�nde bu arac g�z�k�yor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac zaten size kiralanmistir." << endl;
					system("PAUSE");

				}
				else if (kullanici[kacinci].arac != 0)//Kullan�c�n�n �st�nde herhangi bir arac g�z�k�yor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Daha once arac kiralamasi yaptiniz." << endl;
					system("PAUSE");
				}
				else if (arac[secim2].stok == 0)//Arac stoklarda var m�?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac baska bir musterimize kiralanmistir." << endl;
					system("PAUSE");
				}
				else//Kullan�c�n�n bakiyesi yeterli mi?
				{
					system("CLS");
					cout << "Hata!" << endl << "Yetersiz bakiye." << endl;
					system("PAUSE");
				}
			}
			break;
		case 4:
			system("CLS");
			if (kullanici[kacinci].arac == 0)//Kullan�c� arac kiralamad�ysa arac teslim edemez.
			{
				cout << "Teslim edilecek araciniz bulunmamaktadir!" << endl;
				system("PAUSE");
				break;
			}

			cout << arac[kullanici[kacinci].arac].marka << arac[kullanici[kacinci].arac].model << " " << "aracinin teslim islemi basarili." << endl;
			//Kullan�c�n�n kiralad��� ara� numaras�n� kullanici s�n�f�ndan �eker ve o numaraya kar��l�k gelen arac�n bilgilerini basar.
			system("PAUSE");
			arac[kullanici[kacinci].arac].stok = 1;//Stok g�ncelleme
			kullanici[kacinci].arac = 0;//Kullan�c�da tutulan ara� bilgisini g�ncelleme
			//Data base g�ncellemeleri:
			arac_stok_guncelle();
			kullanici_guncelle(kacinci, kisi_sayisi);
			break;
		default:
			break;
		}
	} while (secim != 5);
	system("CLS");
	cout << "Bizi tercih ettiginiz icin tesekkur ederiz. Hoscakalin!" << endl;
}
void giris()
{
	//A��l�� penceresi
	int secim, id, sifre, kullanici_no = 0;
	int ID, SIFRE;
	string ISIM, SOYISIM;
	cout << "*ARAC KIRALAMA OTOMASYONU*" << endl << "1-Giris yap" << endl << "2-Uyelik olustur" << endl << "Secim: ";
	cin >> secim;
	switch (secim)
	{
	case 1:
		do
		{
			system("CLS");
			cout << "ID: ";
			cin >> id;
			cout << "Sifre: ";
			cin >> sifre;
			//ID ve �ifre al�nd�
			kullanici_no = kullanici_kontrol(id, sifre);
			if (kullanici_no == 0)//ID ve Sifre kisiler s�n�f�nda bulunamad�
			{
				cout << "ID veya Sifre hatali!" << endl;
				system("PAUSE");
			}
			else
			{
				cout << "Giris basarili!" << endl;
				system("PAUSE");
				break;
			}
		} while (kullanici_no == 0);
		ana_menu(kullanici_no, okuma());
		break;
	case 2:
		do
		{
			system("CLS");
			cout << "Isim: ";
			cin >> ISIM;
			cout << "Soyisim: ";
			cin >> SOYISIM;
			cout << "ID: ";
			cin >> ID;
			cout << "Sifre: ";
			cin >> SIFRE;
			kullanici_no = kullanici_kontrol1(ID);
			if (kullanici_no == 0)
			{
				system("CLS");
				kullanici_yaz(ID, SIFRE, ISIM, SOYISIM);//Database'e kullan�c� ekleme
				cout << "Kullanici olusturma islemi basarili!" << endl;
				system("PAUSE");
				break;
			}
			cout << "Bu ID kayitlarimizda mevcut. Tekrar deneyiniz." << endl;
			system("PAUSE");
		} while (kullanici_no != 0);//Girilen ID mevcut oldu�u m�ddetce d�necektir.
		okuma();//Tekrardan okuma i�lemi ile kullan�c�lar s�n�f� elemanlar�n� g�ncelleme
		kullanici_no = kullanici_kontrol1(ID);
		ana_menu(kullanici_no, okuma());
		break;
	default:
		cout << "HATA!" << endl;
		break;
	}
}