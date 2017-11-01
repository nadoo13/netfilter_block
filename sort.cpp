#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

char arr[10000];
(char *)dest[1000000];

bool compare(char *a, char *b) {
	if(strcmp(a,b)>0) return true;
	else return false;
}

int main() {
	freopen("input.csv","r",stdin);
	freopen("sorted_data.data","w",stdout);
	int m,n,i,j;
	int max = 0;
	for(i=0;i<1000000;i++) {
		scanf("%d,%s",&n,arr);
		int len = strlen(arr)+1;
		dest[i] = (char *)malloc(len);
		strncpy(dest[i],arr,len-1);
	}
	sort(arr,arr+1000000,compare);
	for(i=0;i<1000000;i++) {
		printf("%s\n",dest[i]);
		free(dest[i]);
	}
	return 0;
}
