#define MAXFILA 20
#define MAXCOL 30
#define MAXCC 10

void imprimirCotizacion(char empresas[][MAXCOL], char productos[][MAXCOL], float precios[][MAXCOL], int compras[], float descuentos[], float preciosTotales[], int cantidadEmpresas, int cantidadProductos);
void ingresarCadenas(char* mensaje, char nombres[][MAXCOL], int cantidad);
void ingresarMatrizPrecios(char* mensaje, char empresas[][MAXCOL],char productos[][MAXCOL],float valores[][MAXCOL], int productos1, int empresas1);
void ingresarStockEmpresas(char* mensaje,int stockEmpresas[][MAXCOL],char empresas[][MAXCOL],char productos[][MAXCOL],int productos1, int empresas1);
void imprimirMatrizPrecios(char empresas[][MAXCOL],char productos[][MAXCOL],float valores[][MAXCOL], int productos1, int empresas1);
void imprimirCadenas(char* mensaje, char nombres[][MAXCOL], int cantidad);
int leerEnteroPositivo(char* mensaje);
int leerEnteroEntre(char* mensaje, int minimo, int maximo);
float leerFlotantePositivo(char* mensaje);
void ingresarCompras(int compras[],char productos[][MAXCOL], int numProductos);
void ingresarDescuento(float descuentos[],char empresas[][MAXCOL],int canEmpresas);
void calcularPrecioProforma(float precios[][MAXCOL], int compras[], float preciosTotales[], float descuentos[],int cantEmpresas,int cantProductos);
int mejorEmpresaPrecio(float preciosTotales[], int cantEmpresas);
void mostrarValoresPagoEmpresa(char empresas[][MAXCOL],float preciosTotales[],int cantidadEmpresas);
void ingreseStockEmpresas(int stockEmp[MAXFILA][MAXCOL], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL] );
void imprimirStockEmpresas( int stockEmp[MAXFILA][MAXCOL], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL] );
void restarCompraDelStock(int stockEmp[MAXFILA][MAXCOL], int stockCompras[MAXFILA][MAXCOL], int compras[], int cantEmpresas,int cantProductos, char empresas[][MAXCOL],char productos[][MAXCOL]);
void ingresarClientes(char nombreCliente[], char cedula[]);
int buscarProducto(char productos[][MAXCOL], int cantidadProductos, char nombreProducto[]);
void eliminarProducto(char productos[][MAXCOL], float precios[][MAXCOL], int* cantidadProductos, int cantidadEmpresas, char empresas[][MAXCOL]);