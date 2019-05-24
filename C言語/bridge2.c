
#include<stdio.h>
#include<time.h>
#include"MT.h"
int checkuse[52];//���̃J�[�h���z��ꂽ�����L������B0~12��SA~S2�B���g�p�Ȃ�0�g�p���Ȃ�1��Ԃ��B
int Insertcnt[4];//������Insert���ꂽ���J�E���g����B0��N��NSEW�̏��B���p�͂���œ���B
int checkInsert[4][13];//�Ȃɂ�Insert���ꂽ�����L������B�O�����p��낪���ʔԍ��B�Ⴆ�΂܂��AN��Insert�����[0][0]��Insert���ꂽ�J�[�h�̒l���i�[����A����N��Insert������[0][1]�Ɋi�[�����B
int card[4][13];//�z��ꂽ�J�[�h���L������B�O�����p��낪���ʔԍ��BcheckInsert�Ɠ����v�́B�Ȃɂ��L������Ă��Ȃ�����0���������SA�Ɣ��̂ŉ��������Ă��Ȃ�����100������B����checkInsert�ł����l�B
int shapevec[4][2][4];//shape�̏������L������B�O���珇�ɕ��p�A�ŏ�or�ő�(0��min,1��max),suit(0����SHDC�̏�),�܂�[0][0][0]�ɂ�N�̍ŏ���S�̖������L�������B
int hcpvec[4][2];//hcp�̏������L������B�O�����p�����낪max or min,shapevec�Ɠ����v�́B

void first_reset() {			//�S�Ă����Z�b�g����֐�
	for (int i = 0; i < 52; i++)
		checkuse[i] = 0;
	for (int i = 0; i < 4; i++)
		Insertcnt[i] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			card[i][j] = 100;
			checkInsert[i][j] = 100;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			shapevec[i][0][j] = 0;
			shapevec[i][1][j] = 13;
		}
	}
	for (int i = 0; i < 4; i++) {
		hcpvec[i][0] = 0;
		hcpvec[i][1] = 40;
	}

}


void handreset() {			//Insert���ꂽ���̂����Ȃ��烊�Z�b�g�B��̓I�ɂ͈�U�S��������checkInsert�Ɋi�[����Ă������̂����������B
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			checkuse[card[j][i]] = 0;
			card[j][i] = 100;
		}
		for (int i = 0; i < Insertcnt[j]; i++) {
			card[j][i] = checkInsert[j][i];
			checkuse[card[j][i]] = 1;
		}
	}
}

void printchange(int x) {//�����𕶎��ɕϊ����ďo�͂���֐��B
	if (x % 13 == 0)printf("A");
	if (x % 13 == 1)printf("K");
	if (x % 13 == 2)printf("Q");
	if (x % 13 == 3)printf("J");
	if (x % 13 == 4)printf("T");
	if (x % 13 == 5)printf("9");
	if (x % 13 == 6)printf("8");
	if (x % 13 == 7)printf("7");
	if (x % 13 == 8)printf("6");
	if (x % 13 == 9)printf("5");
	if (x % 13 == 10)printf("4");
	if (x % 13 == 11)printf("3");
	if (x % 13 == 12)printf("2");

}

void printout() {		//����������NSEW�̃n���h���o�͂���֐��B�O�q��printchange���g�p�Bcard[i][]�̓\�[�g����Ă���O��B
	printf("\t\tN\n\t\t");
	int i, j;
	for (i = 0; i < 13; i++) {
		if (card[0][i] < 13)
			printchange(card[0][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {//i=0�ƂȂ��ĂȂ��͎̂d�l�B���for����S�̌����L������Ă���̂ł�������X�^�[�g����Ƃ��܂�H���o�͂ł���B
		if (card[0][i] < 26)
			printchange(card[0][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (card[0][i] < 39)
			printchange(card[0][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (card[0][i] < 52)
			printchange(card[0][i]);
		else break;
	}
	printf("\n");
	//�����܂ł�N�̏o��
	printf("W\t\t\t\tE\n");
	for (i = 0; i < 13; i++) {
		if (card[3][i] < 13)
			printchange(card[3][i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j = 0; j < 13; j++) {
		if (card[2][j] < 13)
			printchange(card[2][j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (card[3][i] < 26)
			printchange(card[3][i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (card[2][j] < 26)
			printchange(card[2][j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (card[3][i] < 39)
			printchange(card[3][i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (card[2][j] < 39)
			printchange(card[2][j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (card[3][i] < 52)
			printchange(card[3][i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (card[2][j] < 52)
			printchange(card[2][j]);
		else
			break;
	}
	printf("\n");
	//�����܂ł�W-E�̏o�́iWE�͈ʒu�̊֌W����s���ďo�͂��Ȃ���΂Ȃ�Ȃ�)
	printf("\t\tS\n\t\t");
	for (i = 0; i < 13; i++) {
		if (card[1][i] < 13)
			printchange(card[1][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (card[1][i] < 26)
			printchange(card[1][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (card[1][i] < 39)
			printchange(card[1][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (card[1][i] < 52)
			printchange(card[1][i]);
		else break;
	}
	printf("\n");
	//S�̏o�́B
}

void Allinsert() {//�c���Ă���J�[�h��S���z��֐��BInsercnt�̂��A��Insert���ꂽ���p�������Ă�Insert���ꂽ�񐔕��z�閇�������炷���Ƃ��ł���B
	for (int j = 0; j < 4; j++) {
		int i = 0;
		while (i < 13 - Insertcnt[j]) {
			if (card[j][i + Insertcnt[j]] == 100) {
				int r;
				r = genrand_int32() % (51 - 0 + 1) + 0;
				if (checkuse[r] == 0) {
					card[j][i + Insertcnt[j]] = r;
					checkuse[r] = 1;
					i++;
				}
			}
			else

				i++;
		}
	}
}

void sort() {//�\�[�g�֐��Bcard[i][0]����card[i][12]�܂ł�0��������12���傫���Ȃ�悤�ɕ��בւ���(i=0~3)
	int i, j, tmp;
	for (int k = 0; k < 4; k++) {
		for (i = 0; i < 13; ++i) {
			for (j = i + 1; j < 13; ++j) {
				if (card[k][i] > card[k][j]) {
					tmp = card[k][i];
					card[k][i] = card[k][j];
					card[k][j] = tmp;
				}
			}
		}
	}
}

void insert(int a, int b) {//����Insert�Ɏg���֐��B���ۂ�Insert����̂͂����B�����ɕ��p��Insert�����J�[�h�����B
	int flag = 0;
	if (checkuse[b] == 1) {
		printf("already used\n");
	}
	else {
		card[a][Insertcnt[a]] = b;
		checkInsert[a][Insertcnt[a]] = b;
		Insertcnt[a]++;
		checkuse[b] = 1;
	}
}

void Insert() {//Insert���[�h�ɓ��������̃A�i�E���X��A���p�A��̓I�ȃJ�[�h�̓��͂��󂯕t����B
	int a;
	int flag = 0;
	while (flag == 0) {
		printf("Where?\n0:N\n1:S\n2:E\n3:W\n");
		scanf("%d", &a);
		printf("What card?\n");
		int b;
		scanf("%d", &b);
		insert(a, b);
		printf("again?\n0:Yes1:No\n");
		scanf("%d", &a);
		if (a == 1)
			break;
	}
}

void shape(int b) {//��q��condition()�Ŏg�p�Bshape�̏����w�������֐��B�����ɕ��p�����B
	int a, c, d;
	printf("suit? 0:S 1:H 2:D 3:C\n");
	scanf("%d", &a);
	printf("min?\n");
	scanf("%d", &c);
	printf("max?\n");
	scanf("%d", &d);
	shapevec[b][0][a] = c;
	shapevec[b][1][a] = d;
}

void hcp(int b) {//shape()��hcp�o�[�W����
	int c, d;
	printf("min?\n");
	scanf("%d", &c);
	printf("max?\n");
	scanf("%d", &d);
	hcpvec[b][0] = c;
	hcpvec[b][1] = d;
}

void condition() {//condition���[�h�Ŏg�p����֐��B

	int a, b;
	printf("What?\n0:shape 1:HCP\n");
	scanf("%d", &a);
	if (a == 0) {
		printf("Where?\n0:N 1:S 2:E 3:W\n");
		scanf("%d", &b);
		shape(b);
	}
	else if (a == 1) {
		printf("Where?\n0:N 1:S 2:E 3:W");
		scanf("%d", &b);
		hcp(b);

	}
}

int checkcondition() {//�������m�F����֐��B�������Ă����0���A�������Ă��Ȃ����1��Ԃ��B
	for (int j = 0; j < 4; j++) {
		int cnt = 0;
		for (int i = 0; i < 13; i++)
			if (card[j][i] / 13 == 0) cnt++;
		if (cnt<shapevec[j][0][0] || cnt>shapevec[j][1][0])
			return 1;
		cnt = 0;
		for (int i = 0; i < 13; i++)
			if (card[j][i] / 13 == 1) cnt++;
		if (cnt<shapevec[j][0][1] || cnt>shapevec[j][1][1])
			return 1;
		cnt = 0;
		for (int i = 0; i < 13; i++)
			if (card[j][i] / 13 == 2) cnt++;
		if (cnt<shapevec[j][0][2] || cnt>shapevec[j][1][2])
			return 1;
		cnt = 0;
		for (int i = 0; i < 13; i++)
			if (card[j][i] / 13 == 3) cnt++;
		if (cnt<shapevec[j][0][3] || cnt>shapevec[j][1][3])
			return 1;
		cnt = 0;
		for (int i = 0; i < 13; i++)
			if (card[j][i] % 13 <= 4)cnt = cnt + 4 - card[j][i] % 13;
		if (cnt<hcpvec[j][0] || cnt>hcpvec[j][1])
			return 1;
	}
	return 0;
}



int main() {
	init_genrand((unsigned)time(NULL));
	first_reset();
	int flag = 0;
	int a;
	while (flag == 0) {
		printf("0:output\n1:insert\n2:condition\n3:allclear\n4:bye\n");
		scanf("%d", &a);
		if (a == 0) {
			do {
				handreset();
				Allinsert();
				sort();
			} while (checkcondition() == 1);

			printout();
			handreset();//�����ň�U���Z�b�g���Ă����Ȃ��ƁA����Insert���鎞��already used�ɂȂ��Ă��܂��B
		}
		else if (a == 1)
			Insert();
		else if (a == 2)
			condition();
		else if (a == 3)
			first_reset();
		else if (a == 4)
			flag = 1;
	}
	return 0;
}


