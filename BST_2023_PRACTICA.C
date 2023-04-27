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
   /**
   Código
    **/
   tempNode->value = data;
   tempNode->left = NULL;
   tempNode->right = NULL;
    //si el árbol está vacio

   if(root == NULL) {
    root = tempNode;
        /**
        Código
        **/
   } else {
        /**
        Código
        **/
      actual = root;
      padre = NULL;
      while(1) {
         padre = actual;

         //recorrido por la izquierda del árbol
         if(data < padre->value) {
            actual = padre->left;
            /**
            Código
            **/
            //insertamos en izquierda
            if(actual == NULL) {
                padre->left = tempNode;
               return;
               /**
                * 
                Código
                **/
            }
         }
         //recorrido por la derecha del árbol
         else {
            actual = padre->right;
                /**
                Código
                **/
            //insertamos en derecha
            if(actual == NULL) {
                padre->right = tempNode;
               return;
                /**
                Código
                **/
            }
         }
      }
   }
}
void inorder_recorrido(struct node* raiz) {
   if(raiz != NULL) {
        inorder_recorrido(raiz->left);
        printf("%d ", raiz->value);
        inorder_recorrido(raiz->right);
        /**
        Código
        **/
   }
}
int main() {
   int i;
   int array[7] = {10, 27, 14, 300, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

    printf("\nInorder: ");
    inorder_recorrido(root);
    printf("\n");

    return 0;
}