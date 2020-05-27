#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include "rlutil.h"
#include <ctime>
using namespace rlutil;
#include "platos.h"
#include "validaciones.h"
#include "clientes.h"
#include "pedidos.h"
#include "menuPedidos.h"
#include "configuraciones.h"
#include "MenuConfiguraciones.h"
int main()
 {
    system(" color 5F");
    int opc;
    bool salir=true;
    while (salir)
    {
    cls();
    menu();
    cout << endl;
    cout << "Elija su Opcion" << endl;
    cin >> opc;
    switch (opc)
    {
      case 1:{
        menuplatos();

      }break;
      case 2:{
        menuClientes();
      }break;
      case 3:{
           menuPedidos();
      }break;
      case 4:{
                        //
      }break;
      case 5:{
          MenuConfiguraciones();
        }break;
      case 0:{
      salir=false;
      cls();
      menu();
      cout << endl;
      cout << " Saliendo del Programa" << endl;
      }break;
      default : {
        cls();
      menu();
      cout << endl;
      cout << " Opcion Incorrecta" <<endl;
      }
    }
    cin.ignore();
    cin.get();
    }
    return 0;
    }
