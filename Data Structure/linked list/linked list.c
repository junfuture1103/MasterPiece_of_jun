#include <stdio.h>
#define NUM 20

typedef struct node {
	int data;
	struct node* link;
}node;

node* new_node() {
	struct node* temp = malloc(sizeof(struct node));
	return temp;
}

void insert_node(node** phead, node* p, node* new_node) {
	node* tmp = p->link;
	p->link = new_node;
	new_node->link = tmp;
	if (p == *phead) {
		(*phead)->link = new_node;
	}
	return;
}

void delete_node(node** phead, node* before, node* p) {
	node* tmp = p->link;
	before->link = tmp;
	free(p);
	return;

}

int main() {
	node* tmp = new_node();
	node* head = tmp;
	node* temp;
	node* old_temp = head;

	for (int i = 0; i < NUM; i++) {
		temp = new_node();
		temp->data = i;
		old_temp->link = temp;
		old_temp = temp;
	}
	temp->link = NULL;
	temp = head;

	for (int i = 0; i < NUM; i++) {
		temp = temp->link;
		printf("%d->", temp->data);
	}
	printf("NULL");

	int input = 0;
	//insert in normal
	printf("\n\nGet me insert value : ");
	if (!scanf("%d", &input)) exit(1);

	//make new node
	temp = new_node();
	temp->data = input;

	tmp = head;

	while (tmp->link != NULL) {
		tmp = tmp->link;
		if (tmp->data >= input) break;
	}

	insert_node(&head, tmp, temp);
	temp = head;

	while (temp->link != NULL) {
		temp = temp->link;
		printf("%d -> ", temp->data);
	}
	printf("NULL");

	//insert in first
	printf("\n\nGet me insert in first value : ");
	if (!scanf("%d", &input)) exit(1);

	//make new node
	temp = new_node();
	temp->data = input;

	tmp = head;
	insert_node(&head, tmp, temp);
	temp = head;

	while (temp->link != NULL) {
		temp = temp->link;
		printf("%d -> ", temp->data);
	}
	printf("NULL");

	//delete value
	printf("\n\nGet me delete value : ");
	if (!scanf("%d", &input)) exit(1);

	node* before;

	while (tmp->link != NULL) {
		before = tmp;
		tmp = tmp->link;
		if (tmp->data == input) break;
	}

	delete_node(&head, before, tmp);

	while (temp->link != NULL) {
		temp = temp->link;
		printf("%d -> ", temp->data);
	}
	printf("NULL");
	return 0;
}