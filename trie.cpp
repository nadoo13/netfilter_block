#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct trie_node{char c; int child_size; trie_node **child;}trie_node;

char *data[1000000];
char temp[100];
int ccc;
int space;
int cncount;
int trcount;
trie_node *connect_node(int start, int end, int depth) {
	/*
	if(ccc<10000) {
//		printf("s,e,d : %d %d %d\n",start,end,depth);
		if(space) {
			for(int i=0;i<depth;i++) printf(" ");
			space=0;
		}
		if(depth>=0) {
			if(data[start][depth]) printf("%c",data[start][depth]);
			else {
				printf("\n");
				space = 1;
			}
		}
		ccc++;
	}*/
	cncount++;
	int st=start,en=end,md;
	int node_count = 0;
	int dir_start = st;
	trie_node *save[300];
	int save_count=0;
	trie_node *result = (trie_node *)malloc(sizeof(trie_node));
	while(dir_start<=end &&(depth<0||data[start][depth]!='\0')) {
		st = dir_start;
		en = end;
		md = (st+en)/2;
		while(st<en-1) {
			if(data[dir_start][depth+1]<data[md][depth+1]) en=md;
			else st=md;
			md = (st+en)/2;
		}
		if(data[st][depth+1] == data[en][depth+1]) md = en;
		else md = st;
		save[save_count++] = connect_node(dir_start,md,depth+1);
		dir_start = md+1;
	}
	if(save_count) result->child = (trie_node **)malloc(sizeof(trie_node *)*save_count);
	else result->child = NULL;
	for(int i=0;i<save_count;i++) {
		result->child[i] = save[i];
	}
	result->child_size = save_count;
	if(depth>=0) result->c=data[start][depth];
	else result->c = '\0';
	return result;
}

int trip(char *str,trie_node *root,int depth) {
	int i;
	int size = root->child_size;
	for(i=0;i<size;i++) {
		if(root->child[i]->c == str[depth]) {
			if(root->child[i]->c == '\0') return 1;
			else return trip(str,root->child[i],depth+1);
		}
	}
	return 0;
}

int main(int argc, char **argv) {
	freopen("sorted_data.data","r",stdin);
	//freopen("sorted_trie.data","w",stdout);
	int i;
	for(i=0;i<1000000;i++) {
		scanf("%s",temp);
		int len = strlen(temp);
		data[i] = (char *)malloc(len+1);
		strcpy(data[i],temp);
	}
	trie_node *root = NULL;
	
	root = connect_node(0,999999,-1);
	printf("input host name : \n");
	if(argc>=2) strcpy(temp,argv[1]);
	if(trip(temp,root,0)) {
		printf("found!\n");
	}
	else printf("not found in trie...\n");
	//printf("%d %d\n",cncount,trcount);
	return 0;
}	
