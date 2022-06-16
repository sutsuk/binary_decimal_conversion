#include <stdio.h>
#include <string.h>

#define MAX_FRAC 256
#define MAX_CHAR 256

int quo, rem;

double b_to_d(char *str){
  int i;
  double reti = 0.0, retf = 0.0;
  while(*str != '\0'){
    if(*str == '.'){
      for(i = 0; str[i+1] != '\0'; i++);
      while(str[i] != '.'){
        retf = (retf / 2.0) + (double)(str[i] - '0');
        i = i - 1;
      }
      retf = retf / 2.0;
      return (reti + retf);
    }else{
      reti = (reti * 2.0) + (double)(*str - '0');
    }
    str++;
  }
  return reti;
}

void div_mod(int dd, int ds){
  quo = 0;
  while(dd >= ds){
    dd = dd - ds;
    quo++;
  }
  rem = dd;
}

void loop_limit(){
  printf("Loop count has reached the upper limit.\n");
}

void mode_err(){
  printf("Selected mode is not defined");
}

double d_to_b(double inp){
  int cnt;
  int deci = (int)inp;
  double decf = inp - (double)deci;
  double reti = 0.0, retf = 0.0, dig = 1.0;
  while(1){
    if(deci < 2.0){
      reti = reti + (deci * dig);
      break;
    }
    div_mod(deci, 2);
    deci = quo;
    reti = reti + ((double)rem * dig);
    dig = dig * 10.0;
  }
  dig = 0.1;
  while(cnt < MAX_FRAC){
    if(decf == 0.0){
      break;
    }
    decf = decf * 2;
    if(decf >= 1.0){
      retf = retf + (1.0 * dig);
      decf = decf - 1.0;
    }
    dig = dig / 10;
  }
  if(decf != 0.0){
    loop_limit();
  }
  return (reti + retf);
}

int main(void){
  int i, mode;
  double inpn;
  char inps[MAX_CHAR];
  printf("Mode Select\n  1. binary to decimal\n  2. decimal to binary\n > ");
  scanf("%d", &mode);
  printf("\nInput a number\n > ");
  (void)getchar();
  if(mode == 1){
    fgets(inps, MAX_CHAR, stdin);
    for(i = 0; inps[i] != '\n'; i++);
    inps[i] = '\0';
    printf("%f\n", b_to_d(inps));
  }else if(mode == 2){
    scanf("%lf", &inpn);
    printf("%f\n", d_to_b(inpn));
  }else{
    mode_err();
  }
  return 0;
}
