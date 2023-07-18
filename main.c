#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define MAXFILA 20
#define MAXCOL 30
#define MAXCC 10

int main(void) {
 
  char empresas[MAXFILA][MAXCOL];
  char productos[MAXFILA][MAXCOL];
  float precios[MAXFILA][MAXCOL];
  int compras[MAXFILA];
  float descuentos[MAXFILA];
  float preciosTotales[MAXFILA] = {0};
  int stockEmpresas[MAXFILA][MAXCOL];
  char nombreCliente[MAXCOL];
  char cedula[MAXCC];
  int cantidadEmpresas;
  int cantidadProductos;
  int opcion;
  int n = 0;
  
  printf("-------------BIENVENIDOS AL COTIZADOR PICHUELOSTEC-------------------\n"); 
  do {
    printf("Elija la opcion deseada: \n1.- Ingresar datos y productos \n2.- Editar producto \n3.- Eliminar producto \n4.- Imprimir cotizacion\n");
    scanf("%d", &opcion);
    switch(opcion) {
      case 1: {
        ingresarClientes(nombreCliente, cedula);

        cantidadEmpresas = leerEnteroEntre("Ingrese cantidad de empresas ofertantes", 1, MAXFILA);
        cantidadProductos = leerEnteroEntre("Ingrese cantidad de productos", 1, MAXFILA);
        ingresarCadenas("Ingrese nombre empresas", empresas, cantidadEmpresas);
        ingresarCadenas("Ingrese nombre productos", productos, cantidadProductos);
        ingresarMatrizPrecios("ingrese valor", empresas, productos, precios, cantidadProductos, cantidadEmpresas);
        imprimirMatrizPrecios(empresas, productos, precios, cantidadProductos, cantidadEmpresas);
        ingresarDescuento(descuentos, empresas, cantidadEmpresas);
        ingresarCompras(compras, productos, cantidadProductos);
        imprimirCotizacion(empresas, productos, precios, compras, descuentos, preciosTotales, cantidadEmpresas, cantidadProductos);

        printf("\nSi desea volver al menu principal ingrese 0 caso contrario ingrese cualquier otro numero entero");
        scanf("%d", &n);
        break;
      }
      
      case 2: {
      char nombreProducto[MAXCOL];
printf("Ingrese el nombre del producto a editar: ");
scanf("%s", nombreProducto);

int indiceProducto = buscarProducto(productos, cantidadProductos, nombreProducto);
if (indiceProducto != -1) {
    // El producto fue encontrado
    printf("Ingrese el nuevo nombre del producto: ");
    scanf("%s", productos[indiceProducto]);

    // Modificar el precio del producto por empresa
    for (int i = 0; i < cantidadEmpresas; i++) {
        printf("Ingrese el nuevo precio para %s de la empresa %s: ", productos[indiceProducto], empresas[i]);
        scanf("%f", &precios[indiceProducto][i]);
    }

    // Actualizar el archivo cotizaciones.txt con los cambios
    FILE* archivoCotizaciones = fopen("cotizaciones.txt", "w");
    if (archivoCotizaciones == NULL) {
        printf("No se pudo abrir el archivo de cotizaciones.\n");
    } else {
        // Escribir los datos actualizados en el archivo
        fprintf(archivoCotizaciones, "EMPRESAS:\n");
        for (int i = 0; i < cantidadEmpresas; i++) {
            fprintf(archivoCotizaciones, "%d. %s\n", i + 1, empresas[i]);
        }

        fprintf(archivoCotizaciones, "\nPRODUCTOS:\n");
        for (int i = 0; i < cantidadProductos; i++) {
            fprintf(archivoCotizaciones, "%d. %s\n", i + 1, productos[i]);
        }

        fprintf(archivoCotizaciones, "\nPRECIO POR PRODUCTO:\n");
        for (int i = 0; i < cantidadProductos; i++) {
            for (int j = 0; j < cantidadEmpresas; j++) {
                fprintf(archivoCotizaciones, "%s - %s: %.2f\n", productos[i], empresas[j], precios[i][j]);
            }
        }

        fclose(archivoCotizaciones);
        printf("Producto editado exitosamente y cambios reflejados en el archivo de cotizaciones.\n");
    }
} else {
    printf("El producto no fue encontrado en el archivo de cotizaciones.\n");
}


    printf("\nSi desea volver al menú principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
    scanf("%d", &n);
    break;
} 
      case 3: {
        eliminarProducto(productos, precios, &cantidadProductos, cantidadEmpresas, empresas);
        printf("\nSi desea volver al menu principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
        scanf("%d", &n);
        break;
      }
      
      case 4: {
        calcularPrecioProforma(precios, compras, preciosTotales, descuentos, cantidadEmpresas, cantidadProductos);
        mostrarValoresPagoEmpresa(empresas, preciosTotales, cantidadEmpresas);
        // Invoque a la función mejorEmpresaPrecio()
        int indiceMejor = mejorEmpresaPrecio(preciosTotales, cantidadEmpresas);
        // Imprima el nombre de la mejor empresa
        printf("\nLa mejor empresa es %s\n", empresas[indiceMejor]);
        // Imprima el valor a pagar
        printf("El valor a pagar es %.2f\n", preciosTotales[indiceMejor]);
        printf("\nSi desea volver al menu principal ingrese 0, caso contrario ingrese cualquier otro número entero: \n");
        scanf("%d", &n);
        break;
      }
 
      default: {
        printf("ERROR. Ingrese una opción válida.\n");
      }
    }
  } while(n == 0);
}