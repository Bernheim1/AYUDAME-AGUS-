#ifndef CAMION_CHOFER_H_INCLUDED
#define CAMION_CHOFER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Camion_Chofer.h"
#include "Camion.h"
#include "Chofer.h"
#define LIBRE 0
#define OCUPADO 1
#define MAXCHOFERES 12
#define MAXCAMIONES 25
int cargar_Nombrechofer(char nombre_chofer[],int id_camion, eChoferes listachofer[], int tamChofer);
void mostrar_Camion (eCamiones camion, eChoferes listachofer[],int tam_chofer );
void Mostrar_Listacamiones(eCamiones listacamion[], int tam, eChoferes listachofer[],int tamchofer);
void alta_camion (eCamiones listacamion[],int tamcamion, eChoferes listachofer[],int tamchofer);
void modificar_camion (eCamiones listacamion[], int tam,eChoferes listachofer[],int tamchofer);
void ordenar_Camion_portipo (eCamiones listacamion[],int tam,eChoferes listachofer[] ,int tamchofer);

void mostrar_UnCamion (eCamiones camion);
void mostrarChofer_yCamion (eChoferes listachofer[],int tamchofer,eCamiones listacamion[],int tamcamion);

#endif // CAMION_CHOFER_H_INCLUDED
