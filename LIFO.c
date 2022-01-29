//Declaración de librerías
#include "stdio.h"
#include "stdlib.h"
#include <ctype.h>

//Declaración de constantes
#define MAXIMO 9

//Declaración de variables
typedef struct _Nodo{
	
	char *nombre;
	char numero_de_cuenta[MAXIMO];
	struct _Nodo *siguiente;
	
}PILA;

PILA *Pila = NULL;

int contador = 0;

//Declaración de funciones
void Inciso_a(void);
void Insertar_elementos(PILA *);
void Inciso_b(void);
void Inciso_c(void);
void Inciso_d(void);

//Función principal
int main(void){
	
	char opcion, respuesta;
	
	do{
		
		system("cls");
		
		printf("\t\tBASE DE DATOS.\n\n");
		printf("Elige una de las siguientes opciones: ");
		printf("\na)Ingresar datos.");
		printf("\nb)Mostrar la base de datos.");
		printf("\nc)Eliminar datos.");
		printf("\nd)Eliminar la base de datos.");
		printf("\ne)Salir.");
		
		printf("\nOpci%cn: ",162);
		fflush(stdin);
		scanf("%c",&opcion);
		
		opcion = tolower(opcion);
		
		switch(opcion){
			
			case 'a':{
				
				Inciso_a();
				
				break;
			}
			case 'b':{
				
				Inciso_b();
				
				break;
			}
			case 'c':{
				
				Inciso_c();
				
				break;
			}
			case 'd':{
				
				Inciso_d();
				
				break;
			}
			case 'e':{
				
				exit(1);
				
				break;
			}
			default:{
				
				system("cls");
				
				printf("\n\n\n\t\t**********************************\n");
				printf("\t\t*                                *\n");
				printf("\t\t*        Opci%cn inv%clida.        *\n",162,160);
				printf("\t\t*                                *\n");
				printf("\t\t**********************************\n");
				
				break;
			}
		}
		
		printf("\n\n\nSi quiere salir del programa tecle una 'N', en caso contrario \noprima cualquier tecla.\n");
		printf("Opci%cn: ",162);
		fflush(stdin);
		scanf("%c", &respuesta);
		
		respuesta = toupper(respuesta);
		
	}while(respuesta != 'N');
	
	return 0;

}

//La función del inciso (a), permite ingresar datos a la PILA.
void Inciso_a(void){
	
	system("cls");
	
	if(contador == 5){
		
		printf("\n\n\n\t***********************************************************\n");
		printf("\t*                                                         *\n");
		printf("\t*  La base de datos se encuentra llena en estos momentos. *\n");
		printf("\t*                                                         *\n");
		printf("\t***********************************************************\n");
		
	}else{
		
		PILA *nodo_auxiliar;
		char cuenta;
		int maximo = 0;
			
		printf("\t\t\tINGRESAR ELEMENTOS\n\n");
		nodo_auxiliar = (PILA *)malloc(sizeof(PILA));
		printf("Ingresa el nombre de la persona: ");
		nodo_auxiliar->nombre = (char *)malloc(sizeof(char)*100);
		fflush(stdin);
		scanf("%[^\n]s",nodo_auxiliar->nombre);
		
		printf("Ingresa el n%cmero de cuenta: ",163);
		fflush(stdin);
		while((cuenta = getchar()) != '\n' && (maximo <= 8)){
			if((cuenta == '0') || (cuenta == '1') || (cuenta == '2') || (cuenta == '3') || (cuenta == '4') || (cuenta == '5') || (cuenta == '5') || (cuenta == '6') || (cuenta == '7') || (cuenta == '8') || (cuenta == '9')){
				nodo_auxiliar->numero_de_cuenta[maximo++] = cuenta;
			}else{
				continue;
			}
		}
		
		nodo_auxiliar->numero_de_cuenta[maximo] = '\0';
		
		contador = contador + 1;
		
		printf("\n\n\n\n");
		printf("Los elementos ingresado a la base de datos fueron: ");
		printf("\nNombre: %s",nodo_auxiliar->nombre);
		printf("\nN%cmero de cuenta: %s",163,nodo_auxiliar->numero_de_cuenta);
		
		Insertar_elementos(nodo_auxiliar);
	}
	
}

void Insertar_elementos(PILA *nodo_auxiliar){
	
	if(Pila == NULL){
		
		nodo_auxiliar->siguiente = NULL;
		Pila = nodo_auxiliar;
	
	}else{
		
		nodo_auxiliar->siguiente = Pila;
		Pila = nodo_auxiliar;
	}
}

//La función del inciso (b), permite mostrar los elementos y la cantidad de elementos ingresados de la PILA
void Inciso_b(void){
	
	system("cls");
	
	if(Pila == NULL){
		
		printf("\n\n\n\t\t******************************************************\n");
		printf("\t\t*                                                    *\n");
		printf("\t\t*  No existen elementos dentro de la base de datos.  *\n");
		printf("\t\t*                                                    *\n");
		printf("\t\t******************************************************\n");
		
	}else{
		
		PILA *Elementos = NULL;
		
		Elementos = Pila;
		
		printf("**********************************************************************\n");
		printf("  NUMERO DE CUENTA\t|\t\tNOMBRE\n");
		printf("**********************************************************************\n");
		
		while(Elementos != NULL){
			
			printf(" %s\t\t|\t    %s\n",Elementos->numero_de_cuenta,Elementos->nombre);
			printf("**********************************************************************\n");	
			Elementos = Elementos->siguiente;
		
		}
		
		printf("\n\n");
		printf("La cantidad de elementos ingresados es: %d\n",contador);
		printf("*************************************************************************\n\n");
		
	}
}

//La función del inciso (c), permite borrar elementos de la PILA
void Inciso_c(void){
	
	system("cls");
	
	if(Pila == NULL){
		
		printf("\n\n\n\t\t*******************************************\n");
		printf("\t\t*                                         *\n");
		printf("\t\t*       La pila se encuentra vac%ca.       *\n",161);
		printf("\t\t*                                         *\n");
		printf("\t\t*******************************************\n");
	
	}else{
		
		PILA *Eliminar = NULL;
		
		Eliminar = Pila->siguiente;
		free(Pila);
		Pila = Eliminar;
	}
	
}

//La función del inciso (d), permite eliminar toda la PILA
void Inciso_d(void){
	
	system("cls");
	
	if(Pila == NULL){
		
		printf("\n\n\n\n\t\t***************************************\n");
		printf("\t\t*                                     *\n");
		printf("\t\t*     La base de datos no existe.     *\n");
		printf("\t\t*                                     *\n");
		printf("\t\t***************************************\n");
		
	}else{
		
		free(Pila);
		Pila = NULL;
		
		printf("\n\n\n\t\t********************************************************\n");
		printf("\t\t*                                                      *\n");
		printf("\t\t*  La base de datos ha sido eliminada exitosamente.    *\n");
		printf("\t\t*                                                      *\n");
		printf("\t\t********************************************************\n");
	
	}
	
}
