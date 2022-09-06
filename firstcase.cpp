//birsuyilmaz
#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Arac{
    public:
        int HGS_no;
        string sahibin_ismi;
        string sahibin_soyismi;
        int sinif;
        double fiyat;
        
};

class Gise{
    public:
        int arac_sayisi;
        Arac *araclar;
        int sayim;
        Gise(){
            arac_sayisi = SIZE;
            Arac *araclar = new Arac[arac_sayisi];
            sayim = 0;
        }

        int Odeme(Arac arac1, double bakiye, Arac araclar[], int &sayim, int &arac_sayisi){
        bakiye -= arac1.fiyat;
        araclar[sayim] = arac1;
        sayim ++;
        if(sayim >= arac_sayisi){
            Sayi_arttirma(arac_sayisi, araclar);
        }
        return bakiye;
        }
    
        void Gunluk_Bakiye(int sayim, Arac *araclar){
            int toplam_bakiye = 0;
            for(int i = 0; i < sayim; i++){
                toplam_bakiye += araclar[i].fiyat;
            }
            cout << "Toplam günlük bakiye: " << toplam_bakiye << endl;
        }
    private:
        void Sayi_arttirma(int &arac_sayisi, Arac *&araclar)
         {
             arac_sayisi *= 2;
             Arac *yeni = new Arac[arac_sayisi];
             for(int i=0; i<arac_sayisi/2; i++)
             {
                 yeni[i] = araclar[i];
	         }

	         delete [] araclar;

	         araclar = yeni;
         }
};


class Otomobil: public Arac, public Gise{
    public:
        Otomobil(){
           int sinif = 1; 
        }
};

class Minibus: public Arac, public Gise{
    public:
        Minibus(){
           int sinif = 2; 
        }


};

class Otobus: public Arac, public Gise{     
    public:
        Otobus(){
           int sinif = 3; 
        }

};

int main(){
    Arac *araclar = new Arac[SIZE];
    int arac_sayisi = SIZE;
    int sayi = 0;
    int bakiye = 100;

    Otomobil o;
    o.HGS_no = 15337373;
    o.sahibin_ismi = "Murat";
    o.sahibin_soyismi = "Kara";
    o.fiyat = 15;

    Minibus m;
    m.HGS_no = 15337374;
    m.sahibin_ismi = "Metin";
    m.sahibin_soyismi = "Kanca";
    m.fiyat = 18;

    Otobus t;
    t.HGS_no = 15337375;
    t.sahibin_ismi = "Helin";
    t.sahibin_soyismi = "Merkez";
    t.fiyat = 25;

    bakiye = o.Odeme(o, bakiye, araclar, sayi, arac_sayisi);
    bakiye = m.Odeme(m, bakiye, araclar, sayi, arac_sayisi);
    bakiye = t.Odeme(t, bakiye, araclar, sayi, arac_sayisi);

    o.Gunluk_Bakiye(sayi, araclar);
    t.Gunluk_Bakiye(sayi, araclar);
    m.Gunluk_Bakiye(sayi, araclar);
    
    cout << "Geriye kalan bakiye: " << bakiye << endl;

    return 0;
}
//birsuyilmaz