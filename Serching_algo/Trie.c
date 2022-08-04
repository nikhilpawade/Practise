/*
Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought to optimal limit (key length). If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using Trie, we can search the key in O(M) time. However the penalty is on Trie storage requirements.
Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. We need to mark the last node of every key as end of word node. A Trie node field isEndOfWord is used to distinguish the node as end of word node.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_INDEX(c) ((int)c - (int)'a'		)
struct trieNode
{
	struct trieNode *childeren[ALPHABET_SIZE];
	bool isEndofWord;
};

struct trieNode *getNode(void)
{
	int i;
	struct trieNode *pNode = NULL;
	pNode = (struct trieNode *) malloc(sizeof(struct trieNode));
	if (pNode) {
		for (i = 0; i < ALPHABET_SIZE; i++) {
			pNode->childeren[i] = NULL;
		}
		pNode->isEndofWord = false;
	}
	return pNode;
}

void insert(struct trieNode *root, char * str)
{
	int i, length, index;
	length = strlen(str);
	struct trieNode *pCurr = root;

	for (i = 0; i < length; i++) {
		index = CHAR_INDEX(str[i]);
		if(!pCurr->childeren[index]) {
			pCurr->childeren[index] = getNode();
		}
		pCurr = pCurr->childeren[index];
	}
	pCurr->isEndofWord = true;
}

int search(struct trieNode *root, char *str)
{
	int i, length, index;
	length = strlen(str);
	struct trieNode *pCurr = root;

	for (i = 0; i < length; i++) {
		index = CHAR_INDEX(str[i]);
		if(!pCurr->childeren[index]) {
			return false;
		}
		pCurr = pCurr->childeren[index];
	}
	return ((pCurr != NULL) && (pCurr->isEndofWord));

}

void display(struct trieNode *root, char str[], int level)
{
	int i;
	if (root->isEndofWord == true) {
		str[level] = '\0';
		printf("%s\n", str);
	}
	for (i = 0; i < ALPHABET_SIZE; i++) {
		if( root->childeren[i]) {
			str[level] = i + 'a';
			display(root->childeren[i], str, level + 1);
		}
		
	}

}

int isEmpty(struct trieNode *root) {
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++) {
		if (root->childeren[i] != NULL) {
			return false;
		}
	}
	return true;
}
struct trieNode * deleted(struct trieNode *root, char str[], int level)
{
	if (root == NULL) {
		return NULL;
	}

	if (level == strlen(str)) {
		if (root->isEndofWord) {
			root->isEndofWord = false;
		}
		if (isEmpty(root)) {
			free(root);
			root = NULL;
		}
		return root;
	}
	int index = str[level] - 'a';
	root->childeren[index] = deleted(root->childeren[index], str, level +1);

	if (isEmpty(root) && root->isEndofWord == false) {
		free(root);
		root = NULL;
	}

	return root;
}

int main()
{
	int i;
	char str[50], str1[50];
	char keys[][9] = {"the", "aaa", "there", "answer", "any", "by", "bye", "their", "nikhil"};
  	char output[][32] = {"Not present in trie", "Present in trie"};
	struct trieNode *root = getNode();
	for (i = 0; i < ARRAY_SIZE(keys); i++) {
		insert(root, keys[i]);
	}

	// Search for different keys
	printf("%s --- %s\n", "the", output[search(root, "the")] );
	printf("%s --- %s\n", "these", output[search(root, "these")] );
	printf("%s --- %s\n", "their", output[search(root, "their")] );
	printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );

	printf("Present node in trie\n");
	display(root, str, 0);
	printf("Enter node to delete\n");
	scanf("%s", str1);
	deleted(root, str1, 0);
	printf("Present node in trie\n");
	display(root, str, 0);
	return 0;
}
