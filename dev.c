#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char str[1024],names[64][16],check[64][16];
int j,k,l;

int more(char* k1, char* k2){
    int x=0; int i;
    
    k1[x] = tolower(k1[x]);
    k2[x] = tolower(k2[x]);
    
	while(k1[x]==k2[x] && x<strlen(k1) && x<strlen(k2)){
        x++;
    }
    if (x==strlen(k1)) return 0;
    if (x==strlen(k2)) return 1;
    if (k1[x]>k2[x]) return 1;
    return 0;
}

int main(){ 
    int i;
	while(0 == 0){
    printf("\nU enter text --> get alphabet sorted text ");
    
    printf("\nPlease enter u text ==>");
    gets(str);
    int i;
    for(i=0;i<strlen(str);i++){
        j=0;
        while(i+j<strlen(str) && str[i+j]!=',' && str[i+j]!=' '){
            names[k][j]=str[i+j];
            check[k][j]=str[i+j];
            j++;
        }
        k++;
        i+=j;
    }
    char tmp[16];
    for(i=0;i<k-1;i++){
    	int x;
        for(x=k-2;x>=i;x--){
            strcpy(check[x],names[x]);
            strcpy(check[x+1],names[x+1]);
			if (more(check[x],check[x+1])){
                strcpy(tmp,names[x]);
                strcpy(names[x],names[x+1]);
                strcpy(names[x+1],tmp);
            }
        }
    }
    for (i=0;i<k;i++) puts(names[i]);
}
}
