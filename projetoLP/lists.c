#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

List list_new(void){
    List aux;
    aux = (List) malloc (sizeof (List_node));
    if (aux != NULL) {
        aux->info.nrid = 0;
        aux->info.prio = 0;
        aux->next = NULL;
    }
    return aux;
}

int list_empty(List lista){
    return (lista->next == NULL ? 1 : 0);
}

List list_nodkill(List lista){
    List temp_ptr;
    while (list_empty (lista) == 0) {
        temp_ptr = lista;
        lista= lista->next;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

int list_size(List lista){
    int count=0;
    while(lista->next!=NULL){
        count++;
        lista = lista->next;
    }
    return count;
}

void list_searchtok(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && (*atual)->info.prio >= chave.prio){
        *ant = *atual;
        if (((*atual)->next) == NULL) {
            break;
        }
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.prio != chave.prio)
        *atual = NULL;
}

List list_search(List lista, card it){
    List ant;
    List atual;
    list_searchtok (lista, it, &ant, &atual);
    return (atual);
}

void list_searchtok_id(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && (*atual)->info.nrid != chave.nrid){
        *ant = *atual;
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.nrid != chave.nrid)
        *atual = NULL;
}

void list_searchtok_data(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && strcmp((*atual)->info.date_criac, chave.date_criac) < 0){
        *ant = *atual;
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.date_criac != chave.date_criac)
        *atual = NULL;
}

List list_search_id(List lista, card it){
    List ant;
    List atual;
    list_searchtok_id(lista, it, &ant, &atual);
    return (atual);
}
void list_searchtok_conc(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && strcmp((*atual)->info.date_conc, chave.date_conc) < 0){
        *ant = *atual;
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.date_conc != chave.date_conc)
        *atual = NULL;
}

void list_insert_conc(List lista, card it){
    List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok_conc(lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}
void list_searchtok_pessoa(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && strcmp((*atual)->info.pessoa, chave.pessoa) <= 0){
        *ant = *atual;
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.pessoa != chave.pessoa)
        *atual = NULL;
}
void list_insert_pessoa(List lista, card it){
    List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok_pessoa(lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}

void list_kill_id(List lista, card it){
    List ant1;
    List atual1;
    list_searchtok_id (lista, it, &ant1, &atual1);
    if (atual1 != NULL) {
        ant1->next = atual1->next;
        free (atual1);
    }
}

void list_insert(List lista, card it){
    List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok (lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}

void list_insert_data(List lista, card it){
    List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok_data(lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}

void list_print(List lista, int flag){
    List l = lista->next; /* Salta o header */
    while (l){
        printf("id: %d ", l->info.nrid);
        printf("prio: %d ", l->info.prio);
        printf("msg: %s\n", l->info.msg);
        printf("criação: %s\n", l->info.date_criac);
        if (flag==2 || flag==3) {
            printf("nome: %s\n", l->info.pessoa);
            printf("prazo: %s\n", l->info.prazo);
        }
        if (flag==3) {
            printf("conclusao: %s\n", l->info.date_conc);
        }
        printf("----------------------------------\n");
        l = l->next;
    }
}

