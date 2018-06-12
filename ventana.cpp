#include "ventana.h"
#include "ui_ventana.h"
#include "mainwindow.h"             //Se llama la libreria dentro de ventana.cpp
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include <stdio.h>
#include <QFile>
#include <stdio.h>
#include <QTextStream>

ventana::ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventana)
{
    ui->setupUi(this);
}

ventana::~ventana()
{
    delete ui;
}


void ventana::on_pushButton_2_clicked()
{
     MainWindow *M =new MainWindow;       //Se Crea la variable MainWindow dentro de la función, siendo así una variable local
     M->show();                        //Se muestra el MainWindow
     close();                          //Se cierra la ventana que está abierta
}

void ventana::on_pushButton_3_clicked()
{
    Level1 *l1 =new Level1;
    l1->show();
    close();

    QFile archivo ("puntaje1.txt");    //create file with score
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << puntaje;
        }
        archivo.close();

        FILE *p;   //open the file and read the score
        p=fopen("puntaje1.txt","r");

        if( p==NULL )
        printf("Error al abrir el fichero\n");

        else
        {
            while( !feof(p) )
            printf("%c",getc(p));
            printf("\n");
        }
}



void ventana::on_pushButton_clicked()
{
    Level2 *l2 =new Level2;
    l2->show();
    close();
    QFile archivo ("puntaje2.txt");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << puntaje;
        }
        archivo.close();
    FILE *p2;
    p2=fopen("puntaje2.txt","r");

    if( p2==NULL )
    printf("Error al abrir el fichero\n");

    else
    {
        while( !feof(p2) )
        printf("%c",getc(p2));
        printf("\n");

    }
}

void ventana::on_pushButton_4_clicked()
{
    Level4 *l4 =new Level4;
    l4->show();
    close();
    QFile archivo ("puntaje4.txt");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << puntaje;
        }
        archivo.close();
    FILE *p4;
    p4=fopen("puntaje4.txt","r");

    if( p4==NULL )
    printf("Error al abrir el fichero\n");

    else
    {
        while( !feof(p4) )
        printf("%c",getc(p4));
        printf("\n");

    }
}

void ventana::on_pushButton_5_clicked()
{
    Level5 *l5 =new Level5;
    l5->show();
    close();
    QFile archivo ("puntaje5.txt");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << puntaje;
        }
        archivo.close();
    FILE *p5;
    p5=fopen("puntaje5.txt","r");

    if( p5==NULL )
    printf("Error al abrir el fichero\n");

    else
    {
        while( !feof(p5) )
        printf("%c",getc(p5));
        printf("\n");

    }
}

void ventana::on_pushButton_6_clicked()
{
    Level3 *l3 =new Level3;
    l3->show();
    close();
    QFile archivo ("puntaje3.txt");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << puntaje;
        }
        archivo.close();
    FILE *p3;
    p3=fopen("puntaje3.txt","r");

    if( p3==NULL )
    printf("Error al abrir el fichero\n");

    else
    {
        while( !feof(p3) )
        printf("%c",getc(p3));
        printf("\n");

    }
}
