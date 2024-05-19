#define _CRT_SECURE_NO_WARNINGS

// made by taewon-seo, INU ESE, 2024-05-19 update
/*
*****************
* 20240517 �ǽ� *
*****************
*/


#define SZ 100  // vertex ��ȣ: 0 ~ 99

#if 0
#include <stdio.h>

// graph init
int graph[SZ][SZ];

// stack for DFS
int stack[SZ];
int top = -1;

// vertex i�� �湮�ߴ��� ���, 0 = not-visited, 1=visited
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

// vertex v1-v2 edge ���� �߰�
void add_to_graph(int v1, int v2) {
    graph[v1][v2] = graph[v2][v1] = 1;
}

// stack �ȿ� _v�� �ִ���, �������� �Ǵ��ϴ� �Լ�
// stack�ȿ� ������, return 0
//          ������, return 1
int stacked(int _v) {
    for (int i = 0; i <= top; i++) {
        if (stack[i] == _v) {
            return 1;
        }
    }
    return 0;
}

// DFS
// _v���� �����ؼ�, ��� ��带 ���� �켱 �湮
void depth_first_search(int _v) {
    // 1. ���� vertex�� push
    push(_v);

    // ���ѹݺ�
    while (1) {
        // 2. pop�ؼ� visited��� ǥ��
        int k = pop();
        if (k == -999) { // stack empty
            return;
        }

        printf("%d  ", k);  // �湮 vertex�μ� ���
        mark_as_visited(k); // vertex k�� �湮�ߴٰ� ǥ�����ִ� �Լ�

        // 3. pop�� vertex�� adjacent vertex(���� �̿���)�� push
        //    ��, not-visited, not-stacked
        for (int i = 0; i < SZ; i++) {
            if (graph[k][i] == 1 && visited(i) == 0 && stacked(i) == 0) {
                push(i);
            }
        }
    }
}

int main(void) {
    add_to_graph(1, 4);  // vertex 1���� 4�� ���� ����
    add_to_graph(5, 9);  // vertex 5���� 9�� ���� ����
    add_to_graph(2, 1);  // vertex 2���� 1�� ���� ����
    add_to_graph(5, 6);  // vertex 5���� 6�� ���� ����
    add_to_graph(5, 14); // vertex 5���� 14�� ���� ����
    add_to_graph(1, 5);  // vertex 1���� 5�� ���� ����
    add_to_graph(5, 4);  // vertex 5���� 4�� ���� ����

    depth_first_search(1);  // ��� vertex ���

    return 0;
}
#endif

#if 1
// BFS
#include <stdio.h>
#include <stdlib.h>

#define SZ 100  // vertex ��ȣ: 0 ~ 99

// �׷����� �迭�� ����
int graph[SZ][SZ];

// vertex i�� �湮�ߴ��� ���, 0 = not-visited, 1=visited
int vertex_info[SZ];

// ť ����
int queue[SZ];
int front = 0;
int rear = 0;

// �湮 ǥ�� �Լ�
void mark_as_visited(int _v) {
    vertex_info[_v] = 1;
}

int visited(int _v) {
    return vertex_info[_v];
}

// ť�� ��� �߰�
void enqueue(int _v) {
    if ((rear + 1) % SZ == front) {
        // ť�� ���� �� ���
        return;
    }
    queue[rear] = _v;
    rear = (rear + 1) % SZ;
}

// ť���� ��� ����
int dequeue(void) {
    if (front == rear) {
        // ť�� ����ִ� ���
        return -999;
    }
    int res = queue[front];
    front = (front + 1) % SZ;
    return res;
}

// queue �ȿ� _v�� �ִ���, �������� �Ǵ��ϴ� �Լ�
// queue �ȿ� ������, return 0
//          ������, return 1
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

// �׷����� edge �߰� �Լ�
void add_to_graph(int v1, int v2) {
    graph[v1][v2] = graph[v2][v1] = 1;
}

// BFS
// _v���� �����ؼ�, ��� ��带 �ʺ� �켱 �湮
void breadth_first_search(int _v) {
    // �湮 ���� �ʱ�ȭ
    for (int i = 0; i < SZ; i++) {
        vertex_info[i] = 0;
    }

    // 1. ���� vertex�� enqueue
    enqueue(_v);

    // ���ѹݺ�
    while (1) {
        // 2. dequeue�ؼ� visited��� ǥ��
        int k = dequeue();
        if (k == -999) { // queue empty
            return;
        }

        if (!visited(k)) {
            printf("%d  ", k);  // �湮 vertex�μ� ���
            mark_as_visited(k); // vertex k�� �湮�ߴٰ� ǥ�����ִ� �Լ�

            // 3. dequeue�� vertex�� adjacent vertex(���� �̿���)�� enqueue
            //    ��, not-visited, not-in-queue
            for (int i = 0; i < SZ; i++) {
                if (graph[k][i] == 1 && visited(i) == 0 && inQueue(i) == 0) {
                    enqueue(i);
                }
            }
        }
    }
}

int main(void) {
    add_to_graph(1, 4);  // vertex 1���� 4�� ���� ����
    add_to_graph(5, 9);  // vertex 5���� 9�� ���� ����
    add_to_graph(2, 1);  // vertex 2���� 1�� ���� ����
    add_to_graph(5, 6);  // vertex 5���� 6�� ���� ����
    add_to_graph(5, 14); // vertex 5���� 14�� ���� ����
    add_to_graph(1, 5);  // vertex 1���� 5�� ���� ����
    add_to_graph(5, 4);  // vertex 5���� 4�� ���� ����

    breadth_first_search(1);  // ��� vertex ���

    return 0;
}

#endif