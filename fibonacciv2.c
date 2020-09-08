#include<stdio.h>
#include<stdlib.h>

struct Node {
   unsigned int data:4;
   struct Node* next;
   struct Node* prev;
};

void append(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  
  if (*head_ref == NULL) {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }
  
  while (last->next != NULL){
    last = last->next;
  }
  
  last->next = new_node;
  new_node->prev = last;
  
  return; 
} 

void printList(struct Node* node){
  int i=0;
  struct Node* last;
  
  while (node->next != NULL) {
    last = node;
    node = node->next;
  }
  
  while (last != NULL){
    printf("%d", last->data);
    last = last->prev;
    i++;
    if(i%45==0){ printf("\n"); }
  }
  printf("\n");  
}

int main(){
  int i, n;
  printf("fibonacci dizisinin kacinci elemani bulunsun?\n");
  scanf("%d",&n);
  
  struct Node* a = NULL;
  struct Node* b = NULL;
  struct Node* c = NULL;
  struct Node* ai = NULL;
  struct Node* bi = NULL;
  struct Node* ci = NULL;
  struct Node* tmp = NULL;
  append(&a, 1);
  append(&b, 1);
  append(&c, 0);
  
  for(i=0;i<n-2;i++){
    ai=a; bi=b; ci=c;
    
    while(ai->next != NULL || bi->next != NULL){
      if( ai->data + bi->data > 9 ){
        ci->data = ( ai->data + bi->data ) % 10;
        ai->next->data = ai->next->data + 1;
      }else{
        ci->data = ai->data + bi->data;
      }
        ai=ai->next;
        bi=bi->next;
        ci=ci->next;
    }
    if( ai->data + bi->data > 9 ){
        ci->data = ( ai->data + bi->data ) % 10;
        ai->next->data = ai->next->data + 1;
      }else{
        ci->data = ai->data + bi->data;
      }
    
    if(ci->data > 0){
      append(&a, 0);
      append(&b, 0);
      append(&c, 0);
    }
    tmp=a;
    a=b;
    b=c;
    c=tmp;
  }
  printf("Fib(%d)=\n",n);
  printList(b); 
return 0;
}
