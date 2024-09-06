#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour échanger les positions de deux nœuds
void permuterNoeuds(Node** head, Node* t, Node* v) {
    if (t == v) return;

    // Trouver les nœuds précédents de t et v
    Node* prevT = NULL, *prevV = NULL, *curr = *head;
    while (curr != NULL && (prevT == NULL || prevV == NULL)) {
        if (curr->next == t) prevT = curr;
        if (curr->next == v) prevV = curr;
        curr = curr->next;
    }

    // Si t ou v n'est pas dans la liste, retour
    if (t == NULL || v == NULL) return;

    // Si t ou v est la tête de la liste
    if (prevT != NULL) prevT->next = v;
    else *head = v;

    if (prevV != NULL) prevV->next = t;
    else *head = t;

    // Échanger les nœuds
    Node* temp = t->next;
    t->next = v->next;
    v->next = temp;
}

// Fonction pour ajouter un nœud à la liste
void ajouterNoeud(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Ajouter des nœuds à la liste
    ajouterNoeud(&head, 5);
    ajouterNoeud(&head, 4);
    ajouterNoeud(&head, 3);
    ajouterNoeud(&head, 2);
    ajouterNoeud(&head, 1);

    printf("Liste originale : ");
    afficherListe(head);

    // Échanger les nœuds
    permuterNoeuds(&head, head->next, head->next->next->next);

    printf("Liste après permutation : ");
    afficherListe(head);

    return 0;
}
