#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char str[1024],names[64][16];
int j,k,l;

/*
int registr(char* r1, char* r2){
    char c = 'a';
    
    c = toupper(c);
    printf("Char %c is %s\n", c, (isupper(c)) ? "big" : "small");
    c = tolower(c);
    printf("Char %c is %s\n", c, (isupper(c)) ? "big" : "small");
    return0;
}
*/

int more(char* s1, char* s2){
    int x=0; 
	int y;
    char k1[64][16];
    char k2[64][16];
   // k1 = 0;
    **k1 = s1[x];
    **k2 = s1[x];
    
    
    s1[x] = tolower(s1[x]);
    s2[x] = tolower(s2[x]);
    
    
    while(s1[x]==s2[x] && x<strlen(s1) && x<strlen(s2)){
        x++;
    }
    if (x==strlen(s1)) return 0;
    if (x==strlen(s2)) return 1;
    if (s1[x]>s2[x]) return 1;
   // return 0;
}

int main(){ 
    int i;
	while(0 == 0){
    printf("Text:");
    gets(str);
    int i;
    for(i=0;i<strlen(str);i++){
        j=0;
        while(i+j<strlen(str) && str[i+j]!=',' && str[i+j]!=' '){
            names[k][j]=str[i+j];
            j++;
        }
        k++;
        i+=j;
    }
    char tmp[16];
    for(i=0;i<k-1;i++){
    	int x;
        for(x=k-2;x>=i;x--){
            if(more(names[x],names[x+1])){ //CALL"more"
                strcpy(tmp,names[x]);
                strcpy(names[x],names[x+1]);
                strcpy(names[x+1],tmp);
            }
        }
    }
    for (i=0;i<k;i++) puts(names[i]);
}
}
