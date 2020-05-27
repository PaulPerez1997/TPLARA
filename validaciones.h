#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
struct FECHA {
int DIA;
int MES;
int ANIO;
};

struct clientes{
int ID;
char APELLIDOS [50];
char NOMBRES [50];
char MAIL [50];
char DOMICILIO [100];
int CP;
FECHA Fecha_de_nacimiento;
bool ESTADO=true;
};

const char*PATH_CLIENTE= "clientes.dat";

int idAutonumerico()
{
        FILE*p;
int bytes;
p=fopen("clientes.dat","ab");
if(p==NULL){
        return -1;
}
fseek(p,0,SEEK_END);
bytes=ftell(p);
int cantidad=bytes/sizeof(clientes);
fclose(p);
return cantidad;
}

bool grabar_cliente(clientes reg){
FILE*p;
p=fopen(PATH_CLIENTE,"ab");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    return false;
}
fwrite(&reg,sizeof(clientes),1,p);
fclose(p);
cls();
return true;
}


bool ValidacionMail(char*mail){

    // tener arroba/s
if (strchr(mail,'@')==0){
    return false;
}

    // tener punto/s
if(strchr(mail,'.')==0){
    return false;
}

// solo un arroba
int i=0,cont=0;
while(mail[i]!='\0'){
    if(mail[i]=='@'){
        cont++;
    }
    i++;
}
if(cont>1){
    return false;
}

// no empezar ni terminar con @ o .
int tam=strlen(mail);
if(mail[0]=='@' || mail[tam-1]=='@' || mail[0]=='.' || mail[tam-1]=='.'){
    return false;
}

// no tener dos puntos juntos
int aux=0;
while(mail[aux]!='\0'){
    if(mail[aux]=='.'){
        if(mail[aux+1]=='.'){
            return false;
        }
    }
    aux++;
}
return true;
}

bool validar_fecha(FECHA fecha_de_nacimiento)
{
 time_t t;
t=time(NULL);
struct tm*fec;
fec= localtime(&t);

if(fecha_de_nacimiento.ANIO >= (fec->tm_year+1900)){
    return false;
}
else{
    switch (fecha_de_nacimiento.MES)
    {
    case 1:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 2:
        if(fecha_de_nacimiento.ANIO%4==0 && fecha_de_nacimiento.ANIO%100==0 && fecha_de_nacimiento.ANIO%400==0){
            if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=28){
                return true;
            }
            else{
                return false;
            }
}
else{
    if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=29){
        return true;
    }
    else{
        return false;
    }
}
        break;
    case 3:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 4:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 5:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 6:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 7:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 8:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 9:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 10:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 11:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 12:
        if(fecha_de_nacimiento.DIA>=1 && fecha_de_nacimiento.DIA<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    default:
        return false;
        break;
    }

}

return false;
}

 void listar_Cliente(clientes reg)
 {
     cout << "ID: "<<reg.ID<< endl;
     cout << "NOMBRE: "<<reg.NOMBRES<<endl;
     cout << "APELLIDO: "<<reg.APELLIDOS<<endl;
     cout << "MAIL: "<<reg.MAIL<<endl;
     cout << "DOMICILIO: "<<reg.DOMICILIO<<endl;
     cout << "CODIGO POSTAL: "<<reg.CP<<endl;
     cout << "FECHA DE NACIMIENTO: "<<reg.Fecha_de_nacimiento.DIA<<"/"<<reg.Fecha_de_nacimiento.MES<<"/"<<reg.Fecha_de_nacimiento.ANIO<<endl;
     cout << "ESTADO: ";
     if (reg.ESTADO==true)
     {
         cout << "ACTIVO"<<endl;
     }
     else{
        cout << "INACTIVO"<<endl;
     }
 }


bool ListarClientePorID(clientes reg)
{
    FILE*p;
    p = fopen(PATH_CLIENTE,"rb");
    if (p == NULL)
    {
        cout << "Error";
    }
    else{
        int aux;
    cout << "ingrese el ID a buscar"<< endl;
    cin >> aux;
    while (fread(&reg,sizeof(clientes),1,p)==1)
        {
        if (reg.ID == aux){
            listar_Cliente(reg);
            return true;
            }
        }

    }
    return false;
}

bool ListarTodosLosClientes (clientes reg)
{
    FILE*p;
    p = fopen(PATH_CLIENTE,"rb");
    if (p == NULL)
    {
        cout << "Error";
        return false;
    }
    while (fread(&reg,sizeof(clientes),1,p)==1)
        {
            cout << endl;
            listar_Cliente(reg);
            cout << "-------------------------------"<<endl;
        }
    return true;
}
int buscarIDCliente (int id)
{
    clientes reg;
    int i=0;
    FILE*p;
    p = fopen(PATH_CLIENTE,"rb");
    if (p == NULL)
    {
        cout << "Error";
        return false;
    }
    while (fread(&reg,sizeof(clientes),1,p)==1)
        {
          if (reg.ID == id)
          {
              return i;
          }
          i++;
        }

    return -1;
}

clientes leer_clientes(int pos){
    clientes reg;
    FILE*p;
    p=fopen(PATH_CLIENTE,"rb");
    if(p==NULL){
        cout<< "no se pudo abrir el archivo"<<endl;
    }
    fseek(p,pos*sizeof(clientes),SEEK_SET);
    fread(&reg,sizeof(clientes),1,p);
    fclose(p);
    return reg;
    };

   bool sobreescribir_clientes (clientes reg, int indice)
   {
     FILE*p;
bool escribio;
p=fopen(PATH_CLIENTE,"rb+");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
fseek(p,indice*sizeof(clientes),SEEK_SET);
escribio=fwrite(&reg,sizeof(clientes),1,p);
fclose(p);
return escribio;
   }

bool Modificar_Cliente(clientes reg)
{
    int aux,indice;
    cout << "ingrese el ID a Modificar"<< endl;
    cin >> aux;
    indice=buscarIDCliente(aux);
    if (indice >=0)
    {
        clientes reg=leer_clientes(indice);
        listar_Cliente(reg);
        cout<< "ingrese el nuevo domicilio: ";
        cin.ignore();
        cin.getline(reg.DOMICILIO,100);
        if(sobreescribir_clientes(reg,indice)==true)
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
    return true;
    }

    bool Eliminar_cliente (clientes reg)
    {
        int aux,indice;
    cout << "ingrese el ID para Desactivar"<< endl;
    cin >> aux;
    indice=buscarIDCliente(aux);
    if (indice >=0)
    {
        clientes reg=leer_clientes(indice);
        reg.ESTADO=false;
        if(sobreescribir_clientes(reg,indice)==true)
        {
            cout << "ID INACTIVO"<< endl;
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
    return true;
    }
#endif // VALIDACIONES_H_INCLUDED
