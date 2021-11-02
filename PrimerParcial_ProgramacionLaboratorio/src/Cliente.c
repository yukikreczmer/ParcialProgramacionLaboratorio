/*
 * Cliente.c
 */
#include "Cliente.h"


int eCliente_initIsEmpty(eCliente listaClientes[], int tam)
{
	int i;
	int retorno=-1;
	if(tam>0 || listaClientes!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			listaClientes[i].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}
int eCliente_BuscarIdLibre(eCliente listaClientes[], int tam)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaClientes[i].isEmpty==1)
			{
				retorno=listaClientes[i].ID;
				break;
			}
		}
	}
	return retorno;
}
int eCliente_GenerarIdAuto(eCliente list[], int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].ID=i+1;
		}
		retorno=0;
	}
	return retorno;
}
void ValidarRetorno(int retorno, char ErrorMensaje[])
{
	if(retorno==-1)
	{
		printf("%s",ErrorMensaje);
	}
}
int eCliente_HayEnAlta(eCliente list[], int len)//Retorna -1 por error en lista o tamanio. 0 si no hay clientes dados de alta. 1 si hay clientes dados de alta
{
	int retorno=-1;
	int i;
	if(list!=NULL&&len>0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}


void eCliente_ImprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int posicionLocalidad;
	posicionLocalidad=eLocalidad_findPositionById(listaLocalidades, tamLocalidades, cliente.IDlocalidad);
	printf("%03d      %-15s %-15s %-20s %-20s\n", cliente.ID, cliente.nombreEmpresa, cliente.cuit, listaLocalidades[posicionLocalidad].descripcion, cliente.direccion);
}
int eCliente_ImprimirClientes(eCliente listaClientes[], int tamCliente,  eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamCliente>0)
	{
		printf("ID:      Empresa:        CUIT:           Localidad:           Direccion:\n\n");
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				eCliente_ImprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
			}
		}
		retorno=1;
	}
	return retorno;
}


int eCliente_AltaCliente(eCliente listaClientes[], int tamCliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int i;
	char localidadCliente[60];
	int retornoLocalidad;
	if((listaClientes!=NULL && tamCliente>0)&&(listaLocalidades!=NULL && tamLocalidades>0))
	{
		for(i=0;i<tamCliente;i++)
		{
			if(listaClientes[i].isEmpty==1)
			{
				PedirString("Ingrese Nombre de la empresa: ", listaClientes[i].nombreEmpresa);
				PedirStringNumerico("\nIngrese su CUIT: ", listaClientes[i].cuit);
				PedirString("\nIngrese la direccion: ", listaClientes[i].direccion);
				PedirStringPrimeraMayusc("\nIngrese su localidad: ", localidadCliente);
				listaClientes[i].isEmpty=0;

				//Busco la localidad ingresada en la lista de localidades.
				//devuelve -1 si hay error en las listas, 0 si no hay error pero no encontro la localidad en la lista o el Id de la localidad si la encontró
				retornoLocalidad=eLocalidad_BuscarLocalidad(localidadCliente, listaLocalidades, tamLocalidades);
				if(retornoLocalidad==-1)
				{
					printf("Hubo un error en la lista de localidades\n");
				}
				//Si la encuentra devuelve el numero de ID de la localidad para guardar como FK en eCliente
				else if(retornoLocalidad>0)
				{
					listaClientes[i].IDlocalidad=retornoLocalidad;
				}
				else
				{
					//Si el retorno es 0 no hubo error en las listas pero no encontró la localidad en la lista, se procede a dar de alta y guardar el ID como FK en cliente
					retornoLocalidad=eLocalidad_AltaLocalidad(listaLocalidades, tamLocalidades, localidadCliente);
					listaClientes[i].IDlocalidad=retornoLocalidad;
					//retorna -1 por error en lista o tamaño. 0 si no hay espacio libre. ID de localidad si agrego la localidad a la lista
					if(retornoLocalidad==-1)
					{
						printf("Hubo un error en la lista de localidades\n");
					}
					else if(retornoLocalidad>0)
					{
						//si hay lugar en la lista retorna el ID de la localidad y la guardo como FK en cliente
						listaClientes[i].IDlocalidad=retornoLocalidad;
					}
					else
					{
						//si retorna 0 es porque no hay espacio para almacenar una nueva localidad en la lista
						printf("No hay espacio libre para añadir su localidad\n");
					}
				}

				printf("\nSe dio de alta a un cliente. Su numero ID es: %03d\n\n", listaClientes[i].ID);
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}
int eCliente_ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int retornoOrdenarPorID;
	int retornoPrint;
	int IdToModificar;
	int retornoPosition;
	int opcionAModificar;
	int contadorIntentos=0;
	int retornoLocalidad;
	char localidadCliente[60];

	if(listaClientes!=NULL && tamClientes>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al cliente. \n");
			}
			retornoOrdenarPorID=eCliente_OrdenarPorID(listaClientes, tamClientes);
			ValidarRetorno(retornoOrdenarPorID, "Error en la lista de clientes.\n");
			retornoPrint=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
			ValidarRetorno(retornoPrint, "Error en la lista de clientes.\n");
			IdToModificar=PedirOpcionValidandoCaracteres("Ingrese el ID del cliente a modificar", 1, tamClientes, "Error. ");
			retornoPosition=eCliente_findPositionById(listaClientes, tamClientes, IdToModificar);

			contadorIntentos++;
		}while(retornoPosition==-1|| listaClientes[retornoPosition].isEmpty==1);
		printf(	"1. Direccion\n"
				"2. Localidad\n");

		opcionAModificar=PedirOpcionValidandoCaracteres("Ingrese opcion a modificar: ", 1, 2, "Error. ");
		switch(opcionAModificar)
		{
			case 1:
				PedirString("Ingrese la direccion: ", listaClientes[retornoPosition].direccion);
				break;
			case 2:
				PedirStringPrimeraMayusc("Ingrese la localidad: ", localidadCliente);
				retornoLocalidad=eLocalidad_BuscarLocalidad(localidadCliente, listaLocalidades, tamLocalidades);
				//Busco la localidad ingresada en la lista de localidades.
				//devuelve -1 si hay error en las listas, 0 si no hay error pero no encontro la localidad o el Id de la localidad si la encontró
				if(retornoLocalidad==-1)
				{
					printf("Hubo un error en la lista de localidades\n");
				}
				else if(retornoLocalidad>0)
				//Si la encuentra devuelve el numero de ID de la localidad(mayor a 0) para guardar como FK en eCliente
				{
					listaClientes[retornoPosition].IDlocalidad=retornoLocalidad;
				}
				else
				{
					//Si el retorno es 0 no hubo error en las listas pero no encontró la localidad en la lista, se procede a dar de alta y guardar el ID como FK en cliente
					//retorna -1 por error en lista o tamaño. 0 si no hay espacio libre. ID de localidad si agrego la localidad a la lista
					retornoLocalidad=eLocalidad_AltaLocalidad(listaLocalidades, tamLocalidades, localidadCliente);
					if(retornoLocalidad==-1)
					{
						printf("Hubo un error en la lista de localidades\n");
					}
					else if(retornoLocalidad>0)
					{
						//si hay lugar en la lista guarda la localidad en la lista, retorna el ID de la localidad y la guardo como FK en cliente
						listaClientes[retornoPosition].IDlocalidad=retornoLocalidad;
					}
					else
					{
						//si retorna 0 es porque no hay espacio para almacenar una nueva localidad en la lista
						printf("No hay espacio libre para añadir su localidad\n");
					}
				}
				break;

				retornoPrint=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
				ValidarRetorno(retornoPrint, "Error en la lista de clientes.\n");
		}
		retorno=0;

	}
	return retorno;
}

int eCliente_BajaCliente(eCliente listaClientes[],int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	int retornoPrint;
	int retornoOrdenar;
	int idToBaja;
	int retornoRemove;
	int retornoFind;
	int contadorIntentos=0;

	if(listaClientes!=NULL && tamClientes>0)
	{
		do
		{
			if(contadorIntentos>0)
			{
				printf("Error no se encontro al cliente.\n");
			}
		retornoOrdenar=eCliente_OrdenarPorID(listaClientes, tamClientes);
		ValidarRetorno(retornoOrdenar, "Error en la lista de clientes.\n");
		retornoPrint=eCliente_ImprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
		ValidarRetorno(retornoPrint, "Error.\n");
		idToBaja=PedirEnteroPositivoValidandoCaracteres("Ingrese el ID del cliente a dar de baja: \n", "Error. ");
		retornoFind=eCliente_findPositionById(listaClientes, tamClientes, idToBaja);
		contadorIntentos++;
		}while(retornoFind==-1|| listaClientes[retornoFind].isEmpty==1);
		printf("¿Desea eliminar al cliente %s?\n",listaClientes[retornoFind].nombreEmpresa);
		printf("1. Confirmar\n"
				"2. Cancelar\n");
		retornoRemove=PedirOpcionValidandoCaracteres("Escriba 1 o 2.\n", 1, 2, "Escriba 1 para confirmar o 2 para cancelar\n");
		if(retornoRemove==1)
		{
			listaClientes[retornoFind].isEmpty=1;
		}

		retorno=0;
	}
	return retorno;
}

int eCliente_findPositionById(eCliente listaClientes[], int tamClientes,int ID)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamClientes>0)
	{
		for(i=0;i<tamClientes;i++)
		{
			if(listaClientes[i].ID == ID)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int eCliente_OrdenarPorID(eCliente list[], int len)
{
	int retorno=-1;
	int i;
	int j;
	eCliente aux;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].ID>list[j].ID)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
			}
		}

		retorno=0;
	}
	return retorno;

}
int eCliente_IniciarCantidadPedidos(eCliente listaClientes[], int tamClientes)
{
	int retorno=-1;
	int i;
	if(listaClientes!=NULL && tamClientes>0)
	{
		for(i=0;i<tamClientes;i++)
		{
			listaClientes[i].cantidadCompletados=0;
			listaClientes[i].cantidadPendientes=0;
		}
		retorno=1;
	}

	return retorno;
}

