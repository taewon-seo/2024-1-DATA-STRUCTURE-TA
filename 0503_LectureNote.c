#define _CRT_SECURE_NO_WARNINGS


// made by taewon-seo, INU ESE, 2024-05-02 update
/*
*****************
* 20240503 �ǽ� *
*****************
*/

/*
[ �ǽ� ���� ]
BST �����ϱ�
DelFromBST �����ϱ�
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

	// 1. ���� ��带 �Ҵ�޾Ƽ�, _v�� �����Ѵ�.
	struct Node* new_node = createNode(_v);

	// 2. BST�� ����־, ó���� ���
	if (root == 0) {
		root = new_node;
		return;
	}
	// 3. BST�� �̹� ������ ����ִ� ���
	// 3.1 root�� ���Ͽ�, 
	//		������, �������� ��������
	//      ũ��, ���������� ��������,
	//      ����, ������ ���� ��������� �� ��ġ�� �߰�

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

	// 1. root���� ����
	struct Node* tmp = root;

	// 2. root�� �ִ� ���
	// 3. ������, root�� ���Ͽ�
	//		��������, ���������� �Ǵ��ϰ�, �������� ã�´�.
	//		������ ������, ���� ������ �� �������� ã�´�.

	while (1)
	{
		// BST�� ����ִ� ���,
		if (tmp == 0) {
			printf("%d�� ����!!\n", _v);
			return;
		}
		if (tmp->data == _v) {
			printf("%d�� ����!!\n", _v);
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

// �ڽ��� ���� ���
void handleNoChild(struct Node* _p, struct Node* _target) {

	// case 1. _p == 0
	// BST EMPTY
	if (_p == 0) {
		free(_target);
		root = 0;
		return;
	}
	// case 2. _p != 0
	// _p�� ���� Ȥ�� ���������� �Ǵ�, 
	// 0(NUL)L���� ó���ϰ�,
	// _target�� ����
	if (_p->left == _target) {
		_p->left = 0;
	}
	else {
		_p->right = 0;
	}
	free(_target);
	return;
}

// �ڽ��� 1���� ���
void handleOneChild(struct Node* _p, struct Node* _target) {
	// 1. _p == 0
	if (_p == 0) {  // _target�� root�ε�
		if (_target->left != 0) {  // �ڽ� 1��, ������ ���
			root = _target->left;
		}
		else {
			root = _target->right;
		}
		free(_target);
		return;
	}
	// 2. _p != 0
	// 2.1 �ϴ� ������ child�� �Ͽ��� target�� �ڽ��� ����Ű�� �Ѵ�.
	// 2.2. �θ��� �������� ���������� �Ǵ��ؼ�, ���ʿ� ���δ�.
	struct Node* child = (_target->left != 0) ? _target->left : _target->right;
	// �� �ڽ��� �׻� ���� �ڸ��� �����޴´�.
	if (_p->left == _target) {
		_p->left = child;
	}
	else {
		_p->right = child;
	}
	return;
}

// �ڽ��� 2���� ���
void handleTwoChildren(struct Node* _p, struct Node* _target) {

	// 1. �ϴ�, ��ü��带 ã�´�. _target�� ��ü�� ��带 ã�´�.
	// �İ��ڴ� ���ʿ��� �ö���� ��
	struct Node* replaceNode = _target->left;
	struct Node* new_p = _target;
	// new_p : replaceNode�� �θ�
	while (replaceNode->right != 0) {
		new_p = replaceNode;
		replaceNode = replaceNode->right;
	}
	// replaceNode ==> _taret�� ����, ���� ����� �������� ������.
	_target->data = replaceNode->data;

	// replaceNode�� ����
	// replaceNode�� �� 2���� ��츸 ����, �ڽ��� ���ų� 1���̰ų�.
	switch (cntChildren(replaceNode)) {
	case 0:
		handleNoChild(new_p, replaceNode);
		break;
	case 1:
		handleOneChild(new_p, replaceNode);
		break;
	default:
		printf("��û ����!!!\n");
		return;
	}
	return;
}


// BST���� ��� ����
// fromWhere : �˻��� root ���
// _what : ���� ���� ��带 ����
void delFromBST(struct Node* fromWhere, int _what) {

	struct Node* target = 0;    // ���� ����� ����Ű�� ������
	struct Node* p = 0;			// ���� ����� �θ��忡 ���� ������

	// 1. target���� �Ͽ���, _what�� ���� ��带 ����Ű�� �ϰ�,
	// 2. p�� target�� �θ� ����Ű�� �Ѵ�.
	target = fromWhere;
	while (target != 0) {
		if (target->data == _what) {  // ������� ���� ã����.
			break;
		}
		else { // ���� target�� ����Ű�� �Ϳ� _what�� �����Ƿ�, BST ��Ģ�� ���� �˻�
			p = target;
			if (target->data > _what) {
				target = target->left;
			}
			else {
				target = target->right;
			}
		}
	}
	// ����� ��
	// p = 0, target = 0    ===> BST�� empty
	// p != 0, target = 0   ===> ���ϴ°� ����

	// p = 0, target != 0   ===> root�� target
	// p != 0, target != 0  ===>  ���ϴ°� ã��
	if (target == 0) {
		return;
	}

	// ���ڽ�, ���ڽ�, ���ڽ�,
	int n_child = cntChildren(target);
	switch (n_child) {
	case 0:  // ���ڽ�
		handleNoChild(p, target);
		break;
	case 1:  // ���ڽ�
		handleOneChild(p, target);
		break;
	case 2:  // ���ڽ�
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

	delFromBST(root, 10); // root���� �����ؼ�, 10�� ��� ��带 �����.
	delFromBST(root, 100); // 100 ��� ��尡 �����Ƿ�, �ƹ� �͵� ���� �ʴ´�.

	inorder_traversal(root);

	return 0;
}




#if 0

// 1821: [2024 �����ͱ��� �ǽ�] BST ����

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
