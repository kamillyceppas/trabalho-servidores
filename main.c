#include <stdio.h> 
#include <stdlib.h>

#define l 24
#define c 7  
// l = horas do dia
// c = número de servidores

int main() {
  float temperaturaMaxima, temperaturaMinima, somaTemperaturas = 0; 
  float temperaturaMaximahora,temperaturaMinimahora,temperaturaMediahora;
  int i, j;
  float temperatura[l][c] = {
      {46, 44, 45, 49, 59, 46, 43}, {49, 43, 42, 56, 59, 48, 47},
      {63, 42, 48, 58, 59, 45, 48}, {46, 48, 49, 59, 59, 49, 49},
      {48, 49, 56, 59, 59, 51, 51}, {45, 70, 57, 49, 59, 49, 59},
      {44, 41, 45, 49, 52, 46, 63}, {46, 44, 45, 49, 59, 46, 43},
      {49, 43, 42, 56, 59, 48, 47}, {63, 42, 48, 58, 59, 45, 48},
      {46, 48, 49, 59, 59, 49, 49}, {48, 49, 56, 59, 59, 51, 51},
      {45, 70, 57, 49, 59, 49, 59}, {44, 41, 45, 49, 52, 46, 63},
      {46, 44, 45, 49, 59, 46, 43}, {49, 43, 42, 56, 59, 48, 47},
      {63, 42, 48, 58, 59, 45, 48}, {46, 48, 49, 59, 59, 49, 49},
      {48, 49, 56, 59, 59, 51, 51}, {45, 70, 57, 49, 59, 49, 59},
      {44, 41, 45, 49, 52, 46, 63}, {48, 49, 56, 59, 59, 51, 51},
      {43, 44, 44, 45, 46, 46, 47}, {46, 44, 45, 49, 59, 46, 43}};
  float tempServMedia[c] = {0};

  system("clear"); // limpa a tela

printf("******** TABELA DE TEMPERATURAS *******\n\n");
// imprimindo a matriz original
printf("HORA\tSERV0\tSERV1\tSERV2\tSERV3\tSERV4\tSERV5\tSERV6\n");
for(i=0;i<l;i++){
  printf(" %dh:\t",i);
  for(j=0;j<c;j++){
    printf(" %.1f\t",temperatura[i][j]);
  }
  printf("\n");
}
printf("\n\n");
  
// Cálculo das estatísticas de temperatura por hora
printf("******** CALCULO DE TEMPERATURAS *******\n\n");

  // Para cada hora do dia, calcular a temperatura média (dentre os 6 servidores), máxima e mínima registrada
 for (i = 0; i < l; i++) {
  
     temperaturaMaximahora = temperatura[i][0];
     temperaturaMinimahora = temperatura[i][0];
     temperaturaMediahora= 0;
    for (j = 0; j < c; j++) {
      
        temperaturaMediahora+= temperatura[i][j];

      //cálculo de maior temperatura 
      if (temperatura[i][j] > temperaturaMaximahora) {
        temperaturaMaximahora = temperatura[i][j];
      }

      //cálculo de menor temperatura
      if (temperatura[i][j] < temperaturaMinimahora) {
        temperaturaMinimahora= temperatura[i][j];
      }
    }
    temperaturaMediahora /= c; // Calcula a média para a hora atual
    printf("Hora %d:\n", i);
    printf("Média: %.2f, Máxima: %.1f, Mínima: %.1f\n\n", temperaturaMediahora, temperaturaMaximahora, temperaturaMinimahora);
  }
  
    // Cálculo das temperaturas médias de cada servidor
  
  printf("******** TEMPERATURA MÉDIA DOS SERVIDORES *******\n\n");
  
  // Armazenar, em um vetor chamado tempServMedia, a temperatura média de cada servidor ao longo do dia. (isto é,cada servidor representa uma posição do vetor)
  
  for (j = 0; j < c; j++) {
    float somaServidor = 0;
    
    for (i = 0; i < l; i++) {
      somaServidor += temperatura[i][j];
    }
     tempServMedia[j] = somaServidor/l;
    
  }
  
    for (j = 0; j < c; j++) {
      printf("SERV%d = %.1f\n", j, tempServMedia[j]);
    
    }
printf("\n\n");

  // Lembre de usar o vetor tempServMedia

  // Tabela de temperaturas com marcação de asteriscos
  
  printf("********TABELA DE TEMPERATURAS C/ TEMPS ACIMA DA MEDIA*******\n\n");

  // Gerar uma nova tabela em que mostra asteristicos ao lado da temperatura:
//  Um asteristico (*) se a temperatura estiver acima de média.
//  Dois asterísticos (**) se a temperatura passou de 3 graus acima da média.

  printf("HORA\tSERV0\tSERV1\tSERV2\tSERV3\tSERV4\tSERV5\tSERV6\n");
  for(int i = 0 ; i < l ; i++){
    printf(" %dh:\t", i);
    for(int j = 0 ; j < c ; j++){
      float diferenca = temperatura[i][j]-tempServMedia[j];
      if(diferenca > 3){
        printf("%.1f**\t", temperatura[i][j]);
      }else if(diferenca > 0){
        printf("%.1f*\t", temperatura[i][j]);
      }
      else{
        printf("%.1f\t", temperatura[i][j]);
      }
      
    }
    printf("\n");
  }

  // Mostrar qual horário do dia ocorreu a maior diferença entre temperatura e temperatura média.

  
  
  int maiorDiferenca=0;
  int horaMaior=0;

   // Identifica a hora do dia com maior diferença entre temperatura e média

   for(int i = 0; i<l; i++){
     for(int j =0; j<c;j++){
       float diferenca = temperatura[i][j]-tempServMedia[j];
       
       if(diferenca>maiorDiferenca){
       maiorDiferenca=diferenca;
         horaMaior=i;
       
  } 
       
     }
    
   }
    printf("\nA hora com maior diferença entre temperatura e média ocorreu às %d:00, diferença de %.2dºC.", horaMaior, maiorDiferenca);
  return 0;
}

