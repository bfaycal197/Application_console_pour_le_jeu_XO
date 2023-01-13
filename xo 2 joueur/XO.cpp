#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char T[5][5];



void proc_remp( int *f , char a[10]){
	int i,j;
	if (*f==0){
		for(i=0;i<3;i++){
					for (j=0;j<3;j++){
						if ( T[i][j]== a[0]){
						T[i][j]='X';
							*f=1;
						}
					}
				}
	} else {
		for(i=0;i<3;i++){
					for (j=0;j<3;j++){
						if ( T[i][j]== a[0]){
							T[i][j]='O';
							*f=0;
						}
					}
				}	
	}	
}

void proc_affich(char T[5][5] ) {
	int i,j; 
		for(i=0;i<=2;i++){
		printf("\n");
		for(j=0;j<=2;j++){
			printf("|%c|",T[i][j]);
		
		}
	} 
	printf("\n");
}

void proc_test(char T[5][5] , char *af){
	int i;
	
	for(i=0;i<=2;i++){
        		if ((T[i][0]==T[i][1]) && (T[i][0]==T[i][2])){
        			*af=T[i][0];
				}
	
		}
		for(i=0;i<=2;i++){
        		if ((T[0][i]==T[1][i]) && (T[0][i]==T[2][i])){
        			*af=T[0][i];
				}
	
		}
		if ((T[0][0]==T[1][1]) && (T[0][0]==T[2][2])){
			*af=T[0][0];
		}
		if ((T[0][2]==T[1][1])&& (T[0][2]==T[2][0])){
			*af=T[0][2];
		}
	
}



int main(int argc, char *argv[]) {
	
	
	int i,o,f,f1,j;
	char m='1',af='0' ,nx[10],n[10];
	
	
	for(i=0;i<=2;i++){
		printf("\n");
		for(j=0;j<=2;j++){
			T[i][j]= m;
			printf("|%c|",T[i][j]);
			m++;
		
		}
	}
	
	printf("\n");
	o=1;f=0;
	do {
		
		if (f==0){
				
				do{
				printf(" le joueur X c'est ton tour choise une position vide ");
						gets(nx);
				
			} while (nx[0]<'1'|| nx[0]>'9'|| nx[1]!= '\0'|| nx[0]==n[0]);
				
			proc_remp(&f , nx);
			
			
		} else {
				
				do{
				printf(" le joueur O c'est ton tour choise une position vide ");
						gets(n);
						
				} while (n[0]<'1'|| n[0]>'9'|| n[1]!= '\0'|| n[0]==nx[0]);
				
				proc_remp(&f, n);
			
			}
		
		// .................................................. Affichage et Verification
	
		if (f1!=f){
		proc_affich(T);
		proc_test(T , &af);
		o++;
		}
		
		f1=f;
	
	//.................................... si la partie est termine ou pas 
	
		if (af=='X'|| af=='O') {
		 o=11;
		} 
		
	} while (o<10);
	
	//................ resultat
		if (o == 11){
		printf(" le joueur %c a gagne ",af);
	} else {
		printf(" aucun joueur n'a gagne");
	}
	
	

	return 0;
}
