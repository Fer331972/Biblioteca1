#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Biblioteca
{
	int numl; //Numero del libro
	char nombrel[100]; //Nombre del libro
	char autor[50]; //Autor del libro
	int dia, mes, año;//Fecha de compra
	int paginas; //Paginas del libro
	int cal; //Calificacion del libro
	char opinion[100]; //Opinion del libro
	char genero[50]; //Genero del libro
	char estado[50]; //Leido,No leido,leyendo
	int activo = 0;//Valida si hay informacion en el struct
}B[600];
void imprimir();
void archivos();
void leer();
int main()
{
	leer();
	setlocale(LC_ALL, "spanish");
	int op;
	int i, j; //Variables contadoras
	int d; //Variable para los switches
	do
	{
		//NO rectificar los cambios ya añadidos a github
		system("cls");
		printf("\n--Menú Principal--\n");
		printf("\n1.-Añadir libros");
		printf("\n2.-Modificar Estado");
		printf("\n3.-Libros Completos");
		printf("\n4.-Listado de libros");
		printf("\n5.-Eliminar libros");
		printf("\n6.-Salir");
		printf("\nSeleccione: ");
		scanf("%d", &d);
		fflush(stdin);
		switch (d)
		{
			//Añadir libros
		case 1:
			do
			{
				system("cls");
				op = 0;
				while ((getchar() != '\n')) { fflush(stdin); }
				printf("\n--Añadir Libros--\n");
				//Encuentra un espacio vacio
				for (i = 0; i <= 599; i++)
				{
					if (B[i].activo == 0)
					{
						j = i;
						B[i].numl = i + 1;
						break;
					}
				}
				printf("\nEscriba el nombre del libro: ");
				gets_s(B[j].nombrel);
				printf("\nAutor del libro: ");
				gets_s(B[j].autor);
				//Validar mayusculas, añadir genero
				do
				{
					op = 0;
					printf("\nNota:El genero solo puede ir en mayusculas");
					printf("\nGenero: ");
					gets_s(B[j].genero);
					for (i = 0; i <= 49; i++)
					{
						if (islower(B[j].genero[i]) != 0)
						{
							printf("\nSolo solo puede ser en mayusculas, intente de nuevo...");
							op = 1;
							break;
						}
					}
				} while (op == 1);
				//Validar paginas
				do
				{
					op = 0;
					printf("\nPaginas: ");
					scanf("%d", &B[j].paginas);
					if (B[j].paginas <= 0)
					{
						printf("\nNo se aceptan valores negativos, intente de nuevo...");
						op = 1;
					}
				} while (op == 1);
				//Validar estado
				do
				{
					op = 0;
					printf("\n\n--Estado--");
					printf("\n1.-Leido");
					printf("\n2.-No leido");
					printf("\n3.-Leyendo");
					printf("\nSeleccione: ");
					scanf("%d", &d);
					switch (d)
					{
						//Leido
					case 1:
						strcpy(B[j].estado, "Leido");
						//Calificacion
						do
						{
							op = 0;
							printf("\nCalificacion: ");
							scanf("%d", &B[j].cal);
							if (B[j].cal < 0 || B[j].cal > 10)
							{
								printf("\nNo se aceptan valores negativos o numero mayores a 10, intente de nuevo...");
								op = 1;
							}
						} while (op == 1);
						while ((getchar() != '\n')) { fflush(stdin); }
						printf("Opinion: ");
						gets_s(B[j].opinion);
						break;
						//No leido
					case 2:
						strcpy(B[j].estado, "No leido");
						break;
						//Leyendo
					case 3:
						strcpy(B[j].estado, "Leyendo");
						break;
						//Opcion default
					default:
						printf("\nEsa opción no esta en el menú,intente de nuevo...\n");
						op = 1;
						break;
					}
				} while (op == 1);
				//Validar fechas
				do
				{
					op = 0;
					printf("\nDigite la fecha de la siguiente manera d/m/aaaa\nFecha de compra: ");
					scanf("%d/%d/%d", &B[j].dia, &B[j].mes, &B[j].año);
					//Validar dias
					if (B[j].dia <= 0 || B[j].dia > 31)
					{
						printf("Fecha incorrecta, intente de nuevo...");
						op = 1;
					}
					//Validar febrero
					if (B[j].mes == 2)
					{
						if (B[j].dia <= 0 || B[j].dia > 28)
						{
							printf("\nFecha incorrecta, intente de nuevo...");
							op = 1;
						}
					}
					//Validar meses
					if (B[j].mes <= 0 || B[j].mes > 12)
					{
						printf("\nMes incorrecto, intente de nuevo...");
						op = 1;
					}
					//Validar año
					if (B[j].año < 2010 || B[j].año > 2030)
					{
						printf("\nAño incorrecto, intente de nuevo...");
						op = 1;
					}
				} while (op == 1);
				B[j].activo = 1;
				printf("\nLibro añadido con exito...\n");
				system("pause");
			} while (op == 1);
			break;
			//Modificar libros
		case 2:
			do
			{
				system("cls");
				op = 0; int n;
				printf("\n--Modificar Estado--\n");
				printf("\nNumero del libro a modificar: ");
				scanf("%d", &n);
				fflush(stdin);
				for (i = 0; i <= 599; i++)
				{
					if (n == B[i].numl)
					{
						n = -1;
						//Valida que no este leido
						if (strcmp(B[i].estado, "Leido") == 0)
						{
							printf("\nEl estado leido no se puede modificar, intente de nuevo...\n");
							system("pause");
							op = 1;
							break;
						}
						printf("\nNumero de libro: %d", B[i].numl);
						printf("\nNombre del libro: %s", B[i].nombrel);
						printf("\nAutor del libro: %s", B[i].autor);
						printf("\nEstado del libro: %s", B[i].estado);
						printf("\n--Nuevo Estado--\n");
						printf("\n1.-Leido");
						printf("\n2.-No leido");
						printf("\n3.-Leyedo");
						printf("\nSeleccione: ");
						scanf("%d", &d);
						fflush(stdin);
						switch (d)
						{
							//Leido
						case 1:
							do
							{
								op = 0;
								printf("\nCalificacion: ");
								scanf("%d", &B[i].cal);
								fflush(stdin);
								if (B[i].cal < 0 || B[i].cal > 10)
								{
									printf("\nNo se aceptan valores negativos o mayores a 10, intente de nuevo...\n");
									system("pause");
									op = 1;
								}
								if (op == 1) { continue; }
								while ((getchar() != '\n')) { fflush(stdin); }
								printf("\nOpinion: ");
								gets_s(B[i].opinion);
								strcpy(B[i].estado, "Leido");
								printf("Modificado con exito...\n");
								system("pause");
							} while (op == 1);
							break;
							//No Leido
						case 2:
							strcpy(B[i].estado, "No leido");
							printf("\nModificado exitosamente...\n");
							system("pause");
							break;
							//Leyendo
						case 3:
							strcpy(B[i].estado, "Leyendo");
							printf("\nModificado exitosamente...\n");
							system("pause");
							break;
							//Opcion default
						default:
							printf("\nEsa opción no esta en el menú, intente de nuevo...\n");
							system("pause");
							op = 1;
							break;
						}
					}
					if (i == 599 && n != -1)
					{
						printf("\nEl libro no existe,intente de nuevo...\n");
						system("pause");
						op = 1; break;
					}
				}
			} while (op == 1);
			break;
			//Libros completos
		case 3:
			do
			{
				int n;
				op = 0;
				system("cls");
				printf("\n--Listado de libros--");
				//Impresion de libros
				for (i = 0; i <= 599; i++)
				{
					if (B[i].activo == 1)
					{
						printf("\n\nNumero de libro: %d", B[i].numl);
						printf("\nNombre del libro: %s", B[i].nombrel);
						printf("\nAutor del libro: %s", B[i].autor);
					}
				}
				printf("\n\nSeleccione un libro para desplegar: ");
				scanf("%d", &n);
				for (i = 0; i <= 599; i++)
				{
					if (n == B[i].numl)
					{
						n = -1;
						printf("\n\nNumero de libro: %d", B[i].numl);
						printf("\nNombre: %s", B[i].nombrel);
						printf("\nAutor: %s", B[i].autor);
						printf("\nGenero: %s", B[i].genero);
						printf("\nPaginas: %d", B[i].paginas);
						printf("\nFecha de compra: %d/%d/%d", B[i].dia, B[i].mes, B[i].año);
						printf("\nEstado: %s", B[i].estado);
						printf("\nCalificacion: %d", B[i].cal);
						printf("\nOpinion: %s\n", B[i].opinion);
						system("pause");
					}
					else if (i == 599 && n != -1)
					{
						printf("\nEl libro no existe, intente de nuevo...\n");
						system("pause");
						op = 1; break;
					}
				}
			} while (op == 1);
			break;
			//Listado de libros
		case 4:
			do
			{
				op = 0;
				system("cls");
				printf("\n1.-Buscar por genero");
				printf("\n2.-Buscar por numero");
				printf("\n3.-Listado completo");
				printf("\nSeleccione: ");
				scanf("%d", &d);
				fflush(stdin);
				switch (d)
				{
					//Buscar por genero
				case 1:
					do
					{
						op = 0;
						char gen[50];
						system("cls");
						while ((getchar() != '\n')) { fflush(stdin); }
						printf("\n--Busqueda por genero--\n");
						printf("\nEscriba el genero: ");
						gets_s(gen);
						for (i = 0; i <= 49; i++)
						{
							if (islower(gen[i] != 0))
							{
								printf("\nEl genero debe estar en mayusculas,intente de nuevo...\n");
								op = 1;
								system("pause"); break;
							}
						}
						if (op == 1) { continue; }
						for (i = 0; i <= 599; i++)
						{
							if (strcmp(gen, B[i].genero) == 0)
							{
								printf("\n\nNumero de libro: %d", B[i].numl);
								printf("\nNombre: %s", B[i].nombrel);
								printf("\nAutor: %s", B[i].autor);
								printf("\nGenero: %s", B[i].genero);
								printf("\nPaginas: %d", B[i].paginas);
								printf("\nFecha de compra: %d/%d/%d", B[i].dia, B[i].mes, B[i].año);
								printf("\nEstado: %s", B[i].estado);
								if (strcmp(B[i].estado, "Leido") == 0)
								{
									printf("\nCalificacion: %d", B[i].cal);
									printf("\nOpinion: %s", B[i].opinion);
								}
							}
						}
						printf("\n");
						system("pause");
					} while (op == 1);
					break;
					//Buscar por numero
				case 2:
					do
					{
						op = 0;
						int n;
						system("cls");
						printf("\n--Busqueda por numero--\n");
						printf("\nIngrese el numero del libro: ");
						scanf("%d", &n);
						fflush(stdin);
						if (n <= 0)
						{
							printf("\nEl numero no puede ser negativo, intente de nuevo...\n");
							continue;
						}
						for (i = 0; i <= 599; i++)
						{
							if (n == B[i].numl)
							{
								n = -1;
								printf("\n\nNumero de libro: %d", B[i].numl);
								printf("\nNombre: %s", B[i].nombrel);
								printf("\nAutor: %s", B[i].autor);
								printf("\nGenero: %s", B[i].genero);
								printf("\nPaginas: %d", B[i].paginas);
								printf("\nFecha de compra: %d/%d/%d", B[i].dia, B[i].mes, B[i].año);
								printf("\nEstado: %s", B[i].estado);
								if (strcmp(B[i].estado, "Leido") == 0)
								{
									printf("\nCalificacion: %d", B[i].cal);
									printf("\nOpinion: %s", B[i].opinion);
								}
							}
							else if (i == 599 && n != -1)
							{
								printf("\nEl libre no fue encontrado,volviendo al menu...\n");
								system("pause");
							}
						}
						system("pause");
					} while (op == 1);
					break;
					//Listado completo
				case 3:
					imprimir();
					printf("\n");
					system("pause");
					break;
					//Opcion default
				default:
					printf("\nEsa opción no esta en el menú, intente de nuevo...\n");
					system("pause");
					op == 1;
					break;
				}

			} while (op == 1);
			break;
			//Eliminar libros
		case 5:
			do
			{
				op = 0;
				int n;
				system("cls");
				printf("\n--Eliminar libros--\n");
				printf("\nNumero del libro a eliminar: ");
				scanf("%d", &n);
				for (i = 0; i <= 599; i++)
				{
					if (n == B[i].numl)
					{
						n = -1;
						B[i].numl = 0;
						strcpy(B[i].nombrel, " ");
						strcpy(B[i].autor, " ");
						strcpy(B[i].genero, " ");
						strcpy(B[i].estado, " ");
						strcpy(B[i].opinion, " ");
						B[i].dia = 0, B[i].mes = 0, B[i].año = 0;
						B[i].paginas = 0;
						B[i].cal = 0;
						B[i].activo = 0;
						printf("\nLibro eliminado con exito...\n");
						system("pause");
					}
					else if (i == 599 && n != -1)
					{
						printf("\nEl libro no existe volviendo al menú...\n");
						system("pause");
					}
				}
			} while (op == 1);
			break;
			//Salir
		case 6:
			archivos();
			return 1;
			break;
			//Opción default
		default:
			printf("\nEsa opción no esta en el menú, intente de nuevo...\n");
			system("pause");
			break;
		}
		op = 1;
	} while (op == 1);
	//Final de codigo
	return 0;
}

void imprimir()
{
	int i;
	system("cls");
	printf("\n--Listado de libros--\n");
	for (i = 0; i <= 599; i++)
	{
		if (B[i].activo == 1)
		{
			printf("\n\nNumero de libro: %d", B[i].numl);
			printf("\nNombre: %s", B[i].nombrel);
			printf("\nAutor: %s", B[i].autor);
			printf("\nGenero: %s", B[i].genero);
			printf("\nPaginas: %d", B[i].paginas);
			printf("\nFecha de compra: %d/%d/%d", B[i].dia, B[i].mes, B[i].año);
			printf("\nEstado: %s", B[i].estado);
			if (strcmp(B[i].estado, "Leido") == 0)
			{
				printf("\nCalificacion: %d", B[i].cal);
				printf("\nOpinion: %s", B[i].opinion);
			}
		}
	}
}
void archivos()
{
	FILE* Archivo;
	Archivo = fopen("Libros.txt", "wb");
	int t = 0;
	int i;
	//Define el tamaño del struct
	for (i = 0; i <= 599; i++)
	{
		if (B[i].activo == 1) { t++; }
	}
	fwrite(B, sizeof(Biblioteca), t, Archivo);
	fflush(Archivo);
	fclose(Archivo);
}
void leer()
{
	FILE* Archivo;
	Archivo = fopen("Libros.txt", "rb");
	if (Archivo == NULL)
	{
		Archivo = fopen("Libros.txt", "wb");
		fclose(Archivo);
	}
	fread(B, sizeof(Biblioteca), 599, Archivo);
	fflush(Archivo);
	fclose(Archivo);
}