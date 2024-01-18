
/* 
* @file proje1.
* @description Fonksiyonlarımın çalıştıran dosya.
* @assignment 1.proje
* @date 10.12.2023
* @author. Emre Hendemoğlu emre.hendemoglu@stu.fsm.edu.tr
*/
#include "Proje1.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Kullanim: %s <dosya_adi>\n", argv[0]);
        return 1;
    }
    Ders mat1 = createDers("Matematik", 3, 85);
    Ders fiz1 = createDers("Fizik", 4, 70);
    Ders kim1 = createDers("Kimya", 5, 90);
    Ders mat2 = createDers("Matematik", 5, 65);
    Ders fiz2= createDers("Fizik", 6, 90);
    Ders kim2=createDers("Kimya",4,65);

    Ders ogrenciDersleri[10] = {mat1, fiz1,kim2};
    Ders ogrenciDersleri2[10] = {kim1,mat2,fiz2};
    Ogrenci ogrenci1 = createOgrenci("Ali", "Veli", "Bilgisayar Muhendisligi", 88.0, ogrenciDersleri);
    Ogrenci ogrenci2 = createOgrenci("Ebru", "Elif", "Biyomedikal Muhendisligi", 78.5, ogrenciDersleri2);

    printf("**********************************************************************************************************************************");
    printf("\nOgrenci Bilgileri:\n");
    printOgrenciInfo(ogrenci1);
    printf("Ogrenci Bilgileri:\n");
    printOgrenciInfo(ogrenci2);
    
    Ogrenci ogrenciler[2]={ogrenci1,ogrenci2};
    int ogrenciSayisi=2;

printf("\nMatematik dersinin ortalama notu: %.2f\n", calculateDersOrtalama(ogrenciler, 2, "Matematik"));
printf("Fizik dersinin ortalama notu: %.2f\n", calculateDersOrtalama(ogrenciler, 2, "Fizik"));
printf("Kimya dersinin ortalama notu: %.2f\n", calculateDersOrtalama(ogrenciler, 2, "Kimya"));

float matStandartSapma = calculateDersStandartSapma(ogrenciler, 2, "Matematik");
printf("\nMatematik Standart Sapma: %.2f\n", matStandartSapma);
float fizStandartSapma = calculateDersStandartSapma(ogrenciler, 2, "Fizik");
printf("Fizik Standart Sapma: %.2f\n", fizStandartSapma);
float kimStandartSapma = calculateDersStandartSapma(ogrenciler, 2, "Kimya");
printf("Kimya Standart Sapma: %.2f\n", kimStandartSapma);
      

    

    listHighGradeStudents(ogrenciler, 2, "Matematik");
   

    writeStudentInfoToFile(ogrenciler, ogrenciSayisi , argv[1]);
    

    

    return 0;
}
