#include "atrapando.h"
#include<bits/stdc++.h>

using namespace std;

int x=0,i=0,j=0,mitad=0,k=0,d=0,d2=0;
int barrera_norte=0,barrera_oeste=0,barrera_sur=0,barrera_este=0,barrera_norte2=0,barrera_sur2=0;
int norte_sur[600][600],oeste_este[600][600];
void proceso();
void esquinas();
int  peligro();
int rectangulo();
int rectangulo2();
int peligro2();

void atrapando(int n)
{
  int r=0;
  mitad=n+1;
	mitad/=2;
	i=j=mitad;
	barrera_oeste=barrera_norte=mitad-8;
/**SE LE SUMA MAS 8 YA QUE ES LA DISTANCIA EXACTA DONDE KAREL
PUEDE AVANZAR Y MIENTRAS AVANZA BLOQUEAR LAS ESQUINAS*/
	barrera_sur=barrera_este=mitad+8;
	barrera_norte2=barrera_norte;
	barrera_sur2=barrera_sur;
	esquinas();
	while(r==0)
    {
        while(r==0)
            r=peligro();
        r=rectangulo();
    }
}

int peligro()
{/**ESTE VOID SIGNIFA UNA ALERTA POR SI KAREL SE ENCUENTRA AL BORDE DE SALIR DE LA CUADRICULA
  Y ASI PODERLE BLOQUEAR EL ACCESO A LA SALIDA */
    long long r=0;
    if(i==barrera_norte && norte_sur[i][j]==0)
    {
        norte_sur[i][j]=1;
        x=ponMuro(i,j,2);
        proceso();
    }
    else if(i==barrera_sur && norte_sur[i][j]==0)
    {
        norte_sur[i][j]=1;
        x=ponMuro(i,j,4);
        proceso();
    }
    else if(j==barrera_oeste && oeste_este[i][j]==0)
    {
        oeste_este[i][j]=1;
        x=ponMuro(i,j,3);
        proceso();

    }
    else if(j==barrera_este && oeste_este[i][j]==0)
    {
        oeste_este[i][j]=1;
        x=ponMuro(i,j,1);
        proceso();
    }
    else
       r=1;
    return r;
}
void proceso()
{
    /// ESTE VOID AYUDA A MOVER "I" Y A "J" PARA SABER LA UBICACION DE KAREL
    if(x==1)
        j++;
    else if(x==2)
        i--;
    else if(x==3)
        j--;
    else
        i++;
}
void esquinas()
{/**ESTE VOID NOS AYUDA A TAPAR LAS ESQUINAS DE UNA CUADRICULA DE 8 * 8
    Y ASI RECORTAR EL ESPACIO PARA ATRAPAR A KAREL, ES DECIR  EN VEZ DE QUE SEA
    UNA CUADRICULA DE N*N ESTA SE CONVIERTE EN UNA DE 8*8
    */
    x=ponMuro(mitad+8,mitad-8,3);
	proceso();
	x=ponMuro(mitad+8,mitad-8,4);
	proceso();
	x=ponMuro(mitad+8,mitad+8,1);
	proceso();
	x=ponMuro(mitad+8,mitad+8,4);
	proceso();
	x=ponMuro(mitad-8,mitad-8,3);
	proceso();
	x=ponMuro(mitad-8,mitad-8,2);
	proceso();
	x=ponMuro(mitad-8,mitad+8,1);
	proceso();
	x=ponMuro(mitad-8,mitad+8,2);
	proceso();
	x=0;
	norte_sur[barrera_norte][barrera_norte]=1;
	norte_sur[barrera_norte][barrera_sur]=1;
	norte_sur[barrera_sur][barrera_norte]=1;
	norte_sur[barrera_sur][barrera_sur]=1;
	oeste_este[barrera_norte][barrera_norte]=1;
	oeste_este[barrera_norte][barrera_sur]=1;
	oeste_este[barrera_sur][barrera_norte]=1;
	oeste_este[barrera_sur][barrera_sur]=1;
}
int rectangulo()
{
    /** CUANDO KAREL NO SE ENCUENTRE AL LIMITE DEL BORDE DE LA CUADRICULA DE 8*8
            ESTE PROCESO SE ENCARGA DE CONSTRUIR UN RECTANGULO DE 8*2 PARA REDUCIR A UN MAS SU
            LIBERTAD DE MOVIMIENTO
    */
    int r=0;
   if(norte_sur[barrera_norte][j]==0)
   {
       norte_sur[barrera_norte][j]=1;
       x=ponMuro(barrera_norte,j,2);
       proceso();
   }
   else if(norte_sur[barrera_sur][j]==0)
   {
       norte_sur[barrera_sur][j]=1;
       x=ponMuro(barrera_sur,j,4);
       proceso();
   }
   else if(norte_sur[barrera_norte][j-1]==0 && j-1>=barrera_oeste)
   {
       norte_sur[barrera_norte][j-1]=1;
       x=ponMuro(barrera_norte,j-1,2);
       proceso();
   }
   else if(norte_sur[barrera_norte][j+1]==0 && j+1<=barrera_este)
   {
       norte_sur[barrera_norte][j+1]=1;
       x=ponMuro(barrera_norte,j+1,2);
       proceso();
   }
   else if(norte_sur[barrera_sur][j-1]==0 && j-1>=barrera_oeste)
   {
       norte_sur[barrera_sur][j-1]=1;
       x=ponMuro(barrera_sur,j-1,4);
       proceso();
   }
   else if(norte_sur[barrera_sur][j+1]==0 && j+1<=barrera_este)
   {
       norte_sur[barrera_sur][j+1]=1;
       x=ponMuro(barrera_sur,j+1,4);
       proceso();
   }
   else
   {
       while(r==0)
        r=peligro();
       r=0;
       r=rectangulo2();
   }
return r;
}
int rectangulo2()
{
    /**UNA VEZ ELABORADO EL PROCESO DE RECTANGULO CON EXITO
            ESTE EMPEZARA A RECORTAR ESE RECTANGULO TOMANDO EN
            CUENTA LA DISTANCIA  ENTRE SUR Y NORTE
    */
    int r=0;
    if(norte_sur[barrera_norte][j+1]==1)
    {
        barrera_oeste=j;
        barrera_este=j+1;
    }
    else
    {
        barrera_este=j;
        barrera_oeste=j-1;
    }
    barrera_norte=barrera_norte2;
    barrera_sur=barrera_sur2;
   while(r==0)
    r=peligro2();
return 1;
}
int peligro2()
{
    /**ETSE VOID NOS PONE EN ALERTA PARA QUE KAREL NO ESCAPE DEL RECTANGULO
        DE 8*2
    */
   int r=0;
     if(j==barrera_oeste && oeste_este[i][j]==0)
    {
        oeste_este[i][j]=1;
        x=ponMuro(i,j,3);
        proceso();

    }
    else if(j==barrera_este && oeste_este[i][j]==0)
    {
        oeste_este[i][j]=1;
        x=ponMuro(i,j,1);
        proceso();
    }
    else if(oeste_este[i][j]==0)
    {
        oeste_este[i][j]=1;
        x=ponMuro(i,j,3);
        proceso();
    }
    else if(oeste_este[i][j+1]==0&& j+1<=barrera_este)
    {
        oeste_este[i][j+1]=1;
        x=ponMuro(i,j+1,1);
        proceso();
    }
    else if(i==barrera_norte2 && i==barrera_norte && barrera_sur2==i && barrera_sur==i)
    {
        x=ponMuro(i,j,3);
        return 1;
    }
    else
    {///AQUI ACORTAS LA DISTANCIA PARA Q NO SE VALLA
        if(j==barrera_oeste)
        {
            d=i-barrera_norte;
            d2=barrera_sur-i;
            if(d2<d && i!=barrera_norte)
            {
                barrera_norte=i;
                x=ponMuro(i,j,2);
                proceso();
            }
            else if(i!=barrera_sur)
            {
                barrera_sur=i;
                x=ponMuro(i,j,4);
                proceso();
            }
        }
        else
        {
            d=i-barrera_norte2;
            d2=barrera_sur2-i;
            if(d2<d &&barrera_norte2!=i)
            {
                barrera_norte2=i;
                x=ponMuro(i,j,2);
                proceso();
            }
            else if(barrera_sur2!=i)
            {
                barrera_sur2=i;
                x=ponMuro(i,j,4);
                proceso();
            }

        }
    }
    return r;
}
