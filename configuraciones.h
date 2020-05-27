#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED

void bkp_plato(){
cls();
FILE*disc_pl;
plato reg;
disc_pl=fopen(PATH_RESTAURANTE,"rb");
if(disc_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pl;
bkp_pl=fopen("restaurante.bkp","ab");
if(bkp_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(plato),1,disc_pl)==1){
    fwrite(&reg,sizeof(plato),1,bkp_pl);
}
cout<< "copia archivo de platos realizada"<<endl;
fclose(disc_pl);
fclose(bkp_pl);

}


void bkp_cliente(){
FILE*disc_cl;
clientes reg;
disc_cl=fopen(PATH_CLIENTE,"rb");
if(disc_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_cl;
bkp_cl=fopen("clientes.bkp","ab");
if(bkp_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(clientes),1,disc_cl)==1){
    fwrite(&reg,sizeof(clientes),1,bkp_cl);
}
cout<< "copia archivo de clientes realizada"<<endl;
fclose(disc_cl);
fclose(bkp_cl);
}

void bkp_pedido(){
FILE*disc_pe;
PEDIDOS reg;
disc_pe=fopen(PATH_PEDIDOS,"rb");
if(disc_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pe;
bkp_pe=fopen("pedidos.bkp","ab");
if(bkp_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(PEDIDOS),1,disc_pe)==1){
    fwrite(&reg,sizeof(PEDIDOS),1,bkp_pe);
}
cout<< "copia archivo de pedidos realizada"<<endl;
fclose(disc_pe);
fclose(bkp_pe);

}


void restaurar_plato(){
cls();
FILE*disc_pl;
plato reg;
disc_pl=fopen(PATH_RESTAURANTE,"wb");
if(disc_pl==NULL){
    cout<< "no se pudo abrir el archivo - Platos"<<endl;
}

FILE*bkp_pl;
bkp_pl=fopen("restaurante.bkp","rb");
if(bkp_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(plato),1,bkp_pl)==1){
    fwrite(&reg,sizeof(plato),1,disc_pl);
}
cout<< "restauracion de archivo de platos realizada"<<endl;
fclose(disc_pl);
fclose(bkp_pl);

}
void restaurar_cliente(){
FILE*disc_cl;
clientes reg;
disc_cl=fopen(PATH_CLIENTE,"wb");
if(disc_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_cl;
bkp_cl=fopen("clientes.bkp","rb");
if(bkp_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(clientes),1,bkp_cl)==1){
    fwrite(&reg,sizeof(clientes),1,disc_cl);
}
cout<< "restauracion de archivo de clientes realizada"<<endl;
fclose(disc_cl);
fclose(bkp_cl);

}
void restaurar_pedido(){
FILE*disc_pe;
PEDIDOS reg;
disc_pe=fopen(PATH_PEDIDOS,"wb");
if(disc_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pe;
bkp_pe=fopen("pedidos.bkp","rb");
if(bkp_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(PEDIDOS),1,bkp_pe)==1){
    fwrite(&reg,sizeof(PEDIDOS),1,disc_pe);
}
cout<< "restauracion de archivo de pedidos realizada"<<endl;
fclose(disc_pe);
fclose(bkp_pe);

}

#endif // CONFIGURACIONES_H_INCLUDED
