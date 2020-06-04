#ifndef CAMION_H_INCLUDED
#define CAMION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Camion_Chofer.h"
//#include "Camion.h"
#include "Chofer.h"
#define LIBRE 0
#define OCUPADO 1
#define MAXCHOFERES 12
#define MAXCAMIONES 25
typedef struct
{
  int idcamion;
  char patente[10];
  char marca[10];
  int anio;
  int peso;
  int cantidadruedas;
  char tipo[20];
  int idchofer;
  int estado;
}eCamiones;
void inicializar_estadocamion (eCamiones listacamion[],int tam);
int generar_Idcamion (eCamiones listacamion[],int tam);
int buscarid_camion(eCamiones listacamion[], int tam);
void hardcodeo_Camiones(eCamiones listacamion[], int tam);
int buscarLibre_camion(eCamiones listacamion[], int tam);
void baja_Camion (eCamiones listacamion[], int tam);
#endif // CAMION_H_INCLUDED
