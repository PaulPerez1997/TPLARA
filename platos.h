#ifndef FUNCIONESLARA_H_INCLUDED
#define FUNCIONESLARA_H_INCLUDED


struct plato{
int   ID;
char  NOMBRE [50];
float COSTO_DE_PREPARACION;
float VALOR_DE_VENTA;
int   TIEMPO_DE_PREPARACION;
int   ID_RESTAURANTE; 
int   COMISION_RESTAURANTE; 
int   ID_CATEGORIA;
bool  ESTADO;
};

int buscarID (int id, plato *pcarga)
{
    plato reg;
    FILE *p;
    p = fopen("restauranteLara.dat","rb");
    if (p == NULL)
    {
        cout << "No se Pudo abrir el archivo" << endl;
        return -1;
    }

    while (fread(&reg, sizeof(plato),1,p) == 1)
    {
        if (reg.ID == id)
        {
        *pcarga = reg;
        fclose(p);
        return 1;

        }
    }
    cout << "No se Encontro el ID" << endl;
    return 0;
}

void listar_por_ID(plato reg)
{
    FILE *p;
    p = fopen("restauranteLARA.dat","rb");
    if (p == NULL)
    {
        cout << "No se pudo abrir el archivo";

    }
    fread(&reg, sizeof(plato),1,p);
    fclose(p);
cout <<"ID: "    << reg.ID                 <<endl;
cout <<"Nombre: "<< reg.NOMBRE             << endl;
cout <<"Costo de Preparacion: " << reg.COSTO_DE_PREPARACION << endl;
cout <<"Valor de Venta: "<< reg.VALOR_DE_VENTA<<endl;
cout <<"Tiempo de Preparacion: " << reg.TIEMPO_DE_PREPARACION<< endl;
cout <<"ID de Restaurante: "<< reg.ID_RESTAURANTE << endl;
cout <<"Comision del Restaurante: "<< reg.COMISION_RESTAURANTE << endl;
cout <<"ID Categoria: "<< reg.ID_CATEGORIA<< endl;
cout <<"Estado: ";
 if (reg.ESTADO == 1){
        cout <<"activo"<< endl;
            }
    else{
    cout << "inactivo" << endl;
        }

}



bool cargar_plato (plato *reg)
{
    cls();
    cout << "Ingrese el ID: ";
    cin >> reg->ID;
    cout << endl;
    if (reg->ID < 0)
    {
        cout << "Error de ingreso de ID" << endl;
    cin.ignore();
    cin.get();
        return false;
    }
    cin.ignore();
    cout << "Ingrese el Nombre: ";
    cin.getline(reg->NOMBRE,50);
    cout << endl;
    cout << "Ingrese el Costo de Preparacion: " ;
    cin >> reg->COSTO_DE_PREPARACION;
    if (reg->COSTO_DE_PREPARACION < 1)
    {
        cout << "Error de ingreso de costo de preparacion";
        cin.ignore();
    cin.get();
        return false;
    }
    cout << endl;
    cout << "Ingrese el valor de venta: " ;
    cin >> reg->VALOR_DE_VENTA;
    if (reg->VALOR_DE_VENTA < reg->COSTO_DE_PREPARACION)
    {
        cout << "Error de ingreso de valor de venta";
        cin.ignore();
    cin.get();
       return false;
    }
    if (reg->VALOR_DE_VENTA < 0 )
    {

        cout << "Error de ingreso de valor de venta";
        cin.ignore();
    cin.get();
        return false;
    }

    cout << endl;
    cout << "Ingrese el tiempo de preparacion: ";
    cin >> reg->TIEMPO_DE_PREPARACION;
    if (reg->TIEMPO_DE_PREPARACION < 0)
    {
        cout << "Error de tiempo de preparacion";
        cin.ignore();
    cin.get();
        return false;
    }
    cout << endl;
    cout << "Ingrese el ID del Restaurante: ";
    cin >> reg->ID_RESTAURANTE;
    if (reg->ID_RESTAURANTE < 0)
    {
        cout << "Error de ingreso del ID de Restaurante";
        cin.ignore();
    cin.get();
        return false;
    }
    cout << endl;
    cout << "Ingreso de comision de restaurante: ";
    cin >> reg->COMISION_RESTAURANTE;
    if (reg->COMISION_RESTAURANTE < 0 )
    {
        cout << "Error de comision de Restaurante"<< endl ;
        cin.ignore();
    cin.get();
        return false;
    }
    if(reg->COMISION_RESTAURANTE > 100)
    {
        cout << "Error de comision de Restaurante"<< endl ;
        cin.ignore();
    cin.get();
        return false;
    }
    cout << endl;
    cout << "Ingrese el ID de la Categoria: ";
    cin >> reg->ID_CATEGORIA;
    if (reg->ID_CATEGORIA < 0)
    {
        cout << "Error del ingreso del ID de la categoria" << endl;
       cin.ignore();
    cin.get();
        return false;
    }
    reg->ESTADO = 1;
    cin.ignore();
    cin.get();
    return true;
}

bool guardar_en_archivo(plato carga)
{
    FILE *p;
    p = fopen("restauranteLara.dat","ab");
    if (p = NULL)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }
    fwrite(&carga, sizeof(plato), 1,p);
    fclose(p);
    return true;
}




void menu ()
{
    cout << endl;
    cout << " Menu Principal " << endl;
    cout << endl;
    cout << " ----------------------" << endl;
    cout << endl;
    cout << " 1) Platos" << endl;
    cout << " 2) clientes" << endl;
    cout << " 3) Pedidos" << endl;
    cout << " 4) Reportes" << endl;
    cout << " 5) Configuracion" << endl;
    cout << endl;
    cout << " ----------------------" << endl;
    cout << endl;
    cout << " 0) SALIR DEL PROGRAMA" << endl;

}

void menuplatos()
{
    int a;
    plato carga;
    cls();
    int opc;
    cout << endl;
    cout << " Menu Platos " << endl;
    cout << endl;
    cout << " -----------------------------" << endl;
    cout << endl;
    cout << " 1- Nuevo Plato" << endl;
    cout << " 2- Modificar Plato" << endl;
    cout << " 3- Listar Plato por ID" << endl;
    cout << " 4- Platos por Restaurant" << endl;
    cout << " 5- Listar todos los Platos" << endl;
    cout << " 6- Eliminar plato" << endl;;
    cout << endl;
    cout << " -----------------------------" << endl;
    cout << endl;
    cout << " 0- VOLVER AL MENU PRINCIPAL" << endl;
    cout << endl;
    cout << "Elija una opcion" << endl;
    cin >> opc;
    switch (opc)
    {
      case 1:{
      if (cargar_plato(&carga) == true)
       {
            if (guardar_en_archivo(carga)== false)
            {
                cout << "Error al Guardar !"<< endl;

            }
             cout << "Plato cargado Exitosamente !"<< endl;
       }

      }break;
      case 2:{}break;
      case 3:{
          system("cls");
          cout << "Ingrese ID a listar" << endl;
          cin >> a;

          if (buscarID(a,&carga) == 1)
          {
              cout << "SSe llistara"<< endl;
          system("pause");
              listar_por_ID(carga);
              cin.ignore();
          cin.get();
          }
      }break;
      case 4:{}break;
      case 5:{}break;
      case 0:{cls();}break;
      default : {
        cls();
      cout << endl;
      cout << " Opcion Incorrecta" <<endl;
      }break;
    cin.ignore();
        cin.get();
    }
    }


#endif // FUNCIONESLARA_H_INCLUDED
