#include <stdio.h>
#include "fonksiyon.h"

int main() {
    aracEkle(1,"Audi", "RS6");
    aracEkle(2,"Fiat", "Linea");
    aracEkle(3,"Ford", "Focus");
    aracEkle(4,"Hyundai","Accent");
    aracEkle(5,"Mercedes","C63");
    aracEkle(6,"Toyota","Corolla");
    aracEkle(7,"Mercedes","AMG G63");
    aracEkle(8,"Ford","Escort");
    aracEkle(9,"Nissan","GTR R34");
    aracEkle(10,"Renault","Megane");
    aracEkle(11,"Volkswagen","Golf");
    aracEkle(12,"Skoda","Superb");
    aracEkle(13,"Toyota","Yaris");
    aracEkle(14,"Audi","A3");
    aracEkle(15,"Volvo","S90");
    uygunAraclariListele();
    printf("Ne yapmak istersiniz?\n1.Arac kiralama\n2.Arac iade etme\n3.Kiralanabilir araclari listeleme\n4.Cikis yap\n");
    int secim;
    scanf("%d",&secim);
    while(secim!=4){
        switch (secim) {
            case 1:{
                int aracID;
                aracKirala(aracID);
                break;
            }
            case 2:{
                int aracID;
                aracIadeEt(aracID);
                break;
            }
            case 3:{
                uygunAraclariListele();
                break;
            }
            default:{
                printf("Gecerli bir secim yapin.\n");
                break;
            }
        }
        printf("Ne yapmak istersiniz?\n1.Arac kiralama\n2.Arac iade etme\n3.Kiralanabilir araclari listeleme\n4.Cikis yap\n");
        scanf("%d",&secim);
    }
    if(secim==4){
        printf("Sistemden cikis yapildi.\n");
    }

    kiralamaGecmisiKaydet();
    return 0;
}
