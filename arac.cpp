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
	//Kiþilerin bulunduðu dosyayý okuma iþlemi
	int k = 1;
	ifstream kisiler, arac_stok;
	kisiler.open("kisiler.txt", ios::app);
	while (!kisiler.eof())
	{
		kisiler >> kullanici[k].id >> kullanici[k].sifre >> kullanici[k].isim >> kullanici[k].soyisim >> kullanici[k].bakiye >> kullanici[k].arac;
		k++;
	}
	kisiler.close();
	//Araçlarýn stoklarýnýn tutulduðu dosyayý okuma iþlemi
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
	//Döngü sona geldiyse kullanýcý bulunamamýstýr(kacinci=22).
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
	//Döngü sona geldiyse kullanýcý bulunamamýstýr.
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
	//Yeni kullanýcý yazma iþlemi
	ofstream kullanici_yaz;
	kullanici_yaz.open("kisiler.txt", ios::app);
	kullanici_yaz << to_string(id) << " " << to_string(sifre) << " " << isim << " " << soyisim << " " << "0 0" << endl;
	kullanici_yaz.close();
}
void kullanici_guncelle(int kacinci, int kisi_sayisi)
{
	//Kullanýcý sýnýfýnda güncel bilgiler mevcut, bundan dolayý eski database i silip yenisini yazma iþlemi
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
	//Arac sýnýfýnda güncel bilgiler mevcut, bundan dolayý eski database i silip yenisini yazma iþlemi
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
			//Bakiye sorgulama iþlemi
			system("CLS");
			cout << "Bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
			system("PAUSE");
			break;
		case 2:
			//Bakiye yükleme iþlemi
			system("CLS");
			cout << "Tutar: ";
			cin >> tutar;
			kullanici[kacinci].bakiye += tutar;
			//Kullanýcýlar sýnýfý güncellendi.
			kullanici_guncelle(kacinci, kisi_sayisi);//Database güncellendi.
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
				kullanici[kacinci].arac = secim2;//Kullanýcýnýn kiraladýðý araç parametresini deðiþtirme iþlemi
				kullanici[kacinci].bakiye -= arac[secim2].fiyat;//Kullanýcýnýn bakiyesinin güncellenmesi
				arac[secim2].stok = 0;//Aracýn stoðunun güncellenmesi
				arac_stok_guncelle();//Aracýn stoðunun database de güncellenmesi
				kullanici_guncelle(kacinci, kisi_sayisi);//Kullanýcýnýn database de güncellenmesi
				cout << "Guncel bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
				system("PAUSE");
			}
			else
			{

				if (kullanici[kacinci].arac == secim2)//Kullanýcýnýn üstünde bu arac gözüküyor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac zaten size kiralanmistir." << endl;
					system("PAUSE");

				}
				else if (kullanici[kacinci].arac != 0)//Kullanýcýnýn üstünde herhangi bir arac gözüküyor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Daha once arac kiralamasi yaptiniz." << endl;
					system("PAUSE");
				}
				else if (arac[secim2].stok == 0)//Arac stoklarda var mý?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac baska bir musterimize kiralanmistir." << endl;
					system("PAUSE");
				}
				else//Kullanýcýnýn bakiyesi yeterli mi?
				{
					system("CLS");
					cout << "Hata!" << endl << "Yetersiz bakiye." << endl;
					system("PAUSE");
				}
			}
			break;
		case 4:
			system("CLS");
			if (kullanici[kacinci].arac == 0)//Kullanýcý arac kiralamadýysa arac teslim edemez.
			{
				cout << "Teslim edilecek araciniz bulunmamaktadir!" << endl;
				system("PAUSE");
				break;
			}

			cout << arac[kullanici[kacinci].arac].marka << arac[kullanici[kacinci].arac].model << " " << "aracinin teslim islemi basarili." << endl;
			//Kullanýcýnýn kiraladýðý araç numarasýný kullanici sýnýfýndan çeker ve o numaraya karþýlýk gelen aracýn bilgilerini basar.
			system("PAUSE");
			arac[kullanici[kacinci].arac].stok = 1;//Stok güncelleme
			kullanici[kacinci].arac = 0;//Kullanýcýda tutulan araç bilgisini güncelleme
			//Data base güncellemeleri:
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
	//Açýlýþ penceresi
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
			//ID ve þifre alýndý
			kullanici_no = kullanici_kontrol(id, sifre);
			if (kullanici_no == 0)//ID ve Sifre kisiler sýnýfýnda bulunamadý
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
				kullanici_yaz(ID, SIFRE, ISIM, SOYISIM);//Database'e kullanýcý ekleme
				cout << "Kullanici olusturma islemi basarili!" << endl;
				system("PAUSE");
				break;
			}
			cout << "Bu ID kayitlarimizda mevcut. Tekrar deneyiniz." << endl;
			system("PAUSE");
		} while (kullanici_no != 0);//Girilen ID mevcut olduðu müddetce dönecektir.
		okuma();//Tekrardan okuma iþlemi ile kullanýcýlar sýnýfý elemanlarýný güncelleme
		kullanici_no = kullanici_kontrol1(ID);
		ana_menu(kullanici_no, okuma());
		break;
	default:
		cout << "HATA!" << endl;
		break;
	}
}