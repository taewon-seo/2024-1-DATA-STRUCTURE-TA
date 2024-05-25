#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-24 update
/*
*****************
* 20240524 실습 *
*****************
*/

#include <stdio.h>

#if 0
// MST
// Minimum Spanning Tree
// 최소 신장 트리
// 주어진 가중치 그래프에서 모든 정점을 포함하면서 
// 전체 가중치의 합이 최소가 되는 신장 트리를 의미

// 프림 알고리즘(Prim's Algorithm) -> vertex 기준
// 크루스칼 알고리즘(Kruskal's Algorithm) -> edge 기준

/*
[ 구현 순서 ] prim (vertex based)

1. Start vertex를 visited group에 추가
2. visited vertex에서 non-visited vertex edge 중 가장 짧은 것 선택 → v
3. v edge 출력
4. visited group 갱신 : add v
5. #vertex - 1 찾을 때 까지 2/3/4 반복
*/

#define NV 5

void perform_MST_Prim(int graph[][NV], int sVertex) { // sVertex: start vertex

	// visited array
	int visited[NV] = { 0 }; // MST를 구성하는 vertex에 포함되었는지를 표시 (1 포함, 0 불포함)

	visited[sVertex] = 1; // start vertex는 MST에 포함되었다고 표시

	// 찾아야 되는 edge 개수 : NV - 1
	for (int i = 0; i < NV - 1; i++) {

		int minDist = 99999;
		int visited_vertex = -1;
		int nonvisited_vertex = -1;

		// visited --> non-visited, 가장 작은 weight를 갖는 것을 찾는다.
		for (int j = 0; j < NV; j++) {

			// visited를 찾는다.
			if (visited[j] == 1) {

				// j로부터 갈 수 있는 non-visited 탐색
				for (int k = 0; k < NV; k++) {

					// 방문하지 않은 k 중에서, j --> k 연결
					if (visited[k] == 0) { 
						
						// j --> k edge가 있고, 지금까지 알려진 weight보다 작을 때
						if ((graph[j][k] > 0) && (graph[j][k] < minDist)) {  
							
							minDist = graph[j][k];
							visited_vertex = j;
							nonvisited_vertex = k;
						}

					}
				}
			}
		}

		// MST에 새로 추가된 edge를 출력
		printf("%d --- %d\n", visited_vertex, nonvisited_vertex);
		visited[nonvisited_vertex] = 1;
	}
}

// Kruskal: greedy 탐욕스러운

/*
[ 구현 순서 ] Kruskal (edge based)

1. 가장 짧은 edge 선택
2. cycle이 생성되지 않으면 edge 출력
3. #vertex - 1 번 반복

** cycle 생성 여부를 검사하는 방법
 - family array 사용
 - 연결될 때 마다, 동일 family 소속으로 변경
*/



void perform_MST_Kruskal(int graph[][NV]) {

	int family[NV] = { 0, 1, 2, 3, 4 };

	// NV - 1 개수 만큼의 edge를 찾는다.
	for (int cnt = 0; cnt < NV - 1; cnt++) {

		int v1 = -1;
		int v2 = -1;
		int minDist = 99999;

		// weight가 가장 작은 edge를 찾아서, MST에 포함
		for (int i = 0; i < NV; i++) { // 모든 edge들에 대해서 탐색, 두 개의 for문 진행
			for (int j = i + 1; j < NV; j++) {

				// 1. 경로가 있고, 
				// 2. 같은 family가 아니고,
				// 3. 지금까지 알려진 minDist보다 짧은 edge이면 추가한다.
				if ((graph[i][j] > 0) && (family[i] != family[j]) && (minDist > graph[i][j])) {
					minDist = graph[i][j];
					v1 = i;
					v2 = j;
				}

			}
		}

		// 가장 짧은 edge를 출력
		printf("%d --- %d\n", v1, v2);

		// 결혼식 -> v1과 v2를 같은 family에 포함 (단, v1이 항상 v2보다 작다.)
		// Cycle이 생기는 것을 찾기 위함
		int old_family = family[v2];
		int new_family = family[v1];

		for (int k = 0; k < NV; k++) {

			if (family[k] == old_family) {  // 원래 v2 가문이었으면
				family[k] = new_family;     // v1 가문으로 변경
			}
		}
	}
}

void addEdge(int graph[][NV], int v1, int v2, int weight) {
	graph[v1][v2] = weight; // weight > 0 -> 경로가 존재
	graph[v2][v1] = weight;
}

int main() {

	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1, 100); // 0 --> 1 edge, weight = 100
	addEdge(graph, 0, 2, 10);
	addEdge(graph, 1, 2, 40);
	addEdge(graph, 1, 3, 50);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 4, 10);

	// MST by Prim
	printf("perform_MST_Prim\n");
	perform_MST_Prim(graph, 0); 
	// graph에 대해서, start vertex = 0로 하여 MST를 Prim 알고리즘으로 찾는다.

	printf("\n\n");

	// MST by Kruskal
	printf("perform_MST_Kruskal\n");
	perform_MST_Kruskal(graph);

	return 0;
}

#endif


#if 1
// Dijkstra
// Shortest path finding

#if 1

#define G_SZ 7

typedef struct {
	int prev; // 직전에 거친 vertex 번호
	int dist; // start vertex --> 목적지까지 거리
	int done; // 최단거리를 찾았는가? 1: yes, 0: no
} DijkstraElement;

void initDTable(DijkstraElement dtable[], int start_vertex) {

	for (int i = 0; i < G_SZ; i++) {
		dtable[i].prev = -1;
		dtable[i].dist = 9999;
		dtable[i].done = 0;
	}

	dtable[start_vertex].done = 0;
}

// dtable에서 dist가 가장 짧고, done = 0인 vertex를 찾아서, 
// 그 번호를 반환한다.
// 만약, 모든 vertex들의 done = 1이면, -1을 반환 ---> Dijkstra 알고리즘 종료를 의미
int find_shortest_path_vertex(DijkstraElement dtable[]) {

	int vertex_idx = -1; // 최단거리가 결정되는 vertex 번호
	int vertex_dist = 9999; // 그 vertex의 최단거리

	for (int i = 0; i < G_SZ; i++) {

		if (dtable[i].done == 0 && dtable[i].dist < vertex_dist) {
			vertex_idx = i;
			vertex_dist = dtable[i].dist;
		}
	}
	return vertex_idx;
}

void showDTable(DijkstraElement dtable[]) {

	// vertex 번호 출력
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", i);
	}
	printf("\n");

	// prev
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].prev);
	}
	printf(" --- prev \n");

	// dist
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].dist);
	}
	printf(" --- dist \n");

	// done
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].done);
	}
	printf(" --- done \n");
}

// s : start vertex 번호
// e : end vertex 번호
// s --> e까지 가는 경로를 (중간 vertex 포함해서) 보여준다.
void showPath(int s, int e, DijkstraElement dtable[]) {

	int current = e;
	while (current != s) {
		printf("%d ", current);
		current = dtable[current].prev;
	}
	printf("%d ", s);
}

int main() {

	DijkstraElement dtable[G_SZ];

	int graph[G_SZ][G_SZ] = {
		//    0   1   2   3   4   5   6
			{-1, -1, -1, -1, -1, -1, -1}, // 0
			{-1, -1,  3, -1, 15, -1, -1}, // 1
			{-1,  3, -1, 30,  2, -1, -1}, // 2
			{-1, -1, 30, -1, -1,  3,  4}, // 3
			{-1, 15,  2, -1, -1,  1, -1}, // 4
			{-1, -1, -1,  3,  1, -1, 20}, // 5
			{-1, -1, -1,  4, -1, 20, -1}, // 6
	};


	// start vertex에서 직접 도달할 수 있는 vertex들에 대해서
	// dtable을 갱신한다.
	int start_vertex = 1;

	// dtable 초기화
	initDTable(dtable, start_vertex);

	dtable[start_vertex].done = 1; // <---- 경로를 다 찾았다고 표시

	for (int i = 0; i < G_SZ; i++) {
		if (graph[start_vertex][i] != -1) { // start_vertex --> i까지 직접 가는 길이 있으면,
			dtable[i].dist = graph[start_vertex][i];
			dtable[i].prev = start_vertex;
		}
	}

	// dtable에서 가장 짧은 거리를 가진 vertex이면서, done = 0인 vertex를 찾는다.
	while (1) {
		int v = find_shortest_path_vertex(dtable);
		if (v == -1) { // Dijkstra 알고리즘 완료
			break;
		}

		dtable[v].done = 1; // v까지는 최단 경로가 결정되었다.

		// v를 통해서 갱신되는 경로가 더 짧은 vertex들을 찾아서,
		// 해당 dtable을 갱신
		for (int i = 0; i < G_SZ; i++) {

			if (graph[v][i] > -1 && dtable[i].done == 0) {

				// i까지 최단경로가 결정되지 않은 것들 중에서.
				// v를 통해서 i까지 가는 길이 기존 알려진 것보다 더 짧으면

				// 이미 알려진 거리 > v를 통해서 가는 길
				if (dtable[i].dist > dtable[v].dist + graph[v][i]) {
					dtable[i].dist = dtable[v].dist + graph[v][i];
					dtable[i].prev = v; // <---- 주의
				}
			}
		}
	}

	showDTable(dtable);
	printf("===================================================\n");
	showPath(1, 6, dtable);
	return 0;
}

#endif



#endif