#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

struct PEDIDOS{
int id;
int idcliente;
int idplato;
int cantidad;
int estado;
float precio_unitario;
float valoracion;
struct FECHA FECHA_PEDIDOS;
};

const char*PATH_PEDIDOS="pedidos.dat";

int BuscarPrecioPlato(int id){
FILE*p;
plato reg;
p=fopen(PATH_RESTAURANTE, "rb");
if(p==NULL){
    return-2;
}
while(fread(&reg,sizeof(plato),1,p)==1){
    if(reg.ID==id){
            fclose(p);
        return reg.VALOR_DE_VENTA;
    }
}
fclose(p);
return -1;
}



int CantPedidos(){
FILE*p;
int bytes;
p=fopen(PATH_PEDIDOS,"ab");
if(p==NULL){
        return -1;
}
fseek(p,0,SEEK_END);
bytes=ftell(p);
int cantidad=bytes/sizeof(PEDIDOS);
fclose(p);

return cantidad;

}

bool CargarPedidos(PEDIDOS *reg){

 cls();
    cin.ignore();
    cout<< "ID generado automaticamente: ";
    reg->id=CantPedidos()+1;
    cout<<reg->id<<endl;

    cout<< "Introduzca el ID cliente: ";
    cin>>reg->idcliente;
    if(buscarIDCliente(reg->idcliente)<0){
        cout<< "id cliente invalido"<<endl;
        return false;
    }

    cout<< "Inttroduzca el ID plato: ";
    cin>>reg->idplato;
    if(buscar_id(reg->idplato)<0){
        cout<< "id plato invalido"<<endl;
        return false;
    }

    cout<< "Introduzca la cantidad: ";
    cin>>reg->cantidad;
    if(reg->cantidad<=0){
        cout<< "cantidad invalida"<<endl;
        return false;
    }

    cout<< "El precio unitario del plato es: ";
    if(BuscarPrecioPlato(reg->idplato)<0){
        return false;
    }
    reg->precio_unitario=BuscarPrecioPlato(reg->idplato);
    cout << reg->precio_unitario<< endl;
    cout<< "Introduzca fecha: "<<endl;
    cout<< "DIA: ";
    cin>>reg->FECHA_PEDIDOS.DIA;
    cout<< "MES: ";
    cin>>reg->FECHA_PEDIDOS.MES;
    cout<< "ANIO: ";
    cin>>reg->FECHA_PEDIDOS.ANIO;
    if(validar_fecha(reg->FECHA_PEDIDOS)==false){
            cout<< "FECHA INVALIDA"<<endl;
        return false;
    }

    cout<< "valoracion: ";
    cin>>reg->valoracion;
    if(reg->valoracion<0 || reg->valoracion>10){
        return false;
    }

    cout<< "estado: en curso"<<endl;
    reg->estado=1;

    return true;
}


bool GuardarPedidos(PEDIDOS reg){
    FILE*p;
    p=fopen(PATH_PEDIDOS,"ab");
    if (p == NULL)
    {
        cout << "Error"<<endl;
        return -1;
    }
    fwrite(&reg,sizeof(PEDIDOS),1,p);
    fclose(p);
    return true;

}
int BuscarIDPedido(int id){
FILE*p;
PEDIDOS reg;
int i=0;
p=fopen(PATH_PEDIDOS,"rb");
if (p == NULL)
{
    cout << "Error ";
    return -1;
}
while (fread(&reg,sizeof(PEDIDOS),1,p)==1){
    if ( reg.id == id){
            fclose(p);
        return i;
    }
    i++;
}
cout << "No se ah podido encontrar ID"<<endl;
return -2;

}
PEDIDOS LeerPedido(int pos){
    PEDIDOS reg;
    FILE*p;
    p=fopen(PATH_PEDIDOS,"rb");
    if(p==NULL){
        cout<< "no se pudo abrir el archivo"<<endl;
    }
    fseek(p,pos*sizeof(PEDIDOS),SEEK_SET);
    fread(&reg,sizeof(PEDIDOS),1,p);
    fclose(p);
    return reg;
    };

    void ListarPedidos (PEDIDOS reg)
    {
        cout << "ID de pedido: "<< reg.id<<endl;
        cout << "ID del Cliente: "<< reg.idcliente<< endl;
        cout << "ID del plato: "<<reg.idplato<<endl;
        cout << "Cantidad: "<<reg.cantidad<<endl;
        switch (reg.estado){
        case 1:{
            cout << "Pedido En Curso !!"<<endl;
        }break;
        case 2:{
            cout << "Pedido Completado !!"<<endl;
        }break;
        default:{
            cout << "Pedido Cancelado !!"<<endl;
        }break;
                }
        cout << "Precio Unitario: "<<reg.precio_unitario<<endl;
        cout << "Valoracion: "<<reg.valoracion<<endl;
        cout << "Fecha: "<<reg.FECHA_PEDIDOS.DIA << "/"<<reg.FECHA_PEDIDOS.MES << "/"<<reg.FECHA_PEDIDOS.ANIO <<endl;
    }

bool SobreescribirPedido (PEDIDOS reg,int indice)
    {
        FILE*p;
        bool escribio;
        p=fopen(PATH_PEDIDOS,"rb+");
        if (p == NULL)
        {
            cout << "Error al abrir archivo"<<endl;
            return false;
        }
        fseek(p,indice*sizeof(PEDIDOS),SEEK_SET);
        escribio=fwrite(&reg,sizeof(PEDIDOS),1,p);
        fclose(p);
        return escribio;


    }

bool ModificarPedido(PEDIDOS reg){
    cls();
int id, opc;
    cout<< "ingrese el ID: "<<endl;
    cin>>id;
    int indice=BuscarIDPedido(id);
    if(indice>=0)
    {
        PEDIDOS reg=LeerPedido(indice);
        ListarPedidos(reg);
        switch (reg.estado)
        {
        case 1:{
            cout << "ingresar nuevo estado"<<endl;
            cout << "2 - completado" <<endl;
            cout << "3 - cancelado "<<endl;
                }break;
        case 2:{
            cout << "ingresar nuevo estado"<<endl;
            cout << "1 - En Curso" <<endl;
            cout << "3 - cancelado "<<endl;
                }break;
        case 3:{
         cout << "ingresar nuevo estado"<<endl;
            cout << "1 - En Curso" <<endl;
            cout << "2 - Completado "<<endl;
                }break;
        default:
            break;
        }
        cin>>opc;
        reg.estado=opc;
        if(SobreescribirPedido(reg,indice)==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        cout<< "id no existente."<<endl;
        return false;
    }
}

void ListarPedidosXID(){
    cls();
    int id,indice;
    cout << "ingrese el ID del Pedido a Listar"<<endl;
    cin >> id;
     indice = BuscarIDPedido(id);
     if (indice >=0)
     {
         PEDIDOS reg = LeerPedido(indice);
         ListarPedidos(reg);
    }
    else{
        cout << "No se encuentra ID "<<endl;
    }
}

void ListarPedidosDeArchivos(PEDIDOS reg)
{
    FILE*p;
    p=fopen(PATH_PEDIDOS,"rb");
    if (p == NULL)
    {
        cout << "Error al leer"<< endl;
    }
    while(fread(&reg,sizeof(PEDIDOS),1,p)==1)
    {
       cout << endl;
        ListarPedidos(reg);
        cout << "------------------------------------------"<<endl;
    }
    fclose(p);
}

#endif // PEDIDOS_H_INCLUDED
