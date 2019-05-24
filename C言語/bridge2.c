
#include<stdio.h>
#include<time.h>
#include"MT.h"
int checkuse[52];//そのカードが配られたかを記憶する。0~12がSA~S2。未使用なら0使用中なら1を返す。
int Insertcnt[4];//いくつInsertされたかカウントする。0がNでNSEWの順。方角はこれで統一。
int checkInsert[4][13];//なにがInsertされたかを記憶する。前が方角後ろが識別番号。例えばまず、NにInsertすると[0][0]にInsertされたカードの値が格納され、次にNにInsertされると[0][1]に格納される。
int card[4][13];//配られたカードを記憶する。前が方角後ろが識別番号。checkInsertと同じ要領。なにも記憶されていない時に0を代入するとSAと被るので何も入っていない時は100を入れる。実はcheckInsertでも同様。
int shapevec[4][2][4];//shapeの条件を記憶する。前から順に方角、最小or最大(0がmin,1がmax),suit(0からSHDCの順),つまり[0][0][0]にはNの最小のSの枚数が記憶される。
int hcpvec[4][2];//hcpの条件を記憶する。前が方角うしろがmax or min,shapevecと同じ要領。

void first_reset() {			//全てをリセットする関数
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


void handreset() {			//Insertされたものを守りながらリセット。具体的には一旦全部消してcheckInsertに格納されていたものを代入し直す。
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

void printchange(int x) {//数字を文字に変換して出力する関数。
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

void printout() {		//いい感じにNSEWのハンドを出力する関数。前述のprintchangeを使用。card[i][]はソートされている前提。
	printf("\t\tN\n\t\t");
	int i, j;
	for (i = 0; i < 13; i++) {
		if (card[0][i] < 13)
			printchange(card[0][i]);
		else break;
	}
	printf("\n\t\t");
	for (i; i < 13; i++) {//i=0となってないのは仕様。上のfor文でSの個数が記憶されているのでそこからスタートするとうまくHが出力できる。
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
	//ここまででNの出力
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
	//ここまででW-Eの出力（WEは位置の関係上並行して出力しなければならない)
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
	//Sの出力。
}

void Allinsert() {//残っているカードを全部配る関数。Insercntのお陰でInsertされた方角があってもInsertされた回数分配る枚数を減らすことができる。
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

void sort() {//ソート関数。card[i][0]からcard[i][12]までを0が小さく12が大きくなるように並べ替える(i=0~3)
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

void insert(int a, int b) {//次のInsertに使う関数。実際にInsertするのはここ。引数に方角とInsertされるカードを持つ。
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

void Insert() {//Insertモードに入った時のアナウンスや、方角、具体的なカードの入力を受け付ける。
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

void shape(int b) {//後述のcondition()で使用。shapeの条件指定をする関数。引数に方角を持つ。
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

void hcp(int b) {//shape()のhcpバージョン
	int c, d;
	printf("min?\n");
	scanf("%d", &c);
	printf("max?\n");
	scanf("%d", &d);
	hcpvec[b][0] = c;
	hcpvec[b][1] = d;
}

void condition() {//conditionモードで使用する関数。

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

int checkcondition() {//条件を確認する関数。満たしていれば0を、満たしていなければ1を返す。
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
			handreset();//ここで一旦リセットしておかないと、次にInsertする時にalready usedになってしまう。
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


