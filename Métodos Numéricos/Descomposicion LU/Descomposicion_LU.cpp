#include <stdio.h>
#include <stdlib.h>
/* El m�todo de LU nos sirve para obtener los resultados de sistemas de ecuaciones lineales para tres incognitas.*/

main(){
	int n;
	float **A,**U, **L,sum=0,sum2=0, sum3=0;
	
	printf("Ingresa el orden de tu matriz: ");
	scanf("%d", &n);
	
	//Asignamos el espacio de nuestros apuntadores.
	A=(float**)malloc(n*sizeof(float*));
	U=(float**)malloc(n*sizeof(float*));
	L=(float**)malloc(n*sizeof(float*));
	
	for(int i=0; i<n; i++){
		A[i]=(float*)malloc(n*sizeof(float));
		U[i]=(float*)malloc(n*sizeof(float));
		L[i]=(float*)malloc(n*sizeof(float));
	}
	//Iniciamos a pedir datos de la Matriz A.
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			printf("\nIngresa el elemento A[%d][%d]: ", i,j);
			scanf("%f", &A[i][j]);
		}
	}
	
	//Iniciamos con el m�todo LU.
	for(int k=0;k<n;k++){
		U[k][k]=1;
			for(int s=0; s<k;s++){
			sum=+L[k][s]*U[s][k];
			}
			L[k][k]= A[k][k]-sum;
			
			for(int i =(k+1); i<n;i++){
				for(int s=0; s<k;s++){
					sum2=+L[i][s]*U[s][k];
				}
			L[i][k]=A[i][k]-sum2;
				
			}
			for(int j=(k+1); j<n;j++){
				for(int s=0; s<k;s++){
					sum3=+L[k][s]*U[s][j];
				}
				U[k][j]=((A[k][j]-sum3)/(L[k][k]));
			
			}
			sum=0;
			sum2=0;
			sum3=0;
	}
		L[2][2]=A[2][2]-(L[2][0]*U[0][2])-(L[2][1]*U[1][2]);
		
	//imprimir Matrices
	printf("La Matriz U es:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n;j++){
				printf("\t%.2f", U[i][j]);
			}
			printf("\n");
	}

	printf("\nLa Matriz L es:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n;j++){
				printf("\t%.2f", L[i][j]);
			}
			printf("\n");
	}
	
	
	system("PAUSE");
}


