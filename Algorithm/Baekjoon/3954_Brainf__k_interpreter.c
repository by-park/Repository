/*
3954 brain f**k interpreter
1. %c �� �޴� ��� \n ���๮�ڰ� ���� �޾�����
input�� �̻��ϰ� �޾�����. getchar() �� ���̿� �ְ� �ذ�
2. code max ���� 50000000 ���� �� �� edge case�� �ɷȴ�.
1�� �߰��ؼ� �ݷʸ� �����.
https://www.acmicpc.net/board/view/61124
Input :
2
65359 16 3
+[>+],...[[-],+]
999
65359 16 3
+[>+],[[-],+]+[]
999

Answer :
Terminates
Loops 14 15
3. Loops ���� => ���� �ֱ� ������ �ϸ� �� ��
https://www.acmicpc.net/board/view/9096
���ѷ����� �ش��ϴ� ������ �ֱٿ� �ִ� ������� ������ �����ϴ�.
����, +[+[-]] ���� ���� ��ø ������ ������ ���� ���� �ٱ� ��������, �쿬�� 5õ�� ��° ���� �߿� ���� ���� ������ �����ϰ� �־��ٸ� ���� ������ ������ ����ع��� ���Դϴ�.
https://www.acmicpc.net/board/view/61103
Input
2
3 124 1
+[-[[>+[>----------------------------------[+++]<+]++++++++++++++++++++++++++[+]<+]----------------------------------[+]]++]
.
1 8 1
+[-[]++]
.

Output
Loops 1 123
Loops 3 4
4. infinite loop �ȿ� 50000000 �� ����
terminate �Ŀ��� 50000000 �� ����ǵ��� �ٲ�

https://www.acmicpc.net/board/view/61124
Input
1
3 209 1
+[>+[>----------------------------------[+++]<+]++++++++++++++++++++++++++[+]<+],[-].+[-[[>+[>----------------------------------[+++]<+]++++++++++++++++++++++++++[+]<+]----------------------------------[+]]++]
1

Output
Loops 86 208

5. ���ѷ��� ���Խ� ������ �׻� �������� ����
���ѷ��� [ �� ���ƿ� �� ������ �׻� �Ȱ��� �ʴ�.
������ ++ �� ������ �þ ���� ����
=> ���ѷ��� üũ�� �� �� ã���� ���� ���� �������� Ż�� ���ϴ� ��

https://www.acmicpc.net/board/view/58310
===== �Է� =====
2
10 5 1
+[[]]
a
1 9 1
++[[++]+]
a

===== ��� =====
Loops 2 3
Loops 3 6

6. ��� �ݷ� �����ϰ��� wrong
5������ ���ѷ����� �׻� ������ �Ȱ��� �ʴٴ°� ������ ��...
���� ���� ���� ���� �߰� ������ ���̵��� �ݷ� ������
1���°�� �쿬�� ���� ������ �ֵ���

���� ���� �� �ڵ� �ݷ�
1
8 23 1
++[[[>>>>>>]<<<<<<++]+]
a

4+17*n �ϸ� 100000001��°�� 10 ��° �ڵ� (>) ���� ��
��
Loops 3 20
=> �Ϲ����� Ǯ���� min, max ���� ����
https://kibbomi.tistory.com/6

7. �ڷ��� ���� ����
�׷��� Ʋ�ȴµ�, unsigned char �ϸ� ����ȯ�� ���� �̻��ϰ� �ٲ峪 �;
int�� �� �ٲ��.

=> ���!
(memory[pointer] + 256 - 1) % 256; �̷� �κп��� ����ȯ�� ������ ����Ű�� �� �˾Ҵµ�,
Ȯ�� ��� jumps[] �迭�� ���� ���� 0~4096 index �ε�,
�̰� unsigned char �� �����ع����� ������ �Ǿ���.
*/

#include <stdio.h>

int msize;
int csize;
int isize;
int pointer;
int input_index;

unsigned char codes[4096];
unsigned char inputs[4096];
unsigned char memory[100010];
int jumps[4096]; // �Ǽ��� ����, �̰� 4096 index ���� �����ϴµ� unsigned char �� �߸� ������

int stack[5000];
int stack_pos[5000];
int cptr;
int sp;
int tc;

void preprocess(void)
{
	sp = 0;
	for (int i = 0; i < csize; i++) {
		if (codes[i] == '[') {
			sp++;
			stack[sp] = i;
		}
		if (codes[i] == ']') {
			jumps[stack[sp]] = i;
			jumps[i] = stack[sp];
			sp--;
		}
	}
}

int do_code(int index)
{
	int ret = index + 1;

	if (codes[index] == '-') {
		memory[pointer] = (memory[pointer] + 256 - 1) % 256;
	}
	else if (codes[index] == '+') {
		memory[pointer] = (memory[pointer] + 1) % 256;
	}
	else if (codes[index] == '<') {
		pointer = (pointer + msize - 1) % msize;
	}
	else if (codes[index] == '>') {
		pointer = (pointer + 1) % msize;
	}
	else if (codes[index] == '[') {
		if (memory[pointer] == 0) { /* loop pass */
			ret = jumps[index] + 1;
		}
		else {
			stack_pos[sp] = cptr;
			stack[sp] = index;
			sp++;
		}
	}
	else if (codes[index] == ']') {
		if (memory[pointer] != 0) {
			ret = jumps[index] + 1;
			stack_pos[sp - 1] = cptr; /* update */
		}
		else sp--; /* loop end */
	}
	else if (codes[index] == ',') {
		if (input_index >= isize) {
			memory[pointer] = 255;
		}
		else {
			memory[pointer] = inputs[input_index++];
		}
	} // pass "."

	return ret;
}

void run(void)
{
	int max_code = 50000001;
	int index = 0;
	int i;

	pointer = 0;
	input_index = 0;
	sp = 0;
	cptr = 0;

	/* terminates within 50 000 000 instructions */
	while (max_code--) {
		if (index >= csize) {
			printf("Terminates\n");
			return;
		}
		index = do_code(index);
		cptr++;
	}

	/* at most 50 000 000 instructions within infinite loop */
	max_code = 50000001;
	while (max_code--) {
		index = do_code(index);
		cptr++;
	}

	for (i = 0; i < sp; i++) {
		if (cptr-1-stack_pos[i] <= 50000000) {
			printf("Loops %d %d\n", stack[i], jumps[stack[i]]);
			break;
		}
	}
}

void init(void)
{
	scanf("%d %d %d", &msize, &csize, &isize);

	for (int i = 0; i < msize; i++) {
		memory[i] = 0;
	}
	for (int i = 0; i < csize; i++) {
		scanf(" %c", &codes[i]);
	}
	getchar();
	for (int i = 0; i < isize; i++) {
		scanf(" %c", &inputs[i]);
	}
	getchar();
}

int main(void)
{
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {

		/* get input & init arrays */
		init();

		/* [[ ]] find sets */
		preprocess();

		/* start codes */
		run();
	}
}