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
	void araba_ayarla(string a, string b, int c, int d, double e, string f, int g)
	{
		marka = a;
		model = b;
		yil = c;
		beygir = d;
		motor = e;
		yakit_tuketimi = f;
		fiyat = g;

	}

	void ozellik_bas(int a)
	{
		cout << a << "- " << marka << setw(15) << model << setw(15) << yil << setw(15) << beygir << setw(15) << motor << setw(15) << yakit_tuketimi << setw(15) << fiyat << " tl" << endl;
	}
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
araba arac[10];
kullanicilar kullanici[20];
int okuma()
{
	//Kişilerin bulunduğu dosyayı okuma işlemi
	int k=1;
	ifstream kisiler, arac_stok;
	kisiler.open("kisiler.txt", ios::app);
	while (!kisiler.eof())
	{
		kisiler >> kullanici[k].id >> kullanici[k].sifre >> kullanici[k].isim >> kullanici[k].soyisim >> kullanici[k].bakiye >> kullanici[k].arac;
		k++;
	}
	kisiler.close();
	//Araçların stoklarının tutulduğu dosyayı okuma işlemi
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
	//Döngü sona geldiyse kullanıcı bulunamamıstır.
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
	//Döngü sona geldiyse kullanıcı bulunamamıstır.
	if (kacinci == 22)
	{
		return 0;
	}
	else
	{
		return kacinci;
	}
}
void kullanici_yaz(int id,int sifre,string isim,string soyisim)
{
	//Yeni kullanıcı yazma işlemi
	ofstream kullanici_yaz;
	kullanici_yaz.open("kisiler.txt", ios::app);
	kullanici_yaz << to_string(id) << " " << to_string(sifre) << " " << isim << " " << soyisim << " " << "0 0" << endl;
	kullanici_yaz.close();
}
void kullanici_guncelle(int kacinci,int kisi_sayisi)
{
	//Kullanıcı sınıfında güncel bilgiler mevcut, bundan dolayı eski database i silip yenisini yazma işlemi
	remove("kisiler.txt");
	ofstream dosya;
	dosya.open("kisiler.txt", ios::app);
	for (int i = 1; i < kisi_sayisi-1; i++)
	{
		dosya <<kullanici[i].id<< " "<<kullanici[i].sifre<< " " << kullanici[i].isim << " " << kullanici[i].soyisim << " " << kullanici[i].bakiye << " " << kullanici[i].arac << endl;
	}
	dosya.close();
}
void arac_stok_guncelle()
{
	//Arac sınıfında güncel bilgiler mevcut, bundan dolayı eski database i silip yenisini yazma işlemi
	remove("arac_stok.txt");
	ofstream arac_oku;
	arac_oku.open("arac_stok.txt", ios::app);
	for (int i = 1; i < 10; i++)
	{
		arac_oku << arac[i].stok << endl;
	}
	arac_oku.close();
}
void ana_menu(int kacinci,int kisi_sayisi)
{
	int secim,secim2,tutar;
	do
	{
		system("CLS");
		cout << "Hosgeldiniz " << kullanici[kacinci].isim << " bey/hanim" << endl << "1 - Bakiye sorgulama" << endl << "2 - Bakiye yukleme" << endl << "3 - Gunluk arac kiralama" << endl << "4 - Arac teslim" << endl << "5 - Cikis" << endl << "Secim: ";
		cin >> secim;
		switch (secim)
		{
		case 1:
			//Bakiye sorgulama işlemi
			system("CLS");
			cout << "Bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
			system("PAUSE");
			break;
		case 2:
			//Bakiye yükleme işlemi
			system("CLS");
			cout << "Tutar: ";
			cin >> tutar;
			kullanici[kacinci].bakiye += tutar;
			//Kullanıcılar sınıfı güncellendi.
			kullanici_guncelle(kacinci,kisi_sayisi);//Database güncellendi.
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
				kullanici[kacinci].arac = secim2;//Kullanıcının kiraladığı araç parametresini değiştirme işlemi
				kullanici[kacinci].bakiye -= arac[secim2].fiyat;//Kullanıcının bakiyesinin güncellenmesi
				arac[secim2].stok = 0;//Aracın stoğunun güncellenmesi
				arac_stok_guncelle();//Aracın stoğunun database de güncellenmesi
				kullanici_guncelle(kacinci,kisi_sayisi);//Kullanıcının database de güncellenmesi
				cout << "Guncel bakiyeniz: " << kullanici[kacinci].bakiye << "tl" << endl;
				system("PAUSE");
			}
			else
			{

				if (kullanici[kacinci].arac == secim2)//Kullanıcının üstünde bu arac gözüküyor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac zaten size kiralanmistir." << endl;
					system("PAUSE");
					
				}
				else if (kullanici[kacinci].arac != 0)//Kullanıcının üstünde herhangi bir arac gözüküyor mu?
				{
					system("CLS");
					cout << "Hata!" << endl << "Daha once arac kiralamasi yaptiniz." << endl;
					system("PAUSE");
				}
				else if (arac[secim2].stok == 0)//Arac stoklarda var mı?
				{
					system("CLS");
					cout << "Hata!" << endl << "Arac baska bir musterimize kiralanmistir." << endl;
					system("PAUSE");
				}
				else//Kullanıcının bakiyesi yeterli mi?
				{
					system("CLS");
					cout << "Hata!" << endl << "Yetersiz bakiye." << endl;
					system("PAUSE");
				}
			}
			break;
		case 4:
			system("CLS");
			if (kullanici[kacinci].arac == 0)//Kullanıcı arac kiralamadıysa arac teslim edemez.
			{
				cout << "Teslim edilecek araciniz bulunmamaktadir!" << endl;
				system("PAUSE");
				break;
			}

			cout << arac[kullanici[kacinci].arac].marka << arac[kullanici[kacinci].arac].model << " " << "aracinin teslim islemi basarili." << endl;
			//Kullanıcının kiraladığı araç numarasını kullanici sınıfından çeker ve o numaraya karşılık gelen aracın bilgilerini basar.
			system("PAUSE");
			arac[kullanici[kacinci].arac].stok = 1;//Stok güncelleme
			kullanici[kacinci].arac = 0;//Kullanıcıda tutulan araç bilgisini güncelleme
			//Data base güncellemeleri:
			arac_stok_guncelle();
			kullanici_guncelle(kacinci,kisi_sayisi);
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
	//Açılış penceresi
	int secim, id, sifre, kullanici_no=0;
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
			//ID ve şifre alındı
			kullanici_no = kullanici_kontrol(id, sifre);
			if (kullanici_no == 0)//ID ve Sifre kisiler sınıfında bulunamadı
			{
				cout << "Kullanici bulunamadi!" << endl;
				system("PAUSE");
			}
			else
			{
				cout << "Giris basarili!" << endl;
				system("PAUSE");
				break;
			}
		} while (kullanici_no == 0);
		ana_menu(kullanici_no,okuma());
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
				kullanici_yaz(ID, SIFRE,ISIM,SOYISIM);//Database'e kullanıcı ekleme
				cout << "Kullanici olusturma islemi basarili!" << endl;
				system("PAUSE");
				break;
			}
			cout << "Bu ID kayitlarimizda mevcut. Tekrar deneyiniz." << endl;
			system("PAUSE");
		} while (kullanici_no != 0);//Girilen ID mevcut olduğu müddetce dönecektir.
		okuma();//Tekrardan okuma işlemi ile kullanıcılar sınıfı elemanlarını güncelleme
		kullanici_no = kullanici_kontrol1(ID);
		ana_menu(kullanici_no,okuma());
		break;
	default:
		cout << "HATA!" << endl;
		break;
	}
}
int main()
{
	//Araç özellik atama
	arac[1].araba_ayarla("Toyota  ", "Corolla", 2014, 100, 1.4, "Benzin", 300);
	arac[2].araba_ayarla("Honda   ", "Civic  ", 2019, 130, 1.6, "Dizel ", 500);
	arac[3].araba_ayarla("Honda   ", "Jazz   ", 2013, 100, 1.4, "Benzin", 300);
	arac[4].araba_ayarla("Nissan  ", "Qashqai", 2022, 150, 1.6, "Dizel ", 650);
	arac[5].araba_ayarla("Opel    ", "Astra  ", 2012, 100, 1.4, "Benzin", 300);
	arac[6].araba_ayarla("Audi    ", "A3     ", 2020, 150, 1.6, "Dizel ", 600);
	arac[7].araba_ayarla("Audi    ", "A6     ", 2013, 180, 2.0, "Dizel ", 700);
	arac[8].araba_ayarla("Audi    ", "A6     ", 2022, 200, 3.0, "Dizel ", 950);
	arac[9].araba_ayarla("BMW     ", "320    ", 2018, 150, 1.4, "Benzin", 600);
	//Başlangıçta kayıtlı olan kullanıcıları görmek üzere yapılan okuma işlemi
	okuma();
	giris();
    
}

