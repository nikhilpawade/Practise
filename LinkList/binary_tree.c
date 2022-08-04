#include <stdio.h>
#include <stdlib.h>
struct st {
	int data;
	struct st *left;
	struct st *right;
};

void insert(struct st **tree, int val) {
	struct st *temp = NULL;

	if (*tree == NULL) {
		temp = malloc(sizeof(struct st));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
	}

	if (val < (*tree)->data) {
		insert(&(*tree)->left, val);
	} else if (val > (*tree)->data) {
		insert(&(*tree)->right, val);
	}
}

void print_preorder(struct st *tree) {
	if (tree) {
		printf("%d\n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

void print_inorder(struct st * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(struct st * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

struct st * search(struct st **tree, int val) {
	if (!*(tree)) {
		return NULL;
	}

	if (val < (*tree)->data) {
		search(&((*tree)->left), val);
	} else if(val > (*tree)->data) {
		search(&((*tree)->right), val);
	} else if (val == (*tree)->data) {
		printf(" %d ---------->\n",(*tree)->data);
		return *tree;
	}
	return NULL;
}

void deltree(struct st * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

//Lowest Common Ancestor(lca)
struct st * find_lca(struct st *tree, int num1, int num2)
{
	if (tree == NULL) {
		return NULL;
	}
	if (num1 > tree->data && num2 > tree->data) {
		find_lca(tree->right, num1, num2);
	} else if(num1 < tree->data && num2 < tree->data) {
		find_lca(tree->left, num1, num2);
	}
	return tree;
	

}
int main() {
	struct st *root = NULL, *temp;
	insert(&root, 9);
	insert(&root, 4);
	insert(&root, 15);
	insert(&root, 6);
	insert(&root, 12);
	insert(&root, 17);
	insert(&root, 2);
	insert(&root, 77);

	printf("Pre Order Display\n");
	print_preorder(root);

	printf("In Order Display\n");
	print_inorder(root);

	printf("Post Order Display\n");
	print_postorder(root);

	temp = search(&root, 4);
	
	if (temp) {
		printf("Searched node=%d\n", temp->data);
	} else {
		printf("Data Not found in tree.\n");
	}
	
	struct st *tmp  = find_lca(root, 6, 12);
	printf("num = 6, unm2 = 12, lca = %d", tmp->data);
	/* Deleting all nodes of tree */
	deltree(root);
	return 0;
}
