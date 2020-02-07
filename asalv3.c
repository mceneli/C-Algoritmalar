#include<stdio.h>
#include<math.h>

int main(){
  int i,j,n,value,number,changed;
  printf("hangi sayiya kadar? : ");
  scanf("%d",&n);
  number=n;
  
  unsigned char array[n/8+1];
  for(i=0;i<=n;i++){
    if(i%2==0){
      array[i/8] |=  (1 << (i%8));
      --number;
    }else{
      array[i/8] &= ~(1 << (i%8));
    }
  }
  array[2/8] &= ~(1 << (2%8));
  ++number;
  int nn=sqrt(n);
  
  for(i=3;i<nn+1;i++){
    value = (array[i/8] & (1 << (i%8))) != 0;
    if(value==0){
      for(j=i*i;j<=n;j=j+2*i){
        changed = (array[j/8] & (1 << (j%8))) != 0;
        if(changed == 0){
          array[j/8] |= (1 << (j%8));
          --number;
        }
      }
    }
  }
  printf("\n%d tane",number);
  return 0;
}