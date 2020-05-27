#ifndef FECHA_ACTUAL_H_INCLUDED
#define FECHA_ACTUAL_H_INCLUDED
struct fecha
{
    int dia,mes,anio;
};

fecha hoy()
{
    time_t t;
    t = time(NULL);
    struct tm *f;
    f= localtime(&t);
    fecha aux;
    aux.dia=f->tm_mday;
    aux.mes=f->tm_mon+1;
    aux.anio=f->tm_year+1900;
    return aux;
}


#endif // FECHA_ACTUAL_H_INCLUDED
