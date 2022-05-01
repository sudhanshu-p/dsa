#include <stdio.h>
#include <stdlib.h>

int rightCheck (int n, int mat[][n]);
int leftCheck (int n, int mat[][n]);


int main() {
	printf("Enter the size of matrix");
	int n;
	scanf("%d", &n);
	int mat[n][n];
	printf("Enter the matrix :\n");
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			scanf("%d",& mat[i][j]);
	int ans1 = rightCheck (n, mat);
	int ans2 = leftCheck (n ,mat);
	if(ans1 == 1 || ans2 == 1)
		printf("YES\n");
	else
		printf("NO\n");
}

int rightCheck (int n, int mat[][n]) {
	for(int count = 0; count < n; count ++) {
		int tempArr[n];
		for(int i = 0, j = count; i < n ; i ++, j = (j + 1) % n)
			tempArr [i] = mat [i][j];
		for(int i = 0; i < n - 1; i++)
			if(tempArr[i] != tempArr[i + 1])
				return 0;
	}
	return 1;
}

int leftCheck (int n, int mat[][n]) {
	for(int count = 0; count < n; count ++) {
		int tempArr[n];
		for(int i = 0, j = count; i < n; i++, j--){
			if(j < 0)
				j += n;
			tempArr[i] = mat[i][j];
		}
		for(int i = 0; i < n - 1; i++)
			if(tempArr[i] != tempArr[i + 1])
				return 0;
	}
	return 1;
}

// 1 2 3 4
// 4 1 2 3
// 3 4 1 2
// 2 3 4 1

// 00, 11, 22, 33
// 01, 12, 23, 30
// 02, 13, 20, 31
// 03, 10, 21, 32

// i = 0=>3
// j = count =>count - 1

// 1 2 3 4
// 2 3 4 1
// 3 4 1 2
// 4 1 2 3

// 00, 13, 22, 31
// 01, 10, 23, 32
// 02, 11, 20, 33
// 03, 12, 21, 30