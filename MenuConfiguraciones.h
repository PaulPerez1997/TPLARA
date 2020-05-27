#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED
void CopiaDeSeguridad(){
    bkp_plato();
    bkp_cliente();
    bkp_pedido();
}
void Restaurar(){
restaurar_plato();
restaurar_cliente();
restaurar_pedido();
}


void MenuConfiguraciones(){
 system(" color 5F");
    int opc;
     PEDIDOS reg;
    int cantCargas=CantPedidos();
    cls();
    cout << endl;
cout << "1- Realizar Copia de Seguridad"<< endl;
cout << "2- Restaurar Copia de Seguridad"<< endl;
cout << "--------------------------------"<< endl;
cout << "0) VOLVER AL MENU PRINCIPAL"<< endl;
    cout << "Elija su Opcion" << endl;
    cin >> opc;
    switch (opc)
    {
        case 1:{
            CopiaDeSeguridad();
        }break;

        case 2:{
            Restaurar();
        }break;

        case 0:{
            cout << "Volviendo al Menu Principal"<< endl;
        }break;

        default:{
        cout << "Opcion Incorreca! Volviendo al Menu Principal"<< endl;
        }break;

    }
}



#endif // MENUCONFIGURACIONES_H_INCLUDED
