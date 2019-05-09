#include<stdio.h>
#include<time.h>
#include"MT.h"
int checkuse[52];
int Ncheckuse;
int Scheckuse;
int Echeckuse;
int Wcheckuse;//使用済みの個数
int NcheckInsert[13];
int ScheckInsert[13];
int EcheckInsert[13];
int WcheckInsert[13];//Insertしたカード
int N[13];
int S[13];
int E[13];
int W[13];
int Nshapevec[2][4];
int Sshapevec[2][4];
int Eshapevec[2][4];
int Wshapevec[2][4];//前0:min 1:max 後:suit 0がS
int Nhcpvec[2];
int Shcpvec[2];
int Ehcpvec[2];
int Whcpvec[2];//0:min 1:max

void Nsort() {
	int i, j, tmp;
	for (i = 0; i<13; ++i) {
		for (j = i + 1; j<13; ++j) {
			if (N[i] > N[j]) {
				tmp = N[i];
				N[i] = N[j];
				N[j] = tmp;
			}
		}
	}
}

void Ssort() {
	int i, j, tmp;
	for (i = 0; i<13; ++i) {
		for (j = i + 1; j<13; ++j) {
			if (S[i] > S[j]) {
				tmp = S[i];
				S[i] = S[j];
				S[j] = tmp;
			}
		}
	}
}

void Esort() {
	int i, j, tmp;
	for (i = 0; i<13; ++i) {
		for (j = i + 1; j<13; ++j) {
			if (E[i] > E[j]) {
				tmp = E[i];
				E[i] = E[j];
				E[j] = tmp;
			}
		}
	}
}

void Wsort() {
	int i, j, tmp;
	for (i = 0; i<13; ++i) {
		for (j = i + 1; j<13; ++j) {
			if (W[i] > W[j]) {
				tmp = W[i];
				W[i] = W[j];
				W[j] = tmp;
			}
		}
	}
}

void printchange(int x) {
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

void Nprintout() {
	printf("\t\tN\n\t\t");
	int i;
	for (i = 0; i < 13; i++) {
		if (N[i] < 13)
			printchange(N[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (N[i] < 26)
			printchange(N[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (N[i] < 39)
			printchange(N[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (N[i] < 52)
			printchange(N[i]);
		else break;
	}
	printf("\n");
}
void Sprintout() {
	printf("\t\tS\n\t\t");
	int i;
	for (i = 0; i < 13; i++) {
		if (S[i] < 13)
			printchange(S[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (S[i] < 26)
			printchange(S[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (S[i] < 39)
			printchange(S[i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {
		if (S[i] < 52)
			printchange(S[i]);
		else break;
	}
	printf("\n");
}
void Eprintout() {
	printf("E\n");
	int i;
	for (i = 0; i < 13; i++) {
		if (E[i] < 13)
			printchange(E[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (E[i] < 26)
			printchange(E[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (E[i] < 39)
			printchange(E[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (E[i] < 52)
			printchange(E[i]);
		else break;
	}
	printf("\n");
}
void Wprintout() {
	printf("W\n");
	int i;
	for (i = 0; i < 13; i++) {
		if (W[i] < 13)
			printchange(W[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 26)
			printchange(W[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 39)
			printchange(W[i]);
		else break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 52)
			printchange(W[i]);
		else break;
	}
	printf("\n");
}

void WEprintout() {
	printf("W\t\t\t\tE\n");
	int i, j;
	for (i = 0; i < 13; i++) {
		if (W[i] < 13)
			printchange(W[i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j = 0; j < 13; j++) {
		if (E[j] < 13)
			printchange(E[j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 26)
			printchange(W[i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (E[j] < 26)
			printchange(E[j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 39)
			printchange(W[i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (E[j] < 39)
			printchange(E[j]);
		else
			break;
	}
	printf("\n");
	for (i; i < 13; i++) {
		if (W[i] < 52)
			printchange(W[i]);
		else
			break;
	}
	printf("\t\t\t\t");
	for (j; j < 13; j++) {
		if (E[j] < 52)
			printchange(E[j]);
		else
			break;
	}
	printf("\n");
}

void Ninsert(int x){
	int flag = 0;
	if (checkuse[x] == 1) {
		printf("already used");
	}
	else {
		N[Ncheckuse] = x;
		NcheckInsert[Ncheckuse] = x;
		Ncheckuse++;
		checkuse[x] = 1;
	}
}
void Sinsert(int x) {
	int flag = 0;
	if (checkuse[x] == 1) {
		printf("already used");
	}
	else {
		S[Scheckuse] = x;
		ScheckInsert[Scheckuse] = x;
		Scheckuse++;
		checkuse[x] = 1;
	}
}
void Einsert(int x) {
	int flag = 0;
	if (checkuse[x] == 1) {
		printf("already used");
	}
	else {
		E[Echeckuse] = x;
		EcheckInsert[Echeckuse] = x;
		Echeckuse++;
		checkuse[x] = 1;
	}
}
void Winsert(int x) {
	int flag = 0;
	if (checkuse[x] == 1) {
		printf("already used");
	}
	else {
		W[Wcheckuse] = x;
		WcheckInsert[Wcheckuse] = x;
		Wcheckuse++;
		checkuse[x] = 1;
	}
}


void Nhandreset() {
	for (int i = 0; i < 13; i++) {
		checkuse[N[i]] = 0;
		N[i] = 100;
	}
	for (int i = 0; i < Ncheckuse; i++) {
		N[i] = NcheckInsert[i];
		checkuse[N[i]] = 1;
	}
}

void Shandreset() {
	for (int i = 0; i < 13; i++) {
		checkuse[S[i]] = 0;
		S[i] = 100;
	}
	for (int i = 0; i < Scheckuse; i++) {
		S[i] = ScheckInsert[i];
		checkuse[S[i]] = 1;
	}
}

void Ehandreset() {
	for (int i = 0; i < 13; i++) {
		checkuse[E[i]] = 0;
		E[i] = 100;
	}
	for (int i = 0; i < Echeckuse; i++) {
		E[i] = EcheckInsert[i];
		checkuse[E[i]] = 1;
	}
}

void Whandreset() {
	for (int i = 0; i < 13; i++) {
		checkuse[W[i]] = 0;
		W[i] = 100;
	}
	for (int i = 0; i < Wcheckuse; i++) {
		W[i] = WcheckInsert[i];
		checkuse[W[i]] = 1;
	}
}

void Nshape(){
	int a,b,c;
	printf("Which?\n0:S 1:H 2:D 3:C\n");
	scanf("%d", &a);
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Nshapevec[b][a] = c;
}
void Sshape(){
	int a, b, c;
	printf("Which?\n0:S 1:H 2:D 3:C\n");
	scanf("%d", &a);
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Sshapevec[b][a] = c;
}

void Eshape(){
	int a, b, c;
	printf("Which?\n0:S 1:H 2:D 3:C\n");
	scanf("%d", &a);
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Eshapevec[b][a] = c;
}
void Wshape(){
	int a, b, c;
	printf("Which?\n0:S 1:H 2:D 3:C\n");
	scanf("%d", &a);
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Wshapevec[b][a] = c;
}
void Nhcp(){
	int  b,c;
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Nhcpvec[b] = c;
}
void Shcp() {
	int  b, c;
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Shcpvec[b] = c;
}
void Ehcp() {
	int  b, c;
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Ehcpvec[b] = c;
}
void Whcp() {
	int  b, c;
	printf("0:min 1:max\n");
	scanf("%d", &b);
	printf("How many?\n");
	scanf("%d", &c);
	Whcpvec[b] = c;
}









void first_reset() {
	for (int i = 0; i < 52; i++)
		checkuse[i] = 0;
	Ncheckuse = 0;
	Scheckuse = 0;
	Echeckuse = 0;
	Wcheckuse = 0;
	for (int i = 0; i < 13; i++) {
		N[i] = 100;
		S[i] = 100;
		E[i] = 100;
		W[i] = 100;
		NcheckInsert[i]=100;
		ScheckInsert[i]=100;
		EcheckInsert[i]=100;
		WcheckInsert[i]=100;
	}
	for (int i = 0; i < 4; i++) {
		Nshapevec[0][i] = 0;
		Nshapevec[1][i] = 13;
		Sshapevec[0][i] = 0;
		Sshapevec[1][i] = 13;
		Eshapevec[0][i] = 0;
		Eshapevec[1][i] = 13;
		Wshapevec[0][i] = 0;
		Wshapevec[1][i] = 13;
	}
	Nhcpvec[0] = 0;
	Nhcpvec[1] = 40;
	Shcpvec[0] = 0;
	Shcpvec[1] = 40;
	Ehcpvec[0] = 0;
	Ehcpvec[1] = 40;
	Whcpvec[0] = 0;
	Whcpvec[1] = 40;
}
void AllNinsert(){
	int i = 0;
	while (i < 13-Ncheckuse) {
		if (N[i+Ncheckuse] == 100) {
			int r;
			r = genrand_int32() % (51 - 0 + 1) + 0;
			if (checkuse[r] == 0) {
				N[i+Ncheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
void AllSinsert(){
	int i = 0;
	while (i < 13 - Scheckuse) {
		if (S[i + Scheckuse] == 100) {
			int r;
			r = genrand_int32() % (51 - 0 + 1) + 0;
			if (checkuse[r] == 0) {
				S[i+Scheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
void AllEinsert(){
	int i = 0;
	while (i < 13 - Echeckuse) {
		if (E[i + Echeckuse] == 100) {
			int r;
			r = genrand_int32() % (51 - 0 + 1) + 0;
			if (checkuse[r] == 0) {
				E[i+Echeckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
void AllWinsert(){
	int i = 0;
	while (i < 13 - Wcheckuse) {
		if (W[i + Wcheckuse] == 100) {
			int r;
			r = genrand_int32() % (51 - 0 + 1) + 0;
			if (checkuse[r] == 0) {
				W[i+Wcheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}

void AllInsert(){
	AllNinsert();
	AllSinsert();
	AllEinsert();
	AllWinsert();
}

void sort(){
	Nsort();
	Ssort();
	Esort();
	Wsort();
}
void printout(){
	Nprintout();
	WEprintout();
	Sprintout();
}

void Insert(){
	int a;
	int flag = 0;
	while (flag == 0) {
		printf("Where?\n1:N\n2:S\n3:E\n4:W\n");
		scanf("%d", &a);
		printf("What card?\n");
		int b;
		scanf("%d", &b);
		if (a == 1) {
			Ninsert(b);

		}
		else if (a == 2)
			Sinsert(b);

		else if (a == 3)
			Einsert(b);
		else if (a == 4)
			Winsert(b);
		printf("again?\n0:Yes1:No\n");
		scanf("%d", &a);
		if (a == 1)
			break;
	}
}
void handclear() { first_reset(); }
void handreset() {
	Nhandreset();
	Shandreset();
	Ehandreset();
	Whandreset();
}
void condition() {
	int a,b;
	printf("What?\n1:shape 2:HCP\n");
	scanf("%d",&a);
	if (a == 1) {
		printf("Where?\n1:N 2:S 3:E 4:W\n");
		scanf("%d", &b);
		if (b == 1)
			Nshape();
		else if (b == 2)
			Sshape();
		else if (b == 3)
			Eshape();
		else if (b == 4)
			Wshape();
	}
	else if (a == 2) {
		printf("Where?\n1:N 2:S 3:E 4:W");
		scanf("%d", &b);
		if (b == 1)
			Nhcp();
		else if (b == 2)
			Shcp();
		else if (b == 3)
			Ehcp();
		else if (b == 4)
			Whcp();

	}
}

int checkcondition() {
	int cnt=0;
	for (int i = 0; i < 13; i++) 
		if (N[i] / 13 == 0) cnt++;
	if (cnt<Nshapevec[0][0] || cnt>Nshapevec[1][0])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (N[i] / 13 == 1) cnt++;
	if (cnt<Nshapevec[0][1] || cnt>Nshapevec[1][1])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (N[i] / 13 == 2) cnt++;
	if (cnt<Nshapevec[0][2] || cnt>Nshapevec[1][2])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (N[i] / 13 == 3) cnt++;
	if (cnt<Nshapevec[0][3] || cnt>Nshapevec[1][3])
		return 1;									//ここまででNのshapeの確認完了

	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (S[i] / 13 == 0) cnt++;
	if (cnt<Sshapevec[0][0] || cnt>Sshapevec[1][0])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (S[i] / 13 == 1) cnt++;
	if (cnt<Sshapevec[0][1] || cnt>Sshapevec[1][1])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (S[i] / 13 == 2) cnt++;
	if (cnt<Sshapevec[0][2] || cnt>Sshapevec[1][2])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (S[i] / 13 == 3) cnt++;
	if (cnt<Sshapevec[0][3] || cnt>Sshapevec[1][3])
		return 1;									//ここまででSのshapeの確認完了

	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (E[i] / 13 == 0) cnt++;
	if (cnt<Eshapevec[0][0] || cnt>Eshapevec[1][0])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (E[i] / 13 == 1) cnt++;
	if (cnt<Eshapevec[0][1] || cnt>Eshapevec[1][1])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (E[i] / 13 == 2) cnt++;
	if (cnt<Eshapevec[0][2] || cnt>Eshapevec[1][2])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (E[i] / 13 == 3) cnt++;
	if (cnt<Eshapevec[0][3] || cnt>Eshapevec[1][3])
		return 1;									//ここまででEのshapeの確認完了

	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (W[i] / 13 == 0) cnt++;
	if (cnt<Wshapevec[0][0] || cnt>Wshapevec[1][0])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (W[i] / 13 == 1) cnt++;
	if (cnt<Wshapevec[0][1] || cnt>Wshapevec[1][1])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (W[i] / 13 == 2) cnt++;
	if (cnt<Wshapevec[0][2] || cnt>Wshapevec[1][2])
		return 1;
	 cnt = 0;
	for (int i = 0; i < 13; i++)
		if (W[i] / 13 == 3) cnt++;
	if (cnt<Wshapevec[0][3] || cnt>Wshapevec[1][3])
		return 1;									//ここまででWのshapeの確認完了
	cnt = 0;
	for (int i = 0; i < 13; i++)
		if (N[i] % 13 <= 4)cnt = cnt + 4 - N[i] % 13;
	if (cnt<Nhcpvec[0] || cnt>Nhcpvec[1])
		return 1;
	cnt = 0;
	for (int i = 0; i < 13; i++)
		if (S[i] % 13 <= 4)cnt = cnt + 4 - S[i] % 13;
	if (cnt<Shcpvec[0] || cnt>Shcpvec[1])
		return 1;
	cnt = 0;
	for (int i = 0; i < 13; i++)
		if (E[i] % 13 <= 4)cnt = cnt + 4 - E[i] % 13;
	if (cnt<Ehcpvec[0] || cnt>Ehcpvec[1])
		return 1;
	cnt = 0;
	for (int i = 0; i < 13; i++)
		if (W[i] % 13 <= 4)cnt = cnt + 4 - W[i] % 13;
	if (cnt<Whcpvec[0] || cnt>Whcpvec[1])
		return 1;

	return 0;
}

int main() {
	init_genrand((unsigned)time(NULL));
	first_reset();
	int flag = 0;
	int a;
	while (flag == 0) {
		printf("0:output\n1:insert\n2:condition\n3:handclear\n4:bye\n");
		scanf("%d", &a);
		if (a == 0) {
			do {
				handreset();//Insertを守りながらリセット
				AllInsert();
				sort();
			} while (checkcondition() == 1);
			printout();
			handreset();
		}
		else if (a == 1)
			Insert();
		else if (a == 2)
			condition();
		else if (a == 3)
			handclear();
		else if (a == 4)
			flag = 1;
	}
	return 0;
}