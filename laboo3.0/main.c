#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Camion_Chofer.h"
#include "Camion.h"
#include "Chofer.h"
#define LIBRE 0
#define OCUPADO 1
#define MAXCHOFERES 12
#define MAXCAMIONES 25

/*////***********************************ESTRUCTURAS ***************************************
typedef struct
{
  int idchofer;
  char nombre[30];
  char apellido[30];
  int dni ;
  int legajo;
  char nacionalidad[30];
  int telefono;
  int  edad;
  char sexo[10];
  int estado;
}eChoferes;
//////////////////////////////////////////////////////////////////////////////////////
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

// //***********************************FIRMAS CHOFER ***************************************
int menu ();
void inicializar_estado (eChoferes listachofer[],int tam);
int generar_Idchofer (eChoferes listachofer[],int tam);
int buscarid_chofer(eChoferes listachofer[], int tam);
void hardcodeo_Choferes(eChoferes listachofer[], int tam);
int buscarLibre_chofer(eChoferes listachofer[], int tam);
void mostrar_Chofer (eChoferes chofer);
void Mostrar_Listachoferes(eChoferes listachofer[], int tam);
void alta_chofer (eChoferes listachofer[], int tam);
void baja_Chofer (eChoferes listachofer[], int tam);
void modificar_chofer(eChoferes listachofer[], int tam);*/
//*********************************** FIRMAS CAMION ***************************************
/*void inicializar_estadocamion (eCamiones listacamion[],int tam);
int generar_Idcamion (eCamiones listacamion[],int tam);
int buscarid_camion(eCamiones listacamion[], int tam);
void hardcodeo_Camiones(eCamiones listacamion[], int tam);
int buscarLibre_camion(eCamiones listacamion[], int tam);//copiado hasta aca
int cargar_Nombrechofer(char nombre_chofer[],int id_camion, eChoferes listachofer[], int tamChofer);
void mostrar_Camion (eCamiones camion, eChoferes listachofer[],int tam_chofer );
void Mostrar_Listacamiones(eCamiones listacamion[], int tam, eChoferes listachofer[],int tamchofer);
void alta_camion (eCamiones listacamion[],int tamcamion, eChoferes listachofer[],int tamchofer);
//void baja_Camion (eCamiones listacamion[], int tam);
void modificar_camion (eCamiones listacamion[], int tam,eChoferes listachofer[],int tamchofer);
void ordenar_Camion_portipo (eCamiones listacamion[],int tam,eChoferes listachofer[] ,int tamchofer);
//***********************************FIRMAS CAMION_CHOFER ***************************************
void mostrar_UnCamion (eCamiones camion);
void mostrarChofer_yCamion (eChoferes listachofer[],int tamchofer,eCamiones listacamion[],int tamcamion);
*/


int main()
{
    eChoferes lista_choferes[MAXCHOFERES];
    eCamiones lista_camiones[MAXCAMIONES];

    inicializar_estado (lista_choferes,MAXCHOFERES);
    inicializar_estadocamion (lista_camiones,MAXCAMIONES);

    hardcodeo_Choferes(lista_choferes, MAXCHOFERES);
    hardcodeo_Camiones(lista_camiones, MAXCAMIONES);




    int posicion =buscarLibre_chofer (lista_choferes,MAXCHOFERES);
   printf("%d",posicion);
    do
    {
        switch (menu())
        {
            case 1:
            Mostrar_Listachoferes(lista_choferes,MAXCHOFERES);
            break;
            case 2:
            Mostrar_Listacamiones( lista_camiones,MAXCAMIONES, lista_choferes,MAXCHOFERES);
            break;
            case 3:
            mostrarChofer_yCamion (lista_choferes,MAXCHOFERES,lista_camiones,MAXCAMIONES);
            break;
            case 4:
            alta_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 5:
            modificar_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 6:
            modificar_camion (lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 7:
            alta_chofer(lista_choferes,MAXCHOFERES);
            break;
            case 8:
            baja_Chofer(lista_choferes,MAXCHOFERES);
            break;
            case 9:
            ordenar_Camion_portipo(lista_camiones,MAXCAMIONES,lista_choferes,MAXCHOFERES);
            break;
            case 10:
            modificar_chofer(lista_choferes,MAXCHOFERES);
            break;
            case 11:
            //mostrar_chofercon_camiones(lista_choferes,MAXCHOFERES,lista_camiones,MAXCAMIONES);
            break;
        }

    }while((menu())!=14);


    printf("Hello world!\n");
    return 0;
}

/* //***********************************FUNCIONES CHOFER ***************************************
// menu
int menu ()
{
  int opcion = 0;
  printf ("\n 1.   LISTA CHOFER ");
  printf ("\n 2.   LISTA CAMION/CHOFER   ");
  printf ("\n 3.   LISTA CHOFER / CAMION ");
  printf ("\n 4.   ALTA CAMION  ");
  printf ("\n 5.   BAJA CAMION ");
  printf ("\n 6.   MODIFICAR CAMION ");
  printf ("\n 7.   ALTA CHOFER ");
  printf ("\n 8.   BAJA CHOFER ");
  printf ("\n 9.   ORDENAR CAMION *TIPO ");
  printf ("\n 10.  MODIFICAR CHOFER");
  printf ("\n 11.  MOSTRAR CHOFER CON CAMIONES");
  printf ("\n 12.  ");
  printf ("\n 13.  ");
  printf ("\n 14.  ");
  printf ("\n\t\t SELECCIONE UNA OPCION:  ");
  scanf("%d",&opcion);
    return opcion;
}
//iniciar
void inicializar_estado (eChoferes listachofer[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        listachofer[i].estado = LIBRE;
    }
}
// hardcodear datos

void hardcodeo_Choferes(eChoferes listachofer[], int tam)
{
    char nombre[6][30]= {"lucrecia","jorge","natalia","matias","jeremias","santiago"};
    char apellido[6][30]= {"perez","davila","ramirez","peon","arias","bolounes"};
    int dni[6] = {958893,956578,957592,959463,957693,956593};
    int legajo[6]= {1234,1237,1236,12348,1239,1235};
    char nacionalidad[6][30]= {"colombiano","venezolano","boliviano","uruguayo","argentino","checo"};
    int telefono[6]= {111111,112222,1155555,1166666,1133333,1144444};
    int edad[6]={45,23,45,14,41,25};
    char sexo [6][10]= {"femenino","masculino","femenino","femenino","masculino","masculino"};
    int estado_ [6]={1,1,1,1,1,1};
    int id_ = generar_Idchofer (listachofer,tam);
    int i;

    for (i=0; i<6; i++)
    {
         listachofer[i].idchofer =id_++;
         strcpy(listachofer[i].nombre,nombre[i]);
         strcpy(listachofer[i].apellido,apellido[i]);
         listachofer[i].dni = dni[i];
         listachofer[i].legajo = legajo[i];
         strcpy(listachofer[i].nacionalidad,nacionalidad[i]);
         listachofer[i].telefono = telefono[i];
         listachofer[i].edad = edad[i];
         strcpy(listachofer[i].sexo,sexo[i]);
         listachofer[i].estado = estado_[i];

    }
}


// generar  id
int generar_Idchofer (eChoferes listachofer[],int tam)
{
   int id_aux = 999;
   int i;
   for (i=0;i<tam;i++)
   {
       if (listachofer[i].estado == OCUPADO)
       {
            if (listachofer[i].idchofer>id_aux)
            {
                id_aux = listachofer[i].idchofer;
            }
       }

   }
    return id_aux +1;
}

// buscar por id
int buscarid_chofer(eChoferes listachofer[], int tam)
{
    int i;
    int aux_id=-1;
    int retorno;
    printf ("\n Ingrese el id a buscar:\n");
    scanf("%d",&aux_id);

    for(i=0; i<tam; i++)
    {
      if( listachofer[i].idchofer==aux_id)
        {
            retorno=i;
            break;
        }
    }
  return retorno;
}

// buscar libre
int buscarLibre_chofer(eChoferes listachofer[], int tam)
{
    int j;
    int index = -1;
    for (j=0;j<tam;j++)
    {
        if (listachofer[j].estado==LIBRE )
        {
            index = j;
        }
    }
    return  index;
}
// mostrar un chofer
void mostrar_Chofer (eChoferes chofer)
{
    printf(" %10d %10s %10s %10d %10d %10s %10d %10d %10s %10d \n ",chofer.idchofer,
                                              chofer.nombre,
                                              chofer.apellido,
                                              chofer.dni,
                                              chofer.legajo,
                                              chofer.nacionalidad,
                                              chofer.telefono,
                                              chofer.edad,
                                              chofer.sexo,
                                              chofer.estado);



}

// Mostrar Lista de choferes
void Mostrar_Listachoferes(eChoferes listachofer[], int tam)
{
    int i ;
    printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");

        for (i=0;i<tam;i++)
        {
            if (listachofer[i].estado == OCUPADO)
            {
                mostrar_Chofer (listachofer[i]);

            }
        }
}
// alta chofer
void alta_chofer (eChoferes listachofer[], int tam)
{
    int posicion;
    char respuesta;
    int aux_id;
    eChoferes aux_chofer;

    aux_id = generar_Idchofer(listachofer,tam);
    posicion = buscarLibre_chofer(listachofer,tam);

    if (posicion!=-1)
    {
        printf ("\n INGRESE NOMBRE: \n");
        fflush (stdin);
        fgets(aux_chofer.nombre,30,stdin);

        printf ("\n INGRESE APELLIDO: \n");
        fflush (stdin);
        fgets(aux_chofer.apellido,30,stdin);

        printf ("\n INGRESE DNI: \n");
        scanf("%d",&aux_chofer.dni);

        printf ("\n INGRESE LEGAJO: \n");
        scanf("%d",&aux_chofer.legajo);

        printf ("\n INGRESE NACIONALIDAD: \n");
        fflush (stdin);
        fgets(aux_chofer.nacionalidad,30,stdin);

        printf ("\n INGRESE TELEFONO: \n");
        scanf("%d",&aux_chofer.telefono);

        printf ("\n INGRESE EDAD: \n");
        scanf("%d",&aux_chofer.edad);

        printf ("\n INGRESE SEXO: \n");
        fflush (stdin);
        fgets(aux_chofer.sexo,10,stdin);

        aux_chofer.idchofer = aux_id;

        printf("\n Desea agregar el Chofer? (s/n)\n" );
        fflush (stdin);
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            aux_chofer.estado = OCUPADO;
            listachofer[posicion]=aux_chofer;
            printf ("\n\t** CHOFER CARGADO CON EXITO!!  **\n ");

        }else
        {
            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
        }
    }else
    {
        printf ("\n\t** NO SE ENCONTRO ESPACIO *LLENO*.  **\n ");
    }
}
// baja chofer
 void baja_Chofer (eChoferes listachofer[], int tam)
 {
    int posicion;
    char respuesta;

    Mostrar_Listachoferes(listachofer,tam);
    posicion = buscarid_chofer(listachofer,tam);
    if (posicion != -1)
    {
        printf("\n\t*** CHOFER ENCONTRADO! ***\n");
        printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");
        mostrar_Chofer(listachofer[posicion]);

        printf("\n Desea eliminar de forma permanente el chofer? (s/n) \n");
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            listachofer[posicion].estado=LIBRE;
            printf("\n\t*** CHOFER ELIMINADO! ***\n");
        }

    }else
    {
        printf("\n\t*** CHOFER NO ENCONTRADO! ***\n");
    }
 }
 // modificar chofer
  void modificar_chofer(eChoferes listachofer[], int tam)
  {
      int id_posicion;
      char aux_char[30];
      int aux_int;
      char respuesta;
      eChoferes aux_chofer;
      Mostrar_Listachoferes(listachofer,tam);
      id_posicion = buscarid_chofer(listachofer,tam);

      if(id_posicion!=-1)
      {
          printf("\n\t*** CHOFER ENCONTRADO! ***\n");
          printf("\n id:   nombre:   apellido:  dni:  legajo:  nacionalidad:  tel:  edad:  sexo:  \n");
          mostrar_Chofer(listachofer[id_posicion]);
          aux_chofer=listachofer[id_posicion];

        printf ("\n RE-INGRESE NOMBRE: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.nombre,aux_char);

        printf ("\n RE-INGRESE APELLIDO: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.apellido,aux_char);


        printf ("\n RE-INGRESE DNI: \n");
        scanf("%d",&aux_int);
        aux_chofer.dni=aux_int;

        printf ("\n RE-INGRESE LEGAJO: \n");
        scanf("%d",&aux_int);
        aux_chofer.legajo=aux_int;

        printf ("\n RE-INGRESE NACIONALIDAD: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.nacionalidad,aux_char);

        printf ("\n RE-INGRESE TELEFONO: \n");
        scanf("%d",&aux_int);
        aux_chofer.telefono=aux_int;

        printf ("\n RE-INGRESE EDAD: \n");
        scanf("%d",&aux_int);
        aux_chofer.edad=aux_int;

        printf ("\n RE-INGRESE SEXO: \n");
        fflush (stdin);
        gets(aux_char);
        strcpy(aux_chofer.sexo,aux_char);

        printf ("\n** Desea efectuar los cambios? (s/n) **\n");
            scanf("%s",&respuesta );
            if (respuesta == 's')
            {
                listachofer[id_posicion] = aux_chofer;
                printf ("\n\t** CAMBIOS EFECTUADOS! **\n");
            }else
            {
                printf ("\n\t** CAMBIOS CANCELADOS! **\n");
            }
      }
  }
//***********************************FUNCIONES CAMION ***************************************
// hardcodear datos

void hardcodeo_Camiones(eCamiones listacamion[], int tam)
{

    char patente[10][10]= {"027-lpe","039-nri","456-lia","123-ias","853-ias","567-ago","103-mvt","451-tbe","172-rty","547-aoq"};
    char marca[10][10]= {"ford","ford","fiat","fiat","wv","ford","ford","ford","ford","ford"};
    int anio[10] = {2000,2000,2001,2001,2010,2005,2005,2015,2020,2020};
    int peso[10]= {1239,2345,3456,4567,5678,6789,7235,2643,1287,9672};
    int cantidadruedas[10]= {4,6,4,4,8,4,4,6,4,10};
    char tipo [10][20]= {"cortaDistancia","largaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","cortaDistancia","largaDistancia","largaDistancia","largaDistancia"};
    int idchofer[10]= {1000,1000,1001,1001,1002,1003,1003,1004,1004,1004};
    int estados [10] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};
    int id_ = generar_Idcamion ( listacamion, tam);
    int i;

    for (i=0; i<tam; i++)
    {
         strcpy(listacamion[i].patente,patente[i]);
         strcpy(listacamion[i].marca,marca[i]);
         listacamion[i].anio = anio[i];
         listacamion[i].peso = peso[i];
         listacamion[i].cantidadruedas = cantidadruedas[i];
         strcpy(listacamion[i].tipo,tipo[i]);
         listacamion[i].estado = estados[i];
         listacamion[i].idchofer= idchofer[i];

             listacamion[i].idcamion = id_++;

    }
}
// inicializar estado
void inicializar_estadocamion (eCamiones listacamion[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        listacamion[i].estado = LIBRE;
    }
}
// generar id
int generar_Idcamion (eCamiones listacamion[],int tam)
{
     int id_aux = 9999;
   int i;
   for (i=0;i<tam;i++)
   {
       if (listacamion[i].estado == OCUPADO)
       {
            if (listacamion[i].idcamion>id_aux)
            {
                id_aux = listacamion[i].idcamion;
            }
       }

   }
    return id_aux +1;
}
// buscar por id
int buscarid_camion(eCamiones listacamion[], int tam)
{
    int i;
    int aux_id=-1;
    int retorno;
    printf ("\n Ingrese el id a buscar:\n");
    scanf("%d",&aux_id);

    for(i=0; i<tam; i++)
    {
      if( listacamion[i].idcamion==aux_id)
        {
            retorno=i;
            break;
        }
    }
  return retorno;
}
// buscar libre
int buscarLibre_camion(eCamiones listacamion[], int tam)
{
    int i;
    int index = -1;
    for (i=0;i<tam;i++)
    {
        if (listacamion[i].estado==LIBRE)
        {
            index = i;
        }
    }
    return  index;
}
// cargar nombrechofer
int cargar_Nombrechofer(char nombre_chofer[],int id_camion, eChoferes listachofer[], int tamChofer)
{
    int todoOK = 0;

    for(int i=0; i<tamChofer; i++)
    {
        if(listachofer[i].idchofer==id_camion)
        {
            strcpy(nombre_chofer,listachofer[i].nombre);
            todoOK = 1;
        }
    }

    return todoOK;
}
// mostrar un camion
void mostrar_Camion (eCamiones camion, eChoferes listachofer[],int tam_chofer )
{
    char  nombrechofer [30];
    cargar_Nombrechofer(nombrechofer,camion.idchofer, listachofer,tam_chofer);

    printf("\t %10d  %10s  %10s  %10d  %10dkg. %10d  %10s  %10s   \n\n ",camion.idcamion,
                                                                camion.patente,
                                                                camion.marca,
                                                                camion.anio,
                                                                camion.peso,
                                                                camion.cantidadruedas,
                                                                camion.tipo,
                                                                nombrechofer);
}

// Mostrar Lista de camiones
void Mostrar_Listacamiones(eCamiones listacamion[], int tam, eChoferes listachofer[],int tamchofer)
{
    printf("\n id:   patente:    marca:   anio:   peso:   cant/ruedas:   tipo: \n");
    int i;
        for (i=0;i<tam;i++)
        {
            if (listacamion[i].estado == OCUPADO)
            {
               mostrar_Camion (listacamion[i],listachofer, tamchofer );
            }//else
            //{
              //  printf("nada");
            //}
        }
}
 // alta camion
 void alta_camion (eCamiones listacamion[],int tamcamion, eChoferes listachofer[],int tamchofer)
 {
     int posicion;
     int aux_idcamion;
     int auxid;
     char respuesta;

     eCamiones aux_camion;

     posicion = buscarLibre_camion( listacamion,tamcamion);

     if (posicion != -1)
     {
        Mostrar_Listachoferes(listachofer,tamchofer);
        auxid = buscarid_chofer(listachofer,tamchofer);
        if (auxid ==-1)
        {
            printf("\n No existe el chofer.  \n");
            auxid = buscarid_chofer(listachofer,tamchofer);
        }
            aux_camion.idchofer = listachofer[auxid].idchofer;

        aux_idcamion = generar_Idcamion(listacamion,tamcamion);
        printf ("\n INGRESE PATENTE: \n");
        fflush (stdin);
        fgets  (aux_camion.patente,20,stdin);
        printf ("\n INGRESE MARCA: \n");
        fflush (stdin);
        fgets (aux_camion.marca,10,stdin);
        printf ("\n INGRESE ANIO: \n");
        scanf("%d",&aux_camion.anio);
        printf ("\n INGRESE PESO: \n");
        scanf("%d",&aux_camion.peso);
        printf ("\n INGRESE CANTIDAD DE RUEDAS: \n");
        scanf("%d",&aux_camion.cantidadruedas);
        printf ("\n INGRESE EL TIPO: \n");
        fflush (stdin);
        fgets (aux_camion.tipo,20,stdin);
        aux_camion.idcamion = aux_idcamion;


        printf("\n Desea agregar el Camion? (s/n)\n" );
        fflush (stdin);
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            aux_camion.estado = OCUPADO;
            listacamion[posicion]=aux_camion;
            printf ("\n\t** CAMION CARGADO CON EXITO!!  **\n ");

        }else
        {
            printf ("\n\t** SE HA CANCELADO LA CARGA.  **\n ");
        }

     }else
     {
         printf("\n no se encontro libre \n");
     }
 }
 // baja camion
 void baja_Camion (eCamiones listacamion[], int tam)
 {
     int posicion;
    char respuesta;

    posicion = buscarid_camion(listacamion,tam);
    if (posicion != -1)
    {
        printf("\n\t*** CAMION ENCONTRADO! ***\n");
        printf("\n \t       id:   patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");
        mostrar_UnCamion(listacamion[posicion]);

        printf("\n Desea eliminar de forma permanente el camion? (s/n) \n");
        scanf("%s",&respuesta);
        if (respuesta == 's')
        {
            listacamion[posicion].estado = LIBRE;
            printf("\n\t*** CAMION ELIMINADO! ***\n");
        }

    }else
    {
        printf("\n\t*** CAMION NO ENCONTRADO! ***\n");
    }
 }
// modificar camion
void modificar_camion (eCamiones listacamion[], int tam,eChoferes listachofer[],int tamchofer)
{

    int id_Posicion;
    int decision;
    char confirmacion;
    char aux_char[20];
    int aux_int;
    eCamiones aux_camion;

    Mostrar_Listacamiones(listacamion,tam,listachofer,tamchofer);
    id_Posicion = buscarid_camion(listacamion,tam);

    if (id_Posicion != -1)
    {
        printf("\n\t*** CAMION ENCONTRADO! ***\n");
        printf("\n \t       id:   patente:      marca:     anio:       peso:   cant/ruedas:   tipo: \n");

        mostrar_UnCamion(listacamion[id_Posicion]);
        aux_camion=listacamion[id_Posicion];

        printf ("\n** INDIQUE EL DATO A CAMBIAR  **\n");
        printf ("\n** 1. TIPO // 2. CHOFER **\n");
        scanf("%d",&decision);

        switch (decision)
        {
            case 1:
            printf ("\n** RE-INGRESE TIPO:  **\n");
            fflush (stdin);
            fgets (aux_char,20,stdin);
            strcpy(aux_camion.tipo,aux_char);
            printf ("\n** Desea efectuar el cambio? (s/n) **\n");
            scanf("%c",&confirmacion);
            if (confirmacion == 's')
            {
                listacamion[id_Posicion] = aux_camion;
                printf ("\n\t** CAMBIO EFECTUADO! **\n");
            }else
            {
                printf ("\n\t** CAMBIO CANCELADO! **\n");
            }

            break;
            case 2:
            Mostrar_Listachoferes(listachofer,tamchofer);
            printf ("\n** RE-INGRESE ID_CHOFER:  **\n");
            fflush (stdin);
            scanf("%d",&aux_int);
            aux_camion.idchofer=aux_int;
            printf ("\n** Desea efectuar el cambio? (s/n) **\n");
            scanf("%s",&confirmacion);
            if (confirmacion == 's')
            {
                listacamion[id_Posicion] = aux_camion;
                printf ("\n\t** CAMBIO EFECTUADO! **\n");
            }else
            {
                printf ("\n\t** CAMBIO CANCELADO! **\n");
            }
            break;
        }
    }


}
// ordenar camion por TIPO
void ordenar_Camion_portipo (eCamiones listacamion[],int tam,eChoferes listachofer[] ,int tamchofer)
{
    int i;
    int j;
    eCamiones aux_camion;
    for (i=0;i<tam-1;i++)
    {
        for(j=0;j<tam;j++)
        {
            if(strcmp(listacamion[i].tipo,listacamion[j].tipo)<0)// 0=iguales / 1=cadena1>cadena2 / -1= cadena1<cadena2
            {
               aux_camion=listacamion[i];
               listacamion[i]=listacamion[j];
               listacamion[j]=aux_camion;
            }
        }
    }
    printf("\n\t** LISTA ORDENADA! **\n");
    Mostrar_Listacamiones(listacamion,tam,listachofer,tamchofer);
}
//***********************************FUNCIONES CAMION_CHOFER ***************************************
void mostrar_UnCamion (eCamiones camion)
{
    printf("\t %10d %10s %10s %10d %10dkg. %10d %10s   \n ",camion.idcamion,
                                                                camion.patente,
                                                                camion.marca,
                                                                camion.anio,
                                                                camion.peso,
                                                                camion.cantidadruedas,
                                                                camion.tipo);
}

// listado de choferes con su respectivo listado de camiones  bandera=1 SI HAY autos =0 si NO
void mostrarChofer_yCamion (eChoferes listachofer[],int tamchofer,eCamiones listacamion[],int tamcamion)
{
    int i;
    int j;
    char bandera_tiene_camion;
    for (i=0;i<tamchofer;i++)
    {
        mostrar_Chofer(listachofer[i]);
        bandera_tiene_camion ='n';

       for (j=0;j<tamcamion;j++)
        {
            if (listachofer[i].idchofer == listacamion[j].idchofer)
            {
                mostrar_UnCamion(listacamion[j]);
                   bandera_tiene_camion ='s';
            }
        }

        if (bandera_tiene_camion == 'n')
        {
            printf("\n NO TIENE CAMION ");
        }

    }

}*/
