#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
using namespace std;

long binario(long num){
	if(num < 2)
		return num;
	else
		return num%2 + (10 * binario(num/2));
}                         										//Hasta aqui es la funcion recursiva para transformar de decimal a binario
	
	
	
	
	//La idea es formar una contraseña abase del siguiente polinomio dx^3+cx^2+bx^1+ax^0
	
	/*1.- Transformamos cada cifra del cumpleaños a binaro:
															0 = 0000
															1 = 0001
															.
															.
															.
															9 = 1001
															7 = 0111
	  2.- Guardamos cada numero binario en una matriz
	  3.- Los coeficientes a,b,c,d del polinomio  son sustituidos por cado uno de los digitos binarios de cada numero empezando desde la derecha
	      Asi para el numero 7 el polinomio quedaria de la siguiente manera: 0*x^3+1*x^2+1*x^1+1*x^0
	  4.- Para el valor de la variable x  se usa un numero aleatorio entre 3 y 5 que se define al inicio del main
	  5.- Para obtener cada caracter de la contraseña se resuelve el polinomio sustituyendo el valor de x 
		  Sea x=4  y el digito 7 ;polinomio = 0*4^3+1*4^2+1*4^1+1*4^0=30
	  6.- Al resultado del polinomio se le agrega un numero aleatorio tal que el resultado quede dentro del rango de 32 a 126
		  que son los varoles del codigo ascii para el abecedario y los caracteres especiles del teclado.
	  7.- se guarda cada uno de los resultados del polinomio en un arreglo de tipo caracter que posteriormente nos desplegara la contraseña
	*/
	

	
	
	
int main(int argc, char *argv[]) {
	
	int n,pot=0,sum=0,arreglo[8][4];
	long bin;
	char pwd[8];
	int x=3+rand()%(6-3);
	
	
	for(int i=0;i<8;i++)
	{
	
		for(int j=0;j<4;j++)
		{
			arreglo[i][j]=0;
			
		}
		
	}
	
	cout<<"Contraseña segura"<<endl;
	cout<<"Ingrese uno a uno los 8 digitos de su fecha de nacimiento (ej. 01012020)"<<endl<<endl;
	
	
	for(int i =0;i<8;i++)
	{
		int index=3;
		cout<<"Ingrese el digito "<<i+1<<" : ";
		cin>>n;
		while(n<0 || n>9)
		{
			cout<<"Digito incorrecto. Ingrese otro digito: ";
			cin>>n;
		}// Se le el digito del cumpleaños en decimal
		
		bin=binario(n);//Se transforma en binario
		
			
			
		while(bin!=0)
		{
			arreglo[i][index]=bin%10;
			bin/=10;
			index--;
		}// se divide cada digito del decimal para guardarlo en la matriz de derecha a izquierda
			
		
	}
	cout<<endl<<endl;
	
	
	
	
	
	for(int i=0;i<8;i++)
	{
		sum=0;
		pot=0;
		for(int j=3;j>-1;j--)
		{
			
			sum+= arreglo[i][j]*pow(x,pot);
			pot++;
			
			
			
			
		}//Se aplica el polinomio para cada digito del cumpleaños
		
		
		
		
		if(sum<32)
		{
			sum+=(32-sum)+rand()%((126-sum+1)-(32-sum));
			
		} //Se acota el resultado del polinomio para que quede dentro del rango ascii (32-126)
		
		
		
		pwd[i]=sum; //Se almacena el dato en el arreglo que contendra la contraseña.
		cout<<". ";
		
		Sleep(1000);
		
		
	}
	cout<<endl<<endl;
	cout<<"La contraseña generada es : ";
	
	for(int i=0;i<8;i++)
	{
		cout<<pwd[i];
		
		
	}//Se muestra la contraseña generada
	
	
	
	
	return 0;
}

