#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node item;
item *head = NULL;
item *current = NULL;

void print_list() {
	item *root = head;
	while (root != NULL) {
		printf ("%d ", root -> data);
		root = root -> next;
	}
	printf ("\n");
}

void insert_node(int data, int new_data) {
	item *new_node = NULL;
	new_node = (item *) malloc(sizeof(item));
	new_node -> data = new_data;
	new_node -> next = NULL;
	if (head == NULL) {
		head = new_node;
		current = new_node;
		return;
	}
	for (item *tmp = head; tmp != NULL; tmp = tmp->next) {
		if (tmp -> data == data) {
			new_node -> next = tmp -> next;
			tmp -> next = new_node;
			if (new_node -> next == NULL) {
				current = new_node;
			}
			return;
		}
	}
	current -> next = new_node;
	current = new_node;
}

void delete_node(int data) {
	if (head -> data == data) {
		head = head -> next;
		return;
	}
	for (item *tmp = head; tmp != NULL; tmp = tmp -> next) {
		if ((tmp -> next) != NULL && (tmp -> next) -> data == data) {
			item *to_be_deleted;
			to_be_deleted = (item *) malloc(sizeof(item));
			to_be_deleted = tmp -> next;
			tmp -> next = to_be_deleted -> next;
		}
	}
}

int main(void) {
	int ar[] = {1, 7, 9, 3, 5};
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; i ++) {
		if (i == 0) insert_node(ar[i], 0);
		else insert_node(ar[i], ar[i - 1]);
	}
	print_list();
	delete_node(7);
	delete_node(9);
	print_list();
	return 0;
}






