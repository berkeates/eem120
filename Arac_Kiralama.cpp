#include"arac.h"
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

