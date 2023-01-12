typedef struct lnode* List;
typedef struct Cartao card;
typedef struct Cartao{
    int nrid;
    int prio;
    //time_t date;
    char date_criac[26];
    char prazo[30];
    char msg[17];
    char pessoa[20];
    char date_conc[26];
}Cartao;
typedef struct lnode {
    card info;
    List next;
} List_node;

List list_new(void);

int list_empty(List lista);

List list_nodkill(List lista);

int list_size(List lista);

void list_searchtok(List lista, card chave, List *ant, List *atual);

List list_search(List lista, card it);

void list_searchtok_id(List lista, card chave, List *ant, List *atual);

void list_searchtok_data(List lista, card chave, List *ant, List *atual);

void list_searchtok_pessoa(List lista, card chave, List *ant, List *atual);

void list_searchtok_conc(List lista, card chave, List *ant, List *atual);

List list_search_id(List lista, card it);

void list_kill_id(List lista, card it);

void list_insert(List lista, card it);

void list_insert_conc(List lista, card it);

void list_insert_pessoa(List lista, card it);

void list_insert_data(List lista, card it);

void list_print(List lista, int flag);