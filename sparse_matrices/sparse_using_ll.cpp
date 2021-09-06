
#include <iostream>

struct Node{
  int col;
  int val;
  struct Node *next;
}*head = NULL, *last = NULL;

struct Node * createnode(int col, int val){
	
  struct Node * node = new Node;
	node->col = col;
	node->val = val;
	node->next = NULL;
	return node;
}

void insert_node(int col, int val){

	if(!head ){
		head = last = createnode(col, val);
	}
	else {
		struct Node * node = createnode(col, val);
		last->next = node;
		last = node;
	}
}

struct Node ** create_sparse_matrix(int row_size) {
	int col,val;
	struct Node **rows = new Node* [row_size];
  for(int i = 0 ; i < row_size ; i++) {
    printf("Enter number of columns at row: %d", i);
    std::cout<<std::endl;
    scanf("%d", &col);

    for (int j = 0; j < col; ++j) {
      printf("Enter value");
      scanf("%d", &val);
      insert_node(j,val);
    }
    rows[i] = head; 
    head = NULL; 
    last = NULL; 
  }
	return rows;
}

void print_ll(struct Node* p) {
  while(p) {
    printf("column: %d  value: %d",p->col,p ->val);
    p = p -> next;
    printf(" ");
  }
}

void printsparse(struct Node **sparse, int row) {
  for(int i = 0; i < row; i++) {
    print_ll(sparse[i]);
    printf("\n");
  }
}

int main() {
  int rows;
  printf("Please Enter the number of rows\n");
  scanf("%d",&rows);
  struct Node ** sparse =  create_sparse_matrix(rows);
  printsparse(sparse, rows);
	return 0;
}
