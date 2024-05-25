#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-24 update
/*
*****************
* 20240524 �ǽ� *
*****************
*/

#include <stdio.h>

#if 0
// MST
// Minimum Spanning Tree
// �ּ� ���� Ʈ��
// �־��� ����ġ �׷������� ��� ������ �����ϸ鼭 
// ��ü ����ġ�� ���� �ּҰ� �Ǵ� ���� Ʈ���� �ǹ�

// ���� �˰���(Prim's Algorithm) -> vertex ����
// ũ�罺Į �˰���(Kruskal's Algorithm) -> edge ����

/*
[ ���� ���� ] prim (vertex based)

1. Start vertex�� visited group�� �߰�
2. visited vertex���� non-visited vertex edge �� ���� ª�� �� ���� �� v
3. v edge ���
4. visited group ���� : add v
5. #vertex - 1 ã�� �� ���� 2/3/4 �ݺ�
*/

#define NV 5

void perform_MST_Prim(int graph[][NV], int sVertex) { // sVertex: start vertex

	// visited array
	int visited[NV] = { 0 }; // MST�� �����ϴ� vertex�� ���ԵǾ������� ǥ�� (1 ����, 0 ������)

	visited[sVertex] = 1; // start vertex�� MST�� ���ԵǾ��ٰ� ǥ��

	// ã�ƾ� �Ǵ� edge ���� : NV - 1
	for (int i = 0; i < NV - 1; i++) {

		int minDist = 99999;
		int visited_vertex = -1;
		int nonvisited_vertex = -1;

		// visited --> non-visited, ���� ���� weight�� ���� ���� ã�´�.
		for (int j = 0; j < NV; j++) {

			// visited�� ã�´�.
			if (visited[j] == 1) {

				// j�κ��� �� �� �ִ� non-visited Ž��
				for (int k = 0; k < NV; k++) {

					// �湮���� ���� k �߿���, j --> k ����
					if (visited[k] == 0) { 
						
						// j --> k edge�� �ְ�, ���ݱ��� �˷��� weight���� ���� ��
						if ((graph[j][k] > 0) && (graph[j][k] < minDist)) {  
							
							minDist = graph[j][k];
							visited_vertex = j;
							nonvisited_vertex = k;
						}

					}
				}
			}
		}

		// MST�� ���� �߰��� edge�� ���
		printf("%d --- %d\n", visited_vertex, nonvisited_vertex);
		visited[nonvisited_vertex] = 1;
	}
}

// Kruskal: greedy Ž�彺����

/*
[ ���� ���� ] Kruskal (edge based)

1. ���� ª�� edge ����
2. cycle�� �������� ������ edge ���
3. #vertex - 1 �� �ݺ�

** cycle ���� ���θ� �˻��ϴ� ���
 - family array ���
 - ����� �� ����, ���� family �Ҽ����� ����
*/



void perform_MST_Kruskal(int graph[][NV]) {

	int family[NV] = { 0, 1, 2, 3, 4 };

	// NV - 1 ���� ��ŭ�� edge�� ã�´�.
	for (int cnt = 0; cnt < NV - 1; cnt++) {

		int v1 = -1;
		int v2 = -1;
		int minDist = 99999;

		// weight�� ���� ���� edge�� ã�Ƽ�, MST�� ����
		for (int i = 0; i < NV; i++) { // ��� edge�鿡 ���ؼ� Ž��, �� ���� for�� ����
			for (int j = i + 1; j < NV; j++) {

				// 1. ��ΰ� �ְ�, 
				// 2. ���� family�� �ƴϰ�,
				// 3. ���ݱ��� �˷��� minDist���� ª�� edge�̸� �߰��Ѵ�.
				if ((graph[i][j] > 0) && (family[i] != family[j]) && (minDist > graph[i][j])) {
					minDist = graph[i][j];
					v1 = i;
					v2 = j;
				}

			}
		}

		// ���� ª�� edge�� ���
		printf("%d --- %d\n", v1, v2);

		// ��ȥ�� -> v1�� v2�� ���� family�� ���� (��, v1�� �׻� v2���� �۴�.)
		// Cycle�� ����� ���� ã�� ����
		int old_family = family[v2];
		int new_family = family[v1];

		for (int k = 0; k < NV; k++) {

			if (family[k] == old_family) {  // ���� v2 �����̾�����
				family[k] = new_family;     // v1 �������� ����
			}
		}
	}
}

void addEdge(int graph[][NV], int v1, int v2, int weight) {
	graph[v1][v2] = weight; // weight > 0 -> ��ΰ� ����
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
	// graph�� ���ؼ�, start vertex = 0�� �Ͽ� MST�� Prim �˰������� ã�´�.

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
	int prev; // ������ ��ģ vertex ��ȣ
	int dist; // start vertex --> ���������� �Ÿ�
	int done; // �ִܰŸ��� ã�Ҵ°�? 1: yes, 0: no
} DijkstraElement;

void initDTable(DijkstraElement dtable[], int start_vertex) {

	for (int i = 0; i < G_SZ; i++) {
		dtable[i].prev = -1;
		dtable[i].dist = 9999;
		dtable[i].done = 0;
	}

	dtable[start_vertex].done = 0;
}

// dtable���� dist�� ���� ª��, done = 0�� vertex�� ã�Ƽ�, 
// �� ��ȣ�� ��ȯ�Ѵ�.
// ����, ��� vertex���� done = 1�̸�, -1�� ��ȯ ---> Dijkstra �˰��� ���Ḧ �ǹ�
int find_shortest_path_vertex(DijkstraElement dtable[]) {

	int vertex_idx = -1; // �ִܰŸ��� �����Ǵ� vertex ��ȣ
	int vertex_dist = 9999; // �� vertex�� �ִܰŸ�

	for (int i = 0; i < G_SZ; i++) {

		if (dtable[i].done == 0 && dtable[i].dist < vertex_dist) {
			vertex_idx = i;
			vertex_dist = dtable[i].dist;
		}
	}
	return vertex_idx;
}

void showDTable(DijkstraElement dtable[]) {

	// vertex ��ȣ ���
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

// s : start vertex ��ȣ
// e : end vertex ��ȣ
// s --> e���� ���� ��θ� (�߰� vertex �����ؼ�) �����ش�.
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


	// start vertex���� ���� ������ �� �ִ� vertex�鿡 ���ؼ�
	// dtable�� �����Ѵ�.
	int start_vertex = 1;

	// dtable �ʱ�ȭ
	initDTable(dtable, start_vertex);

	dtable[start_vertex].done = 1; // <---- ��θ� �� ã�Ҵٰ� ǥ��

	for (int i = 0; i < G_SZ; i++) {
		if (graph[start_vertex][i] != -1) { // start_vertex --> i���� ���� ���� ���� ������,
			dtable[i].dist = graph[start_vertex][i];
			dtable[i].prev = start_vertex;
		}
	}

	// dtable���� ���� ª�� �Ÿ��� ���� vertex�̸鼭, done = 0�� vertex�� ã�´�.
	while (1) {
		int v = find_shortest_path_vertex(dtable);
		if (v == -1) { // Dijkstra �˰��� �Ϸ�
			break;
		}

		dtable[v].done = 1; // v������ �ִ� ��ΰ� �����Ǿ���.

		// v�� ���ؼ� ���ŵǴ� ��ΰ� �� ª�� vertex���� ã�Ƽ�,
		// �ش� dtable�� ����
		for (int i = 0; i < G_SZ; i++) {

			if (graph[v][i] > -1 && dtable[i].done == 0) {

				// i���� �ִܰ�ΰ� �������� ���� �͵� �߿���.
				// v�� ���ؼ� i���� ���� ���� ���� �˷��� �ͺ��� �� ª����

				// �̹� �˷��� �Ÿ� > v�� ���ؼ� ���� ��
				if (dtable[i].dist > dtable[v].dist + graph[v][i]) {
					dtable[i].dist = dtable[v].dist + graph[v][i];
					dtable[i].prev = v; // <---- ����
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