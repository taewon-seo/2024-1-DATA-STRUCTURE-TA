#define _CRT_SECURE_NO_WARNINGS


// made by taewon-seo, INU ESE, 2024-05-02 update
/*
*****************
* 20240503 실습 *
*****************
*/

/*
[ 실습 내용 ]
BST 구현하기
DelFromBST 구현하기
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root = 0;

struct Node* createNode(int _v) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = _v;
	new_node->left = 0;
	new_node->right = 0;
	return new_node;
}

void add_to_BST(int _v) {

	// 1. 새로 노드를 할당받아서, _v를 저장한다.
	struct Node* new_node = createNode(_v);

	// 2. BST가 비어있어서, 처음인 경우
	if (root == 0) {
		root = new_node;
		return;
	}
	// 3. BST에 이미 노드들이 들어있는 경우
	// 3.1 root와 비교하여, 
	//		작으면, 왼쪽으로 내려가고
	//      크면, 오른쪽으로 내려가고,
	//      만약, 내려갈 곳이 비어있으면 그 위치에 추가

	struct Node* tmp = root; 

	while (1) {
		if (new_node->data < tmp->data) { 
			if (tmp->left == 0) {
				tmp->left = new_node;
				return;
			}
			tmp = tmp->left;
		}
		else { 
			if (tmp->right == 0) {
				tmp->right = new_node;
				return;
			}
			tmp = tmp->right;
		}
	}
}

void findNode(int _v) {

	// 1. root에서 시작
	struct Node* tmp = root;

	// 2. root에 있는 경우
	// 3. 없으면, root와 비교하요
	//		왼쪽인지, 오른쪽인지 판단하고, 내려가서 찾는다.
	//		없으면 끝내고, 무언가 있으면 또 내려가서 찾는다.

	while (1)
	{
		// BST가 비어있는 경우,
		if (tmp == 0) {
			printf("%d가 없음!!\n", _v);
			return;
		}
		if (tmp->data == _v) {
			printf("%d가 있음!!\n", _v);
			return;
		}
		if (tmp->data > _v) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
}

void inorder_traversal(struct Node* node) {

	if (node == 0) {
		return;
	}
	inorder_traversal(node->left);
	printf("%d ", node->data);
	inorder_traversal(node->right);
}


int cntChildren(struct Node* n) {
	int cnt = 0;
	if (n->left != 0) {
		cnt++;
	}
	if (n->right != 0) {
		cnt++;
	}
	return cnt;
}

// 자식이 없는 경우
void handleNoChild(struct Node* _p, struct Node* _target) {

	// case 1. _p == 0
	// BST EMPTY
	if (_p == 0) {
		free(_target);
		root = 0;
		return;
	}
	// case 2. _p != 0
	// _p의 왼쪽 혹은 오른쪽인지 판단, 
	// 0(NUL)L으로 처리하고,
	// _target을 삭제
	if (_p->left == _target) {
		_p->left = 0;
	}
	else {
		_p->right = 0;
	}
	free(_target);
	return;
}

// 자식이 1명인 경우
void handleOneChild(struct Node* _p, struct Node* _target) {
	// 1. _p == 0
	if (_p == 0) {  // _target이 root인데
		if (_target->left != 0) {  // 자식 1명, 왼쪽인 경우
			root = _target->left;
		}
		else {
			root = _target->right;
		}
		free(_target);
		return;
	}
	// 2. _p != 0
	// 2.1 일단 포인터 child로 하여금 target의 자식을 가리키게 한다.
	// 2.2. 부모의 왼쪽인지 오른쪽인지 판단해서, 그쪽에 붙인다.
	struct Node* child = (_target->left != 0) ? _target->left : _target->right;
	// 내 자식은 항상 나의 자리를 물려받는다.
	if (_p->left == _target) {
		_p->left = child;
	}
	else {
		_p->right = child;
	}
	return;
}

// 자식이 2명인 경우
void handleTwoChildren(struct Node* _p, struct Node* _target) {

	// 1. 일단, 대체노드를 찾는다. _target을 대체할 노드를 찾는다.
	// 후계자는 왼쪽에서 올라오는 것
	struct Node* replaceNode = _target->left;
	struct Node* new_p = _target;
	// new_p : replaceNode의 부모
	while (replaceNode->right != 0) {
		new_p = replaceNode;
		replaceNode = replaceNode->right;
	}
	// replaceNode ==> _taret에 복사, 지울 대상을 말단으로 보낸다.
	_target->data = replaceNode->data;

	// replaceNode를 삭제
	// replaceNode는 딱 2가지 경우만 존재, 자식이 없거나 1명이거나.
	switch (cntChildren(replaceNode)) {
	case 0:
		handleNoChild(new_p, replaceNode);
		break;
	case 1:
		handleOneChild(new_p, replaceNode);
		break;
	default:
		printf("엄청 에러!!!\n");
		return;
	}
	return;
}


// BST에서 노드 삭제
// fromWhere : 검색할 root 노드
// _what : 값을 가진 노드를 삭제
void delFromBST(struct Node* fromWhere, int _what) {

	struct Node* target = 0;    // 지울 대상을 가리키는 포인터
	struct Node* p = 0;			// 지울 대상의 부모노드에 대한 포인터

	// 1. target으로 하여금, _what을 담은 노드를 가리키게 하고,
	// 2. p는 target의 부모를 가리키게 한다.
	target = fromWhere;
	while (target != 0) {
		if (target->data == _what) {  // 지우려는 것을 찾았음.
			break;
		}
		else { // 현재 target이 가리키는 것에 _what이 없으므로, BST 규칙에 따라서 검색
			p = target;
			if (target->data > _what) {
				target = target->left;
			}
			else {
				target = target->right;
			}
		}
	}
	// 경우의 수
	// p = 0, target = 0    ===> BST가 empty
	// p != 0, target = 0   ===> 원하는게 없음

	// p = 0, target != 0   ===> root가 target
	// p != 0, target != 0  ===>  원하는걸 찾음
	if (target == 0) {
		return;
	}

	// 무자식, 일자식, 쌍자식,
	int n_child = cntChildren(target);
	switch (n_child) {
	case 0:  // 무자식
		handleNoChild(p, target);
		break;
	case 1:  // 일자식
		handleOneChild(p, target);
		break;
	case 2:  // 쌍자식
		handleTwoChildren(p, target);
		break;
	default:
		printf("ERROR WRONG CHILDREN NUMBER");
		return;
	}
	return;
}


int main(void) {

	// 30, 50, 10, 20, 25, 45
	add_to_BST(30);
	add_to_BST(50);
	add_to_BST(10);
	add_to_BST(20);
	add_to_BST(25);
	add_to_BST(45);

	delFromBST(root, 10); // root부터 시작해서, 10이 담긴 노드를 지운다.
	delFromBST(root, 100); // 100 담긴 노드가 없으므로, 아무 것도 하지 않는다.

	inorder_traversal(root);

	return 0;
}




#if 0

// 1821: [2024 데이터구조 실습] BST 응용

#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE node;
struct _NODE {
	int data;
	node* left;
	node* right;
	node* parent;
};
node* root = 0;

void addToBST(int _v) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->parent = _new->left = _new->right = 0;
	if (root) {
		node* temp = root;
		while (1) {
			if (temp->data > _new->data) {
				if (temp->left == 0) {
					temp->left = _new;
					_new->parent = temp;
					return;
				}
				temp = temp->left;
			}
			else {
				if (temp->right == 0) {
					temp->right = _new;
					_new->parent = temp;
					return;
				}
				temp = temp->right;
			}
		}
	}
	root = _new;
	return;
}

void delFromBST(int _v) {
	if (root) {
		node* temp = root;
		while (temp) {
			if (temp->data > _v) {
				temp = temp->left;
				continue;
			}
			if (temp->data < _v) {
				temp = temp->right;
				continue;
			}
			if (temp->left == 0 && temp->right == 0) {
				if (temp->parent) {
					if (temp->parent->left == temp) {
						temp->parent->left = 0;
					}
					else {
						temp->parent->right = 0;
					}
				}
				else {
					root = 0;
				}
				free(temp);
				return;
			}
			if (temp->left && temp->right) {
				node* spear = temp->right;
				while (spear->left) {
					spear = spear->left;
				}
				int backup = spear->data;
				delFromBST(backup);
				temp->data = backup;
				return;
			}
			if (temp->left) {
				if (temp->parent) {
					if (temp->parent->left == temp) {
						temp->parent->left = temp->left;
					}
					else {
						temp->parent->right = temp->left;
					}
					temp->left->parent = temp->parent;
				}
				else {
					root = temp->left;
					root->parent = 0;
				}
			}
			else {
				if (temp->parent) {
					if (temp->parent->left == temp) {
						temp->parent->left = temp->right;
					}
					else {
						temp->parent->right = temp->right;
					}
					temp->right->parent = temp->parent;
				}
				else {
					root = temp->right;
					root->parent = 0;
				}
			}
			free(temp);
			return;
		}
	}
	return;
}

void inorder_traversal(node* node) {
	if (root == 0) {
		printf("-999");
		return;
	}
	if (node == 0) {
		return;
	}
	inorder_traversal(node->left);
	printf("%d ", node->data);
	inorder_traversal(node->right);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n) {
		if (n > 0) {
			addToBST(n);
		}
		if (n == -1) {
			scanf("%d", &n);
			delFromBST(n);
		}
		else if (n == -2) {
			if (root) {
				delFromBST(root->data);
			}
		}
		else if (n == -3) {
			if (root) {
				node* temp = root;
				while (temp->right) {
					temp = temp->right;
				}
				delFromBST(temp->data);
			}
		}
		else if (n == -4) {
			if (root) {
				node* temp = root;
				while (temp->left) {
					temp = temp->left;
				}
				delFromBST(temp->data);
			}
		}
		scanf("%d", &n);
	}
	inorder_traversal(root);
	return 0;
}

#endif
