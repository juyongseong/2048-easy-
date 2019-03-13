#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, maxN = 0;
int map[21][21];
int visited[21][21];

void dfs(int count) {
	if (count == 5) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (map[i][j] > maxN) maxN = map[i][j];
		return;
	}
	else {
		int temp[21][21];
		memcpy(temp, map, 21 * 21 * sizeof(int));
		for (int i = 0; i < 4; ++i) {
			memset(visited, 0, 21 * 21 * sizeof(int));
			switch (i) {
			case 0:
				for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) {
					for (int ny = y; ny > 0; ny--) {
						if (map[ny][x] == 0) break;
						else {
							if (map[ny - 1][x] == 0) {
								map[ny - 1][x] = map[ny][x];
								map[ny][x] = 0;
								visited[ny - 1][x] = visited[ny][x];
								visited[ny][x] = 0;
							}
							else if (map[ny - 1][x] == map[ny][x] && visited[ny - 1][x] == 0 && visited[ny][x] == 0) {
								map[ny - 1][x] *= 2;
								map[ny][x] = 0;
								visited[ny - 1][x] = 1;
							}
						}
					}
				}
				break;
			case 1:
				for (int x = 0; x < n; ++x) for (int y = n - 1; y >= 0; --y) {
					for (int ny = y; ny < n - 1; ny++) {
						if (map[ny][x] == 0) break;
						else {
							if (map[ny + 1][x] == 0) {
								map[ny + 1][x] = map[ny][x];
								map[ny][x] = 0;
								visited[ny + 1][x] = visited[ny][x];
								visited[ny][x] = 0;
							}
							else if (map[ny + 1][x] == map[ny][x] && visited[ny + 1][x] == 0 && visited[ny][x] == 0) {
								map[ny + 1][x] *= 2;
								map[ny][x] = 0;
								visited[ny + 1][x] = 1;
							}
						}
					}
				}
				break;
			case 2:
				for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x) {
					for (int nx = x; nx > 0; nx--) {
						if (map[y][nx] == 0) break;
						else {
							if (map[y][nx - 1] == 0) {
								map[y][nx - 1] = map[y][nx];
								map[y][nx] = 0;
								visited[y][nx - 1] = visited[y][nx];
								visited[y][nx] = 0;
							}
							else if (map[y][nx - 1] == map[y][nx] && visited[y][nx - 1] == 0 && visited[y][nx] == 0) {
								map[y][nx - 1] *= 2;
								map[y][nx] = 0;
								visited[y][nx - 1] = 1;
							}
						}
					}
				}
				break;
			case 3:
				for (int y = 0; y < n; ++y) for (int x = n - 1; x >= 0; --x) {
					for (int nx = x; nx < n - 1; nx++) {
						if (map[y][nx] == 0) break;
						else {
							if (map[y][nx + 1] == 0) {
								map[y][nx + 1] = map[y][nx];
								map[y][nx] = 0;
								visited[y][nx + 1] = visited[y][nx];
								visited[y][nx] = 0;
							}
							else if (map[y][nx + 1] == map[y][nx] && visited[y][nx + 1] == 0 && visited[y][nx] == 0) {
								map[y][nx + 1] *= 2;
								map[y][nx] = 0;
								visited[y][nx + 1] = 1;
							}
						}
					}
				}
				break;
			default:
				printf("error\n");
			}
			dfs(count + 1);
			memcpy(map, temp, 21 * 21 * sizeof(int));
		}

	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &map[i][j]);

	dfs(0);
	//printf("%d", maxN);
	bool true1 = true;
	while (true1) {
		cout << "--------------------" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		printf("What's the biggest number that can come out in five movement? \n");
		printf("8 : KB_UP\n2 : KB_DOWN\n4 : KB_LEFT\n6 : KB_RIGHT\n-1 : Answer\n");
		for (int i = 1; i <= 5; ++i) {
			int num;
			printf("%dmovent (KB_code): ",i);
			scanf("%d", &num);
			switch (num) {
			case 8:
				for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) {
					for (int ny = y; ny > 0; ny--) {
						if (map[ny][x] == 0) break;
						else {
							if (map[ny - 1][x] == 0) {
								map[ny - 1][x] = map[ny][x];
								map[ny][x] = 0;
								visited[ny - 1][x] = visited[ny][x];
								visited[ny][x] = 0;
							}
							else if (map[ny - 1][x] == map[ny][x] && visited[ny - 1][x] == 0 && visited[ny][x] == 0) {
								map[ny - 1][x] *= 2;
								map[ny][x] = 0;
								visited[ny - 1][x] = 1;
							}
						}
					}
				}
				break;
			case 2:
				for (int x = 0; x < n; ++x) for (int y = n - 1; y >= 0; --y) {
					for (int ny = y; ny < n - 1; ny++) {
						if (map[ny][x] == 0) break;
						else {
							if (map[ny + 1][x] == 0) {
								map[ny + 1][x] = map[ny][x];
								map[ny][x] = 0;
								visited[ny + 1][x] = visited[ny][x];
								visited[ny][x] = 0;
							}
							else if (map[ny + 1][x] == map[ny][x] && visited[ny + 1][x] == 0 && visited[ny][x] == 0) {
								map[ny + 1][x] *= 2;
								map[ny][x] = 0;
								visited[ny + 1][x] = 1;
							}
						}
					}
				}
				break;
			case 4:
				for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x) {
					for (int nx = x; nx > 0; nx--) {
						if (map[y][nx] == 0) break;
						else {
							if (map[y][nx - 1] == 0) {
								map[y][nx - 1] = map[y][nx];
								map[y][nx] = 0;
								visited[y][nx - 1] = visited[y][nx];
								visited[y][nx] = 0;
							}
							else if (map[y][nx - 1] == map[y][nx] && visited[y][nx - 1] == 0 && visited[y][nx] == 0) {
								map[y][nx - 1] *= 2;
								map[y][nx] = 0;
								visited[y][nx - 1] = 1;
							}
						}
					}
				}
				break;
			case 6:
				for (int y = 0; y < n; ++y) for (int x = n - 1; x >= 0; --x) {
					for (int nx = x; nx < n - 1; nx++) {
						if (map[y][nx] == 0) break;
						else {
							if (map[y][nx + 1] == 0) {
								map[y][nx + 1] = map[y][nx];
								map[y][nx] = 0;
								visited[y][nx + 1] = visited[y][nx];
								visited[y][nx] = 0;
							}
							else if (map[y][nx + 1] == map[y][nx] && visited[y][nx + 1] == 0 && visited[y][nx] == 0) {
								map[y][nx + 1] *= 2;
								map[y][nx] = 0;
								visited[y][nx + 1] = 1;
							}
						}
					}
				}
				break;
			case -1:
				i = 6;
				break;
			default:
				printf("You sould input number in (8 : KB_UP, 2 : KB_DOWN, 4 : KB_LEFT, 6 : KB_RIGHT, -1 : Answer)\n");
				--i;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					printf("%d ", map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		
		printf("What's the biggest number? ");
		int NNum;
		scanf("%d", &NNum);
		if (NNum == maxN) {
			printf("Good job.\n");
			true1 = false;
		}
		else {
			printf("That's the wrong answer. Please try again...\m");
		}
	}
	system("pause");
}
