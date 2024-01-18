
/* 
* @file proje1.
* @description Fonksiyonlarımın prototiplerini içeren dosya.
* @assignment 1.proje
* @date 10.12.2023
* @author. Emre Hendemoğlu emre.hendemoglu@stu.fsm.edu.tr
*/
#ifndef PROJE1_H
#define PROJE1_H
#include <stdio.h>

typedef struct {
    char *dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
} Ders;

typedef struct {
    char *ogrAdi;
    char *ogrSoyAdi;
    char *bolumu;
    float ortalama;
    Ders *aldigiDersler;
} Ogrenci;

Ders createDers( char *dersAdi, unsigned short int kredi, unsigned short int puan);
Ogrenci createOgrenci( char *ogrAdi,  char *ogrSoyAdi,  char *bolumu, float ortalama,  Ders *aldigiDersler);
void printOgrenciInfo( Ogrenci ogrenci);
void printOgrenciArrayInfo( Ogrenci *ogrenciler, int size);
float calculateDersOrtalama( Ogrenci *ogrenciler, int ogrenciSayisi,  char *dersAdi);
float calculateDersStandartSapma( Ogrenci *ogrenciler, int ogrenciSayisi,  char *dersAdi);
void listHighGradeStudents(Ogrenci *ogrenciler, int ogrenciSayisi, char *dersAdi);
void writeStudentInfoToFile( Ogrenci *ogrenciler, int ogrenciSayisi,  char *dosyaAdi);
Ogrenci* readStudentsFromFile(int *ogrenciSayisi,  char *dosyaAdi);

#endif