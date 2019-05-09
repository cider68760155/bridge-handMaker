let checkuse = new Array(52);
let Ncheckuse;
let Scheckuse;
let Echeckuse;
let Wcheckuse;//使用済みの個数
let NcheckInsert = new Array(13);
let ScheckInsert = new Array(13);
let EcheckInsert = new Array(13);
let WcheckInsert = new Array(13);//Insertしたカード
let N = new Array(13);
let S = new Array(13);
let E = new Array(13);
let W = new Array(13);
let Nshapevec = [];
let Sshapevec = [];
let Eshapevec = [];
let Wshapevec = [];//前0:min 1:max 後:suit 0がS
let Nhcpvec = Array(2);
let Shcpvec = Array(2);
let Ehcpvec = Array(2);
let Whcpvec = Array(2);//0:min 1:max

function printf(s) {
	$('#result').append(s);
}

function chk_inbox(i, val) {
	if (i == '-') return val;
	else return Number(i);
}

function Nsort() {
	let i, j, tmp;
	for (i = 0; i < 13; ++i) {
		for (j = i + 1; j < 13; ++j) {
			if (N[i] > N[j]) {
				tmp = N[i];
				N[i] = N[j];
				N[j] = tmp;
			}
		}
	}
}

function Ssort() {
	let i, j, tmp;
	for (i = 0; i < 13; ++i) {
		for (j = i + 1; j < 13; ++j) {
			if (S[i] > S[j]) {
				tmp = S[i];
				S[i] = S[j];
				S[j] = tmp;
			}
		}
	}
}

function Esort() {
	let i, j, tmp;
	for (i = 0; i < 13; ++i) {
		for (j = i + 1; j < 13; ++j) {
			if (E[i] > E[j]) {
				tmp = E[i];
				E[i] = E[j];
				E[j] = tmp;
			}
		}
	}
}

function Wsort() {
	let i, j, tmp;
	for (i = 0; i < 13; ++i) {
		for (j = i + 1; j < 13; ++j) {
			if (W[i] > W[j]) {
				tmp = W[i];
				W[i] = W[j];
				W[j] = tmp;
			}
		}
	}
}

function printchange(x) {
	if (x % 13 == 0) return "A";
	if (x % 13 == 1) return "K";
	if (x % 13 == 2) return "Q";
	if (x % 13 == 3) return "J";
	if (x % 13 == 4) return "T";
	if (x % 13 == 5) return "9";
	if (x % 13 == 6) return "8";
	if (x % 13 == 7) return "7";
	if (x % 13 == 8) return "6";
	if (x % 13 == 9) return "5";
	if (x % 13 == 10) return "4";
	if (x % 13 == 11) return "3";
	if (x % 13 == 12) return "2";
}

function Nprintout() {
	for (let i = 0; i < 13; ++i)
		$('[name="NSuit"]').eq(Math.floor(N[i] / 13)).append(printchange(N[i]));
}
function Sprintout() {
	for (let i = 0; i < 13; ++i)
		$('[name="SSuit"]').eq(Math.floor(S[i] / 13)).append(printchange(S[i]));
}
function Eprintout() {
	for (let i = 0; i < 13; ++i)
		$('[name="ESuit"]').eq(Math.floor(E[i] / 13)).append(printchange(E[i]));
}
function Wprintout() {
	for (let i = 0; i < 13; ++i)
		$('[name="WSuit"]').eq(Math.floor(W[i] / 13)).append(printchange(W[i]));
}

function WEprintout() {
	printf("W\t\t\t\tE\n");
	let i, j;
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

function Ninsert(x) {
	let flag = 0;
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
function Sinsert(x) {
	let flag = 0;
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
function Einsert(x) {
	let flag = 0;
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
function Winsert(x) {
	let flag = 0;
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


function Nhandreset() {
	for (let i = 0; i < 13; i++) {
		checkuse[N[i]] = 0;
		N[i] = 100;
	}
	for (let i = 0; i < Ncheckuse; i++) {
		N[i] = NcheckInsert[i];
		checkuse[N[i]] = 1;
	}
}

function Shandreset() {
	for (let i = 0; i < 13; i++) {
		checkuse[S[i]] = 0;
		S[i] = 100;
	}
	for (let i = 0; i < Scheckuse; i++) {
		S[i] = ScheckInsert[i];
		checkuse[S[i]] = 1;
	}
}

function Ehandreset() {
	for (let i = 0; i < 13; i++) {
		checkuse[E[i]] = 0;
		E[i] = 100;
	}
	for (let i = 0; i < Echeckuse; i++) {
		E[i] = EcheckInsert[i];
		checkuse[E[i]] = 1;
	}
}

function Whandreset() {
	for (let i = 0; i < 13; i++) {
		checkuse[W[i]] = 0;
		W[i] = 100;
	}
	for (let i = 0; i < Wcheckuse; i++) {
		W[i] = WcheckInsert[i];
		checkuse[W[i]] = 1;
	}
}

function Nshape() {
	for (let i = 0; i < 4; i++) {
		Nshapevec[0][i] = chk_inbox(hand_input.NMin[i].value, 0);
		Nshapevec[1][i] = chk_inbox(hand_input.NMax[i].value, 13);
	}
}
function Sshape() {
	for (let i = 0; i < 4; i++) {
		Sshapevec[0][i] = chk_inbox(hand_input.SMin[i].value, 0);
		Sshapevec[1][i] = chk_inbox(hand_input.SMax[i].value, 13);
	}
}

function Eshape() {
	for (let i = 0; i < 4; i++) {
		Eshapevec[0][i] = chk_inbox(hand_input.EMin[i].value, 0);
		Eshapevec[1][i] = chk_inbox(hand_input.EMax[i].value, 13);
	}
}
function Wshape() {
	for (let i = 0; i < 4; i++) {
		Wshapevec[0][i] = chk_inbox(hand_input.WMin[i].value, 0);
		Wshapevec[1][i] = chk_inbox(hand_input.WMax[i].value, 13);
	}
}
function Nhcp() {
	Nhcpvec[0] = chk_inbox(hand_input.NhcpMin.value, 0);
	Nhcpvec[1] = chk_inbox(hand_input.NhcpMax.value, 40);
}
function Shcp() {
	Shcpvec[0] = chk_inbox(hand_input.ShcpMin.value, 0);
	Shcpvec[1] = chk_inbox(hand_input.ShcpMax.value, 40);
}
function Ehcp() {
	Ehcpvec[0] = chk_inbox(hand_input.EhcpMin.value, 0);
	Ehcpvec[1] = chk_inbox(hand_input.EhcpMax.value, 40);
}
function Whcp() {
	Whcpvec[0] = chk_inbox(hand_input.WhcpMin.value, 0);
	Whcpvec[1] = chk_inbox(hand_input.WhcpMax.value, 40);
}

function first_reset() {
	$('.text').text("");
	for (let i = 0; i < 52; i++)
		checkuse[i] = 0;
	Ncheckuse = 0;
	Scheckuse = 0;
	Echeckuse = 0;
	Wcheckuse = 0;
	for (let i = 0; i < 13; i++) {
		N[i] = 100;
		S[i] = 100;
		E[i] = 100;
		W[i] = 100;
		NcheckInsert[i] = 100;
		ScheckInsert[i] = 100;
		EcheckInsert[i] = 100;
		WcheckInsert[i] = 100;
	}
	for (let i = 0; i < 4; i++) {
		Nshapevec = [];
		Sshapevec = [];
		Eshapevec = [];
		Wshapevec = [];
		Nshapevec.push([0, 0, 0, 0]);
		Nshapevec.push([13, 13, 13, 13]);
		Sshapevec.push([0, 0, 0, 0]);
		Sshapevec.push([13, 13, 13, 13]);
		Eshapevec.push([0, 0, 0, 0]);
		Eshapevec.push([13, 13, 13, 13]);
		Wshapevec.push([0, 0, 0, 0]);
		Wshapevec.push([13, 13, 13, 13]);
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
function AllNinsert() {
	let i = 0;
	while (i < 13 - Ncheckuse) {
		if (N[i + Ncheckuse] == 100) {
			let r;
			r = Math.floor(Math.random() * 52);
			if (checkuse[r] == 0) {
				N[i + Ncheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
function AllSinsert() {
	let i = 0;
	while (i < 13 - Scheckuse) {
		if (S[i + Scheckuse] == 100) {
			let r;
			r = Math.floor(Math.random() * 52);
			if (checkuse[r] == 0) {
				S[i + Scheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
function AllEinsert() {
	let i = 0;
	while (i < 13 - Echeckuse) {
		if (E[i + Echeckuse] == 100) {
			let r;
			r = Math.floor(Math.random() * 52);
			if (checkuse[r] == 0) {
				E[i + Echeckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}
function AllWinsert() {
	let i = 0;
	while (i < 13 - Wcheckuse) {
		if (W[i + Wcheckuse] == 100) {
			let r;
			r = Math.floor(Math.random() * 52);
			if (checkuse[r] == 0) {
				W[i + Wcheckuse] = r;
				checkuse[r] = 1;
				i++;
			}
		}
		else
			i++;
	}
}

function AllInsert() {
	AllNinsert();
	AllSinsert();
	AllEinsert();
	AllWinsert();
}

function sort() {
	Nsort();
	Ssort();
	Esort();
	Wsort();
}
function printout() {
	Nprintout();
	Sprintout();
	Eprintout();
	Wprintout();
}
/*
function Insert() {
	let a;
	let flag = 0;
	while (flag == 0) {
		printf("Where?\n1:N\n2:S\n3:E\n4:W\n");
		scanf("%d", & a);
		printf("What card?\n");
		let b;
		scanf("%d", & b);
		if (a == 1)
			Ninsert(b);
		else if (a == 2)
			Sinsert(b);

		else if (a == 3)
			Einsert(b);
		else if (a == 4)
			Winsert(b);
		printf("again?\n0:Yes1:No\n");
		scanf("%d", & a);
		if (a == 1)
			break;
	}
}
*/
function handclear() { first_reset(); }
function handreset() {
	Nhandreset();
	Shandreset();
	Ehandreset();
	Whandreset();
}
function condition() {
	Nshape();
	Sshape();
	Eshape();
	Wshape();
	Nhcp();
	Shcp();
	Ehcp();
	Whcp();

}

function checkcondition() {
	let cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(N[i] / 13) == 0) cnt++;
	if (cnt < Nshapevec[0][0] || cnt > Nshapevec[1][0])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(N[i] / 13) == 1) cnt++;
	if (cnt < Nshapevec[0][1] || cnt > Nshapevec[1][1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(N[i] / 13) == 2) cnt++;
	if (cnt < Nshapevec[0][2] || cnt > Nshapevec[1][2])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(N[i] / 13) == 3) cnt++;
	if (cnt < Nshapevec[0][3] || cnt > Nshapevec[1][3])
		return 1;									//ここまででNのshapeの確認完了

	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(S[i] / 13) == 0) cnt++;
	if (cnt < Sshapevec[0][0] || cnt > Sshapevec[1][0])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(S[i] / 13) == 1) cnt++;
	if (cnt < Sshapevec[0][1] || cnt > Sshapevec[1][1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(S[i] / 13) == 2) cnt++;
	if (cnt < Sshapevec[0][2] || cnt > Sshapevec[1][2])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(S[i] / 13) == 3) cnt++;
	if (cnt < Sshapevec[0][3] || cnt > Sshapevec[1][3])
		return 1;									//ここまででSのshapeの確認完了

	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(E[i] / 13) == 0) cnt++;
	if (cnt < Eshapevec[0][0] || cnt > Eshapevec[1][0])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(E[i] / 13) == 1) cnt++;
	if (cnt < Eshapevec[0][1] || cnt > Eshapevec[1][1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(E[i] / 13) == 2) cnt++;
	if (cnt < Eshapevec[0][2] || cnt > Eshapevec[1][2])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(E[i] / 13) == 3) cnt++;
	if (cnt < Eshapevec[0][3] || cnt > Eshapevec[1][3])
		return 1;									//ここまででEのshapeの確認完了

	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(W[i] / 13) == 0) cnt++;
	if (cnt < Wshapevec[0][0] || cnt > Wshapevec[1][0])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(W[i] / 13) == 1) cnt++;
	if (cnt < Wshapevec[0][1] || cnt > Wshapevec[1][1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(W[i] / 13) == 2) cnt++;
	if (cnt < Wshapevec[0][2] || cnt > Wshapevec[1][2])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (Math.floor(W[i] / 13) == 3) cnt++;
	if (cnt < Wshapevec[0][3] || cnt > Wshapevec[1][3])
		return 1;									//ここまででWのshapeの確認完了
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (N[i] % 13 <= 4) cnt = cnt + 4 - N[i] % 13;
	if (cnt < Nhcpvec[0] || cnt > Nhcpvec[1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (S[i] % 13 <= 4) cnt = cnt + 4 - S[i] % 13;
	if (cnt < Shcpvec[0] || cnt > Shcpvec[1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (E[i] % 13 <= 4) cnt = cnt + 4 - E[i] % 13;
	if (cnt < Ehcpvec[0] || cnt > Ehcpvec[1])
		return 1;
	cnt = 0;
	for (let i = 0; i < 13; i++)
		if (W[i] % 13 <= 4) cnt = cnt + 4 - W[i] % 13;
	if (cnt < Whcpvec[0] || cnt > Whcpvec[1])
		return 1;

	return 0;
}

function main() {
	let flag = false;
	first_reset();
	condition();
	var start = new Date();
	start = start.getTime();
	while (true) {
		handreset();//Insertを守りながらリセット
		AllInsert();
		sort();
		now = new Date();
		now = now.getTime();
		if (now - start > 5000) break;
		if (checkcondition() == 0) { flag = true; break; }
	}
	if (flag) {
		printout();
		handreset();
	}
	else {
		$('#result').html("やめて，いぢめないで．条件が厳しすぎます．")
	}
}