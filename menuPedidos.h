#ifndef MENUPEDIDOS_H_INCLUDED
#define MENUPEDIDOS_H_INCLUDED


void menuPedidos(){
    system(" color 5F");
    int opc;
     PEDIDOS reg;
    int cantCargas=CantPedidos();
    cls();
    cout << endl;
cout << "1- NUEVO PEDIDO"<< endl;
cout << "2- MODIFICAR PEDIDO"<< endl;
cout << "3- LISTAR PEDIDO POR ID"<< endl;
cout << "4- LISTAR TODOS LOS PEDIDOS"<< endl;
cout << "--------------------------------"<< endl;
cout << "0) VOLVER AL MENU PRINCIPAL"<< endl;
    cout << "Elija su Opcion" << endl;
    cin >> opc;
    switch (opc)
    {
        case 1:{
            if(CargarPedidos(&reg)==true)
            {
                if (GuardarPedidos(reg)==true){
                    cout << "Cargado y Guardado con exito"<<endl;
                }
                else{
                    cout << "Error al Guardar"<<endl;
                }
            }
            else{
                cout << "Error No se pudo Cargar"<<endl;

            }
        }break;
        case 2:{
       if (ModificarPedido(reg)==false){
        cout << "Error al modificar"<<endl;
       }
       else{
        cout << "Modificado Correctamente"<<endl;
       }
        }break;
        case 3:{
               if(cantCargas>0)
            {
                ListarPedidosXID();
            }
            else
            {
                cout<< "no hay pedidos cargados"<<endl;
            }
        }break;
        case 4:{
            if(cantCargas>0)
            {
                ListarPedidosDeArchivos(reg);
            }
            else
            {
                cout<< "no hay pedidos cargados"<<endl;
            }
        }break;
        case 0:{
            cout << "Volviendo al Menu Principal"<< endl;
        }break;
        default:{
        cout << "Opcion Incorreca! Volviendo al Menu Principal"<< endl;
        }break;

    }
}


#endif // MENUPEDIDOS_H_INCLUDED
