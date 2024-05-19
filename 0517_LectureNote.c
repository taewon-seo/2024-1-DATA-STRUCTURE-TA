#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-19 update
/*
*****************
* 20240517 실습 *
*****************
*/


#define SZ 100  // vertex 번호: 0 ~ 99

#if 0
#include <stdio.h>

// graph init
int graph[SZ][SZ];

// stack for DFS
int stack[SZ];
int top = -1;

// vertex i를 방문했는지 기록, 0 = not-visited, 1=visited
int vertex_info[SZ];

void mark_as_visited(int _v) {
    vertex_info[_v] = 1;
}

int visited(int _v) {
    return vertex_info[_v];
}

void push(int _v) {
    if (top == SZ - 1) {
        return;
    }
    top++;
    stack[top] = _v;
}

int pop(void) {
    if (top == -1) {
        return -999;   // EMPTY
    }
    int res = stack[top];
    top--;
    return res;
}

// vertex v1-v2 edge 정보 추가
void add_to_graph(int v1, int v2) {
    graph[v1][v2] = graph[v2][v1] = 1;
}

// stack 안에 _v가 있는지, 없는지를 판단하는 함수
// stack안에 없으면, return 0
//          있으면, return 1
int stacked(int _v) {
    for (int i = 0; i <= top; i++) {
        if (stack[i] == _v) {
            return 1;
        }
    }
    return 0;
}

// DFS
// _v에서 시작해서, 모든 노드를 깊이 우선 방문
void depth_first_search(int _v) {
    // 1. 시작 vertex를 push
    push(_v);

    // 무한반복
    while (1) {
        // 2. pop해서 visited라고 표시
        int k = pop();
        if (k == -999) { // stack empty
            return;
        }

        printf("%d  ", k);  // 방문 vertex로서 출력
        mark_as_visited(k); // vertex k를 방문했다고 표시해주는 함수

        // 3. pop된 vertex의 adjacent vertex(직접 이웃들)을 push
        //    단, not-visited, not-stacked
        for (int i = 0; i < SZ; i++) {
            if (graph[k][i] == 1 && visited(i) == 0 && stacked(i) == 0) {
                push(i);
            }
        }
    }
}

int main(void) {
    add_to_graph(1, 4);  // vertex 1에서 4가 직접 연결
    add_to_graph(5, 9);  // vertex 5에서 9가 직접 연결
    add_to_graph(2, 1);  // vertex 2에서 1이 직접 연결
    add_to_graph(5, 6);  // vertex 5에서 6이 직접 연결
    add_to_graph(5, 14); // vertex 5에서 14가 직접 연결
    add_to_graph(1, 5);  // vertex 1에서 5가 직접 연결
    add_to_graph(5, 4);  // vertex 5에서 4가 직접 연결

    depth_first_search(1);  // 모든 vertex 출력

    return 0;
}
#endif

#if 1
// BFS
#include <stdio.h>
#include <stdlib.h>

#define SZ 100  // vertex 번호: 0 ~ 99

// 그래프를 배열로 구현
int graph[SZ][SZ];

// vertex i를 방문했는지 기록, 0 = not-visited, 1=visited
int vertex_info[SZ];

// 큐 구현
int queue[SZ];
int front = 0;
int rear = 0;

// 방문 표시 함수
void mark_as_visited(int _v) {
    vertex_info[_v] = 1;
}

int visited(int _v) {
    return vertex_info[_v];
}

// 큐에 요소 추가
void enqueue(int _v) {
    if ((rear + 1) % SZ == front) {
        // 큐가 가득 찬 경우
        return;
    }
    queue[rear] = _v;
    rear = (rear + 1) % SZ;
}

// 큐에서 요소 제거
int dequeue(void) {
    if (front == rear) {
        // 큐가 비어있는 경우
        return -999;
    }
    int res = queue[front];
    front = (front + 1) % SZ;
    return res;
}

// queue 안에 _v가 있는지, 없는지를 판단하는 함수
// queue 안에 없으면, return 0
//          있으면, return 1
int inQueue(int _v) {
    int i = front;
    while (i != rear) {
        if (queue[i] == _v) {
            return 1;
        }
        i = (i + 1) % SZ;
    }
    return 0;
}

// 그래프에 edge 추가 함수
void add_to_graph(int v1, int v2) {
    graph[v1][v2] = graph[v2][v1] = 1;
}

// BFS
// _v에서 시작해서, 모든 노드를 너비 우선 방문
void breadth_first_search(int _v) {
    // 방문 정보 초기화
    for (int i = 0; i < SZ; i++) {
        vertex_info[i] = 0;
    }

    // 1. 시작 vertex를 enqueue
    enqueue(_v);

    // 무한반복
    while (1) {
        // 2. dequeue해서 visited라고 표시
        int k = dequeue();
        if (k == -999) { // queue empty
            return;
        }

        if (!visited(k)) {
            printf("%d  ", k);  // 방문 vertex로서 출력
            mark_as_visited(k); // vertex k를 방문했다고 표시해주는 함수

            // 3. dequeue된 vertex의 adjacent vertex(직접 이웃들)을 enqueue
            //    단, not-visited, not-in-queue
            for (int i = 0; i < SZ; i++) {
                if (graph[k][i] == 1 && visited(i) == 0 && inQueue(i) == 0) {
                    enqueue(i);
                }
            }
        }
    }
}

int main(void) {
    add_to_graph(1, 4);  // vertex 1에서 4가 직접 연결
    add_to_graph(5, 9);  // vertex 5에서 9가 직접 연결
    add_to_graph(2, 1);  // vertex 2에서 1이 직접 연결
    add_to_graph(5, 6);  // vertex 5에서 6이 직접 연결
    add_to_graph(5, 14); // vertex 5에서 14가 직접 연결
    add_to_graph(1, 5);  // vertex 1에서 5가 직접 연결
    add_to_graph(5, 4);  // vertex 5에서 4가 직접 연결

    breadth_first_search(1);  // 모든 vertex 출력

    return 0;
}

#endif