#include <stdio.h>
#include <stdbool.h> //bool veri türünü kullanmak için gerekli.
#include <string.h> //karakter dizileri üzerinde işlemler gerçekleştirmek için gerekli.
#include "fonksiyon.h"

#define MAX_ARAC_SAYISI 50
#define DOSYA_ADI "kiralama_gecmisi.txt"

struct Arac {
    int aracID;
    char marka[50];
    char model[50];
    bool kiralandi; //bool veri türü true ya da false değerini alarak araçların kiralanma durumu gösterir.
};

// Global değişkenler
struct Arac araclar[MAX_ARAC_SAYISI];
int aracSayisi = 0;

/*kiralanacak araçları ekleme fonksiyonu
    bu fonksiyon, araç bilgilerini içeren bir struct Arac türünden nesne eklemek için kullanılır.*/
void aracEkle(int aracID, char* marka, char* model) {
    if (aracSayisi < MAX_ARAC_SAYISI) {
        struct Arac yeniArac = {aracID};
        strcpy(yeniArac.marka, marka);
        strcpy(yeniArac.model, model);
        yeniArac.kiralandi = false;
        araclar[aracSayisi++] = yeniArac;
    } else {
        printf("Maksimum arac sayisina ulasildi!\n");
    }
}

// aracKirala fonksiyonu, bir aracın kiralanmasını yönetmek için kullanılır.
void aracKirala(int aracID) {
    printf("Kiralamak istediginiz aracin idsini giriniz:");
    scanf("%d",&aracID);
    for (int i = 0; i < aracSayisi; i++) {
        if (araclar[i].aracID == aracID) {
            if (!araclar[i].kiralandi) {
                araclar[i].kiralandi = true;
                printf("Arac kiralandi: %s %s\n", araclar[i].marka, araclar[i].model);
                return;
            } else {
                printf("Bu arac zaten kiralanmis!\n");
                return;
            }
        }
    }
    printf("Arac bulunamadi!\n");
}

// aracIadeEt fonksiyonu, bir aracın iadesini yönetmek için kullanılır.
void aracIadeEt(int aracID) {
    printf("Iade etmek istediginiz aracin idsini giriniz:");
    scanf("%d",&aracID);
    for (int i = 0; i < aracSayisi; i++) {
        if (araclar[i].aracID == aracID) {
            if (araclar[i].kiralandi) {
                araclar[i].kiralandi = false;
                printf("Arac iade edildi: %s %s\n", araclar[i].marka, araclar[i].model);
                return;
            } else {
                printf("Bu arac zaten iade edilmis!\n");
                return;
            }
        }
    }
    printf("Arac bulunamadi!\n");
}

// kiralanmamış araçları listeleyen fonksiyon
void uygunAraclariListele() {
    printf("Kullanilabilir Araclar:\n");
    for (int i = 0; i < aracSayisi; i++) {
        if (!araclar[i].kiralandi) {
            printf("ID: %d, Marka: %s, Model: %s\n", araclar[i].aracID, araclar[i].marka, araclar[i].model);
        }
    }
}

// kiralamaGecmisiKaydet fonksiyonu, kiralanmış araçların kiralama geçmişini bir dosyaya kaydeden fonksiyondur.
void kiralamaGecmisiKaydet() {
    FILE *dosya = fopen(DOSYA_ADI, "a");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "Kiralama Geçmisi:\n");
    for (int i = 0; i < aracSayisi; i++) { //tanımlanmış bütün araçların arasında dolaşıyor.
        if (araclar[i].kiralandi) {
            fprintf(dosya, "Kiralanan Araç: ID %d, Marka: %s, Model: %s\n", araclar[i].aracID, araclar[i].marka, araclar[i].model);
        }
    }
    fclose(dosya);
    printf("Kiralama gecmisi dosyaya kaydedildi.\n");
}
