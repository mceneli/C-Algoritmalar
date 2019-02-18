#include<stdio.h>
#include<math.h>

int main(){
	int i,j,n,value;
	printf("hangi sayiya kadar? : ");
	scanf("%d",&n);
	
	unsigned char array[n/8+1];
	for(i=0;i<=n;i++){
		if(i%2==0){
			array[i/8] |=  (1 << (i%8));
		}else{
			array[i/8] &= ~(1 << (i%8));
		}
	}
	array[2/8] &= ~(1 << (2%8));
	int nn=sqrt(n);
	
	for(i=3;i<nn;i++){
		value = (array[i/8] & (1 << (i%8))) != 0;
		if(value==0){
			for(j=i*i;j<=n;j=j+2*i){
				array[j/8] |= (1 << (j%8));
			}
		}
	}
	j=0;
	printf("2");
	for(i=3;i<=n;i=i+2){
		value = (array[i/8] & (1 << (i%8))) != 0;
		if(value==0){
			//printf(",%d",i); //ekrana yazdırmak için fakat yazdırmka yavaşlatıyor.
			j++;
		}
	}
	
	printf("\n%d tane",j);
	return 0;
}
    
