#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
bool nuevo_cliente(clientes *reg){
    cls();
     system(" color 5F");
    cout << "Nuevo Cliente"<< endl;

 if ((reg->ID=idAutonumerico()+1)<0)
 {
     cout << "Error en carga automatica de ID." << endl;
     return false;
 }
 else{
    cout << "ID auto-generado" << endl;
   cout << "Su ID es: "<< reg->ID<<endl;
 }
 // NOMBRE

 cout <<"Ingrese su Nombre"<< endl;
cin.ignore();
 cin.getline(reg->NOMBRES,50);
 if (strcmp(reg->NOMBRES,"\0")==0){
        cout << "Nombre invalido" << endl;
        return false;
 }

 cout << "Ingrese su Apellido"<< endl;
 cin.getline(reg->APELLIDOS,50);
 if (strcmp(reg->APELLIDOS,"\0")==0){
        cout << "Apellido invalido" << endl;
        return false;
 }


 cout << "Ingrese su Mail"<< endl;
 cin.getline(reg->MAIL,50);
 if (ValidacionMail(reg->MAIL)==false)
 {
     cout <<"Error en la carga de mail"<< endl;
     return false;
 }

 cout << "Ingrese su Domicilio"<< endl;
 cin.getline(reg->DOMICILIO, 100);
 if (strcmp(reg->DOMICILIO,"\0")==0){
        cout << "Domicilio invalido" << endl;
        return false;
 }
 cout << "Ingrese su Codigo Postal" << endl;
 cin >> reg->CP;
 if (reg->CP<1000 || reg->CP > 9999 )
 {
     cout << "Error en el Codigo Postal "<< endl;
     return false;
 }
 cout << "ingrese fecha de nacimiento" << endl;
 cout << "DIA: ";
 cin >> reg->Fecha_de_nacimiento.DIA;
 cout << endl;
 cout << "MES: ";
 cin >> reg->Fecha_de_nacimiento.MES;
 cout << endl;
 cout << "ANIO: ";
 cin >> reg->Fecha_de_nacimiento.ANIO;
 if (validar_fecha(reg->Fecha_de_nacimiento)==false){
           cout << "Error en Fecha"<< endl;
            return false;

 }

 reg->ESTADO=true;
return true;
}

void menuClientes(){
    system(" color 5F");
    int opc;
    clientes reg;

    cls();
    cout << endl;
cout << "1- NUEVO CLIENTE"<< endl;
cout << "2- MODIFICAR CLIENTE"<< endl;
cout << "3- LISTAR CLIENTE POR ID"<< endl;
cout << "4- LISTAR TODOS LOS CLIENTES"<< endl;
cout << "5- ELIMINAR CLIENTE"<< endl;
cout << "--------------------------------"<< endl;
cout << "0) VOLVER AL MENU PRINCIPAL"<< endl;
    cout << "Elija su Opcion" << endl;
    cin >> opc;
    switch (opc)
    {
        case 1:{
           if (nuevo_cliente(&reg)==true)
           {
               if (grabar_cliente(reg)==true){
               cout << "Nuevo Cliente Cargado Correctamente" << endl;
               }
               else {
                cout <<"Error al Grabar"<< endl;
               }
           }
           else{
            cout << "Error al Cargar nuevo cliente" << endl;
           }
        }break;
        case 2:{
                Modificar_Cliente(reg);
                 cin.ignore();
                 cin.get();
        }break;
        case 3:{
            cls();
            if ( ListarClientePorID(reg)==false){
                cout <<"Error no se encontro ID"<< endl;
            }
        }break;
        case 4:{
            cls();
            if (ListarTodosLosClientes(reg)==false)
            {
                cout << "Error al Listar"<<endl;
            }

        }break;
        case 5:{
            if ( Eliminar_cliente(reg)==false)
            {
                cout << "Error al Desactivar";
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

#endif // CLIENTES_H_INCLUDED
