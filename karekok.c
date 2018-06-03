#include <stdio.h>

int main(){
float n,ilkyaklasim=1.0,
      yaklasim=0.0;
printf("sayi gir:\n");
scanf("%f",&n);
 
while((yaklasim-ilkyaklasim>0.000000001 || ilkyaklasim-yaklasim>0.000000001)){
printf("%f\n",ilkyaklasim);
yaklasim = ilkyaklasim;
ilkyaklasim=(n/ilkyaklasim+ilkyaklasim)/2;
}
printf("%.17f :karekok\n",ilkyaklasim);
return 0;
}

 
