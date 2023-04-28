#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// función: insert, agrega elementos en un árbol con puntero inicial root
void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *actual;
   struct node *padre;

   //agregamos los valores en node
   tempNode->value = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //si el árbol está vacio
   if(root == NULL) {
      root = tempNode;
   } else {
      actual = root;
      while(1) {
         padre = actual;

         //recorrido por la izquierda del árbol
         if(data < padre->value) {
            actual = padre->left;
            //insertamos en izquierda
            if(actual == NULL) {
               padre->left = tempNode;
               return;
            }
         }
         //recorrido por la derecha del árbol
         else {
            actual = padre->right;
            //insertamos en derecha
            if(actual == NULL) {
               padre->right = tempNode;
               return;
            }
         }
      }
   }
}
void Typo1(struct node* raiz) {
   if(raiz != NULL) {
      Typo1(raiz->left);
      Typo1(raiz->right);
      printf("%d ", raiz->value);
   }
}

int main() {
   int i;
   int array1[4] = {4, 2, 5, 76};
   int array2[9] = {50, 30, 24, 5, 28, 45, 98, 52, 60};
   printf("Recorrido del primer array:\n");
   for(i = 0; i < 4; i++)
      insert(array1[i]);
   printf("\nTypo2: ");
   Typo1(root);
   printf("\n\nRecorrido del segundo array:\n");
   root = NULL; // reiniciamos el árbol para insertar el segundo array
   for(i = 0; i < 9; i++)
      insert(array2[i]);
   printf("\nTypo2: ");
   Typo1(root);
   return 0;
}