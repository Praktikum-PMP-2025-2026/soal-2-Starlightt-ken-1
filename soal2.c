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

//membuat fungsi untuk menambahkan elemen 
void insert(struct gerbong **head, int data){
    struct gerbong *list = (struct gerbong*)malloc(sizeof(gerbong)); //membuat banyak list pertama

    list->data = data; 
    if (*head == NULL){ //kalau misalkan listnya kosong, penambahan akan membuat elemen pertama menjadi head
        *head = list; 
    } else {
        struct gerbong *temp = *head; 
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = list;
    }
}

//membuat fungsi merged
struct gerbong *sort_merge(struct gerbong *head1, struct gerbong *head2){
    //jika semua list kosong 
    if (head1 == NULL && head2 == NULL){
        printf("MERGED EMPTY");
        return 0;
    }
    //cek jika salah satu list kosong dan list lainnya hanya berisi 1 elemen
    if (head1 == NULL){
        return head2; 
    }
    if (head2 == NULL){
        return head1; 
    }

    //proses merging berdasarkan nilai elemen yang lebih kecil 
    if (head1->data <= head2->data){
        head1->next = sort_merge(head1, head2->next);
        return head2;
    }
}

void cetak(struct gerbong *list){
    while(list != NULL){
        printf("%d", list->data);
        if (list->next != NULL){
            printf("->");
        }
        list = list->next; 
    }
    printf("\n");
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
    int count1 = 0; 
    int count2 = 0;

    //banyak input datanya
    printf("input banyak data1");
    scanf("%d", &n);

    //membuat linked list yang ukurannya sesuai dengan n dan juga m
    
    //linked list 1 
    while(count1 < n) {
        scanf("%d", &data1);
        insert(&head1, data1);
        count1++;
    }

    //banyak input datanya
    printf("input banyak data2");
    scanf("%d", &m);

    //linked list 2
    while(count2 < m){
        scanf("%d", &data2);
        insert(&head2, data2);
        count2++;
    }
    struct gerbong *list3 = sort_merge(head1, head2);
    cetak(list3);

}
