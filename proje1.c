
/* 
* @file proje1.
* @description Fonksiyonlarımın açıklayan kod.
* @assignment 1.proje
* @date 10.12.2023
* @author. Emre Hendemoğlu emre.hendemoglu@stu.fsm.edu.tr
*/
#include "Proje1.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

Ders createDers( char *dersAdi, unsigned short int kredi, unsigned short int puan) {//Ders oluşturmak için yazılan kod.
    Ders ekelenenDers;
    ekelenenDers.dersAdi = (char*)malloc(256*sizeof(char));//: Ders adını saklamak için dinamik bellek tahsis edilir. Bu bellek 256 karakterlik bir dizi içindir.
    strcpy(ekelenenDers.dersAdi, dersAdi);//Parametre olarak gelen ders adı, dinamik olarak ayrılan belleğe kopyalanır.
    ekelenenDers.kredi = kredi;//Dersin kredi puanı atanır.
    ekelenenDers.puan = puan;// Dersin not puanı atanır.

    return ekelenenDers;
}

Ogrenci createOgrenci(char* ogrAdi, char* ogrSoyAdi, char* bolumu, float ortalama, Ders* aldigiDersler) {//Öğrenci oluşturmak için yazılan kod.
    Ogrenci eklenenOgrenci;
    int i;
    eklenenOgrenci.ogrAdi = (char*)malloc(256 * sizeof(char));//Boyutu 256 olan dizi oluşturma.
    strcpy(eklenenOgrenci.ogrAdi, ogrAdi);//Parametre olarak gelen öğrenci adı belleğe kopyalanır.

    eklenenOgrenci.ogrSoyAdi = (char*)malloc(256 * sizeof(char));//Boyutu 256 olan dizi oluşturma.
    strcpy(eklenenOgrenci.ogrSoyAdi, ogrSoyAdi);//Parametre olarak gelen öğrenci soyadı belleğe kopyalanır.

    eklenenOgrenci.bolumu = (char*)malloc(256 * sizeof(char));//Boyutu 256 olan dizi oluşturma.
    strcpy(eklenenOgrenci.bolumu, bolumu);

    eklenenOgrenci.ortalama = ortalama;//Öğrencinin ortalama notu atanır.

    eklenenOgrenci.aldigiDersler = (Ders*)malloc(10 * sizeof(Ders));//Öğrencinin aldığı ders bilgilerini saklamak için bir dizi oluşturulur. Bu dizi 10 elemanlıdır ve her eleman bir Ders struct'ını temsil eder.
    
    for (i = 0; i < 10; i++) {
        if (aldigiDersler[i].dersAdi != NULL) {
            eklenenOgrenci.aldigiDersler[i] = aldigiDersler[i];//Öğrenciye ait ders dizisine, parametre olarak gelen ders bilgileri atanır.v
        } else {
            eklenenOgrenci.aldigiDersler[i].dersAdi = NULL;//Oğrenci bu sıradaki dersi almamıştır.
            eklenenOgrenci.aldigiDersler[i].kredi = 0;// Kredi puanını sıfırlar.
            eklenenOgrenci.aldigiDersler[i].puan = 0;// Not puanını sıfırlar.
        }
    }

    return eklenenOgrenci;
}



void printOgrenciInfo( Ogrenci ogrenci) { //Ogrenciler hakkında bilgi veren kod.
    printf("Ogrenci Adi: %s %s\n", ogrenci.ogrAdi, ogrenci.ogrSoyAdi);
    printf("Bolumu: %s\n", ogrenci.bolumu);
    printf("Ortalama: %.2f\n", ogrenci.ortalama);

    // Dersleri yazdırmak için yazılan kod.
    for (int i = 0; i < 10; i++)
    {
        if (ogrenci.aldigiDersler[i].dersAdi != NULL)
        {
            printf("Ders Adi: %s, Kredi: %hu, Puan: %hu\n", ogrenci.aldigiDersler[i].dersAdi, ogrenci.aldigiDersler[i].kredi, ogrenci.aldigiDersler[i].puan);
        }
    }
    printf("\n");
}

void printOgrenciArrayInfo( Ogrenci *ogrenciler, int size) {//Ogrenci bilgilerini içeren dizi kodu.
    for (int i = 0; i < size; i++) {
        printOgrenciInfo(ogrenciler[i]);
        printf("\n");
    }
}

float calculateDersOrtalama( Ogrenci *ogrenciler, int ogrenciSayisi,  char *dersAdi) {//Girilen derslerin ortalamasını gösteren kod. 
    
      int toplamPuan = 0, toplamKredi = 0;

    for (int i = 0; i < ogrenciSayisi; i++) {
        Ogrenci ogrenci = ogrenciler[i];

        for (int j = 0; j < 10; j++) {
            if (strcmp(ogrenci.aldigiDersler[j].dersAdi, dersAdi) == 0) {
                Ders ders = ogrenci.aldigiDersler[j];
                toplamPuan += ders.puan * ders.kredi;
                toplamKredi += ders.kredi;
                break; // Bu dersi bulduk, diğer derslere bakmaya gerek yok bu yüzden break yazılır.
            }
        }
    }

    if (toplamKredi == 0) {
        printf("Belirtilen ders adina sahip not bulunamadi.\n");// Not bulunamadığı zaman yazılan kod. 
        return 0.0;
    }

    return (float)toplamPuan / toplamKredi;
}


float calculateDersStandartSapma(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi) {// İlgili ders adına sahip notları depolamak için bir dizi
    float notlar[ogrenciSayisi];
    int notSayisi = 0;


    for (int i = 0; i < ogrenciSayisi; i++) {// Öğrenci dizisini dönen ve ilgili ders adına sahip notları al
        for (int j = 0; j < 10; j++) {
            if (ogrenciler[i].aldigiDersler[j].dersAdi != NULL &&//ders adına sahip notu bulmak için kontrol yapılır. Ders adı NULL değilse ve aranan ders adıyla eşleşiyorsa, notlar dizisine not eklenir.
                strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0) {
                notlar[notSayisi++] = ogrenciler[i].aldigiDersler[j].puan;
                break;  // Bu dersi bulduk diğer derslere bakmaya gerek kalmadığı için yazılır.
            }
        }
    }

    // Hesaplamalar
    float toplam = 0.0;
    for (int i = 0; i < notSayisi; i++) {//Notların toplamı hesaplanır.
        toplam += notlar[i];
    }

    float ortalama = toplam / notSayisi;//Notların ortalaması hesaplanır.

    float toplamKareFark = 0.0;
    for (int i = 0; i < notSayisi; i++) {//Her notun ortalamadan sapması hesaplanır ve kareleri toplamı hesaplanır.
        float fark = notlar[i] - ortalama;
        toplamKareFark += fark * fark;
    }

    return sqrt(toplamKareFark / notSayisi);//Standart sapma, sapmaların karelerinin toplamının not sayısına bölünüp karekökü alınarak hesaplanır ve bu değer geri döndürülür.
}

void listHighGradeStudents(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi) {//Ortalamada yüksek alan öğrenciyi belirten kod.
    printf("\nOgrencilerin %s dersinden ortalamanin ustunde not alanlari:\n", dersAdi);

    for (int i = 0; i < ogrenciSayisi; i++) {//Öğrenci dizisi üzerinde bir döngü başlatılır ve her bir öğrenci için kontrol yapılır.
        for (int j = 0; j < 10; j++) {// Her bir öğrencinin aldığı 10 ders için bir iç döngü başlatılır.
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0) {//İç içe döngülerde, öğrencinin aldığı dersin adı, fonksiyona parametre olarak verilen dersAdi ile eşleşirse, bu dersin not bilgileri kontrol edilecektir.
                if (ogrenciler[i].aldigiDersler[j].puan > calculateDersOrtalama(ogrenciler, ogrenciSayisi, dersAdi)) {// Eğer öğrencinin aldığı bu dersten aldığı not, tüm öğrencilerin aynı ders için hesaplanan ortalamanın üzerindeyse, bu öğrenci listeye eklenir.
                    printf("Ogrenci: %s %s, \nNot: %d\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi, ogrenciler[i].aldigiDersler[j].puan);
                }
            }
        }
    }
}

void writeStudentInfoToFile( Ogrenci *ogrenciler, int ogrenciSayisi,  char *dosyaAdi) {
     FILE *dosya = fopen(dosyaAdi, "w");// Dosyayı yazma modunda açar. 

if (dosya == NULL) {
    perror("Dosya açma hatasi");
    return;
}

    for (int i = 0; i < ogrenciSayisi; i++) {//Öğrenci dizisini döngüye alır ve her bir öğrenci için aşağıdaki adımları gerçekleştirir.
        fprintf(dosya, "Ogrenci: %s %s\nBolum: %s\nNot Ortalamasi: %.2f\n\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi, ogrenciler[i].bolumu, ogrenciler[i].ortalama);// Her öğrencinin adını, soyadını, bölümünü ve not ortalamasını dosyaya yazar.
    }
    fprintf(dosya, "\n");

    fclose(dosya);//: Dosyayı kapatır.
    printf("Ogrenci bilgileri \"%s\" adli dosyaya yazildi.\n", dosyaAdi);
}

Ogrenci* readStudentsFromFile(int *ogrenciSayisi,  char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya '%s' açma hatasi\n", dosyaAdi);
        return NULL;
    }

    *ogrenciSayisi = 0;
    Ogrenci *ogrenciler = NULL;// Başlangıçta öğrenci bilgilerini saklamak için bir diziye işaret eden bir pointer oluşturulur.

    while (1) {
        ogrenciler = realloc(ogrenciler, (*ogrenciSayisi + 1) * sizeof(Ogrenci));//Her bir öğrenci bilgisi okunduğunda, dinamik dizi boyutunu bir artırarak daha fazla öğrenci bilgisini saklamak için bellekte yer ayırır.
        if (ogrenciler == NULL) {
            printf("Bellek hatasi\n");
            fclose(dosya);
            return NULL;
        }

        if (fscanf(dosya, "%s %s %s %f", ogrenciler[*ogrenciSayisi].ogrAdi,
                   ogrenciler[*ogrenciSayisi].ogrSoyAdi, ogrenciler[*ogrenciSayisi].bolumu,&ogrenciler[*ogrenciSayisi].ortalama) == 4) {
            (*ogrenciSayisi)++;
        } else {
            break;  
        }
    }

    fclose(dosya);//Dosya kapatılır.

    return ogrenciler;
}



void freeStudentArray(Ogrenci *ogrenciler) {//Tuttuğu diziyi hafızada yer kaplamasın diye serbest bırakmasını sağlayan kod.
    free(ogrenciler);
}