#include "parser.h" 
#define MaxLinea 2048
#define MaxCampos 15 

char * strdup(char * src);
void quitaLinea(char * s);

int main(int argc,char * argv[]){
  /*declaracion de variables*/
  FILE * fp;
  int Campos = 1,i =0, j ;
  char linea[MaxLinea];
  char * token; 
  char * campos [MaxLinea];
  
  if(argc != 2){
    return 71;
  }
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    return 71;
  }
  
  while(fgets(linea, MaxLinea,fp)){
  /*printf("lee linea\n");*/
  token = strtok(linea, ",");
  while(token != NULL){
    if(Campos == 1){
      
      campos[i] = strdup(token);
      /*printf("Carga campo %s",token);*/
      token = strtok(NULL, ",");
      i++;
    }
    else{
    printf("%s: %s",campos[i],token);
    if(i != j){
      printf(";");
    }
    token = strtok(NULL, ",");
    i++;
    }
  }
  if(Campos == 1){
    Campos = 0;
    j=i; 
  }
  i = 0;
  }
  fclose(fp);
  return 0;
}

char * strdup(char * src){
  char * str;
  size_t size = strlen(src)+1;
  str = malloc(size);
  if(str){
    memcpy(str,src,size);
  }
  return str;
}

