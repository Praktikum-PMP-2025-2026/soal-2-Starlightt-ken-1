/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamics Arrayd
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Kenny Pramanik Najla Wibowo (133224088)
 *   Nama File           : modul4.c
 *   Deskripsi           : Membuat program untuk merging 2 linked list yang awalnya terpisah satu sama lain, dengan ketentuan : 
 *                          - kedua linked list sudah terurut non menurun
 *                          - hasil juga harus non-menurun
 *                          - semua elemen dari kedua list harus tetap muncul, tetapi jika ada double maka munculkan dari salah satu saja
*/
#include <stdio.h> 
#include <stdlib.h> 

typedef struct gerbong{
    int data; 
    struct gerbong *next; 
}gerbong;

//fungsi untuk membuat node baru 
struct gerbong *newnode(int data){
    struct gerbong *node = (struct gerbong*) malloc (sizeof(struct gerbong));
    node->data = data; 
    node-> next = NULL;
    return node;
}
//membuat fungsi untuk menambahkan elemen 
void insert(struct gerbong **head, int data){
    struct gerbong *newnode = (struct gerbong*)malloc(sizeof(struct gerbong)); //membuat banyak list pertama

    struct gerbong *last = *head;

    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = newnode;
    return;
}

//membuat fungsi merged
struct gerbong *sort_merge(struct gerbong *head1, struct gerbong *head2){
    if (!head1) return head2;
    if (!head2) return head1;

    // Create a dummy node to store the result
    struct gerbong dummy;
    struct gerbong* tail = &dummy;

    // Traverse both linked lists, adding smaller elements to the result list
    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // If either of the linked lists is not fully processed, append the rest of the elements
    tail->next = head1 ? head1 : head2;

    // Return the result
    return dummy.next;
}

void cetak(struct gerbong *head){
    while(head){
        printf("%d ", head->data);
        head = head ->next;
    }
}

int main(){
    //banyak elemen per listnya
    int n; 
    int m; 

    //head masing - masing list 
    struct gerbong *head1 = NULL;
    struct gerbong *head2 = NULL;

    //inisialisasi data
    int data1;
    int data2;

    //banyak input datanya
    printf("input banyak data1");
    scanf("%d", &n);

    int count1 = 0; 
    int count2 = 0;

    //membuat linked list yang ukurannya sesuai dengan n dan juga m
    //linked list 1 
    for (int i = 0; i < n; i++) {
        scanf("%d", &data1);
        insert(&head1, data1);
    }

    //banyak input datanya
    printf("input banyak data2");
    scanf("%d", &m);

    //linked list 2
    for(int i = 0; i < m; i++){
        scanf("%d", &data2);
        insert(&head2, data2);
    }
    struct gerbong *list3 = sort_merge(head1, head2);
    cetak(list3);

}
