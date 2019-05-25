let checkuse = new Array(52);
let Insertcnt = new Array(4);
let checkInsert = new Array(4);
let card = new Array(4);
let shapevec = []
let hcpvec = new Array(4);
let toInsrty = new Array(4);

let precheckInsert;
let preshapevec;
let prehcpvec;

function chk_inbox(i, val) {
	if (i == '-') return val;
	else return Number(i);
}

function sort() {
	for (let i = 0; i < 4; ++i) {
		card[i].sort(function (a, b) {
			a = Number(a);
			b = Number(b);
			if (a > b) return 1;
			return -1;
		});
	}
}

function NumToAKQ(x) {
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

function AKQtoNum(x) {
	if (x == 'A') return 0;
	if (x == 'K') return 1;
	if (x == 'Q') return 2;
	if (x == 'J') return 3;
	if (x == 'T') return 4;
	return 14 - Number(x);
}

function Nprintout() {
	let toPrint = new Array("", "", "", "");
	for (let i = 0; i < 13; ++i) {
		toPrint[Math.floor(card[0][i] / 13)] += NumToAKQ(card[0][i]);
	}
	for (let i = 0; i < 4; ++i) {
		if (toPrint[i].length == 0) toPrint[i] = '-';
		$('[name="NSuit"]').eq(i).append(toPrint[i]);
	}
}
function Sprintout() {
	let toPrint = new Array("", "", "", "");
	for (let i = 0; i < 13; ++i) {
		toPrint[Math.floor(card[1][i] / 13)] += NumToAKQ(card[1][i]);
	}
	for (let i = 0; i < 4; ++i) {
		if (toPrint[i].length == 0) toPrint[i] = '-';
		$('[name="SSuit"]').eq(i).append(toPrint[i]);
	}
}
function Eprintout() {
	let toPrint = new Array("", "", "", "");
	for (let i = 0; i < 13; ++i) {
		toPrint[Math.floor(card[2][i] / 13)] += NumToAKQ(card[2][i]);
	}
	for (let i = 0; i < 4; ++i) {
		if (toPrint[i].length == 0) toPrint[i] = '-';
		$('[name="ESuit"]').eq(i).append(toPrint[i]);
	}
}
function Wprintout() {
	let toPrint = new Array("", "", "", "");
	for (let i = 0; i < 13; ++i) {
		toPrint[Math.floor(card[3][i] / 13)] += NumToAKQ(card[3][i]);
	}
	for (let i = 0; i < 4; ++i) {
		if (toPrint[i].length == 0) toPrint[i] = '-';
		$('[name="WSuit"]').eq(i).append(toPrint[i]);
	}
}

function printout() {
	Nprintout();
	Sprintout();
	Eprintout();
	Wprintout();
}

function insert(a, b) {
	if (checkuse[b] == 1) return false;
	card[a][Insertcnt[a]] = b;
	checkInsert[a][Insertcnt[a]] = b;
	Insertcnt[a]++;
	checkuse[b] = 1;
	return true;
}

function handreset() {
	for (let j = 0; j < 4; j++) {
		for (let i = 0; i < 13; i++) {
			checkuse[card[j][i]] = 0;
			card[j][i] = 100;
		}
		for (let i = 0; i < Insertcnt[j]; i++) {
			card[j][i] = checkInsert[j][i];
			checkuse[card[j][i]] = 1;
		}
	}
}

function shape() {
	for (let i = 0; i < 4; ++i) {
		for (let j = 0; j < 4; ++j) {
			shapevec[i][0][j] = chk_inbox(hand_input.Min[i * 4 + j].value, 0);
			shapevec[i][1][j] = chk_inbox(hand_input.Max[i * 4 + j].value, 13);
		}
	}
}

function hcp() {
	for (let i = 0; i < 4; ++i) {
		hcpvec[i][0] = chk_inbox(hand_input.hcpMin[i].value, 0);
		hcpvec[i][1] = chk_inbox(hand_input.hcpMax[i].value, 40);
	}
}

function first_reset() {
	$('.text').text("");
	for (let i = 0; i < 52; i++) {
		checkuse[i] = 0;
	}
	hcpvec = [[], [], [], []];
	for (let i = 0; i < 4; ++i) {
		Insertcnt[i] = 0;
		hcpvec[i][0] = 0;
		hcpvec[i][1] = 40;
	}

	for (let i = 0; i < 4; ++i) {
		card[i] = new Array(13);
		checkInsert[i] = new Array(13);
		for (let j = 0; j < 13; ++j) {
			card[i][j] = 100;
			checkInsert[i][j] = 100;
		}
	}
	shapevec = [[], [], [], []]

	for (let i = 0; i < 4; i++) {
		shapevec[i].push([0, 0, 0, 0]);
		shapevec[i].push([13, 13, 13, 13]);
	}
}

function Allinsert() {
	for (let j = 0; j < 4; j++) {
		let i = 0;
		while (i < 13 - Insertcnt[j]) {
			if (card[j][i + Insertcnt[j]] == 100) {
				let r;
				r = Math.floor(Math.random() * 52);
				if (checkuse[r] == 0) {
					card[j][i + Insertcnt[j]] = r;
					checkuse[r] = 1;
					i++;
				}
			}
			else i++;
		}
	}
}

function Insert() {
	let flag = true;
	for (let k = 0; k < 4; ++k) {
		for (let i = 0; i < 4; i++) {
			let string = hand_input.Card[4 * k + i].value;
			for (let j = 0; j < string.length; ++j) {
				flag &= insert(k, 13 * i + AKQtoNum(string[j]));
			}
		}
	}
	return flag;
}

function checkcondition() {
	for (let j = 0; j < 4; j++) {
		let cnt = 0;
		for (let i = 0; i < 13; i++)
			if (Math.floor(card[j][i] / 13) == 0) cnt++;
		if (cnt < shapevec[j][0][0] || cnt > shapevec[j][1][0])
			return 1;
		cnt = 0;
		for (let i = 0; i < 13; i++)
			if (Math.floor(card[j][i] / 13) == 1) cnt++;
		if (cnt < shapevec[j][0][1] || cnt > shapevec[j][1][1])
			return 1;
		cnt = 0;
		for (let i = 0; i < 13; i++)
			if (Math.floor(card[j][i] / 13) == 2) cnt++;
		if (cnt < shapevec[j][0][2] || cnt > shapevec[j][1][2])
			return 1;
		cnt = 0;
		for (let i = 0; i < 13; i++)
			if (Math.floor(card[j][i] / 13) == 3) cnt++;
		if (cnt < shapevec[j][0][3] || cnt > shapevec[j][1][3])
			return 1;
		cnt = 0;
		for (let i = 0; i < 13; i++)
			if (card[j][i] % 13 <= 4) cnt = cnt + 4 - card[j][i] % 13;
		if (cnt < hcpvec[j][0] || cnt > hcpvec[j][1])
			return 1;
	}
	return 0;
}

function counter_up() {
	let times = Number($('#times').text());
	times++;
	$('#times').text(times);
}

function save_condition() {
	precheckInsert = checkInsert;
	preshapevec = shapevec;
	prehcpvec = hcpvec;
}

function is_changed() {
	if (JSON.stringify(precheckInsert) !== JSON.stringify(checkInsert)) return true;
	if (JSON.stringify(preshapevec) !== JSON.stringify(shapevec)) return true;
	if (JSON.stringify(prehcpvec) !== JSON.stringify(hcpvec)) return true;
	return false;
}

function main() {
	let flag = false;
	counter_up();
	first_reset();
	shape();
	hcp();
	if (is_changed()) {
		$('#sikouID').text(Math.floor(Math.random() * 100000));
		$('#times').text(1);
	} 
	if (!Insert()) {
		$('#error').text("挿入したカードに重複があります．");
		return;
	}
	else $('#error').text("");
	save_condition();
	var start = new Date();
	start = start.getTime();
	while (true) {
		handreset();//Insertを守りながらリセット
		Allinsert();
		sort();
		now = new Date();
		now = now.getTime();
		if (now - start > 5000) break;
		if (checkcondition() == 0) { flag = true; break; }
	}
	if (flag) {
		printout();
	}
	else {
		$('#error').text("やめて，いぢめないで．条件が厳しすぎます．");
	}
}

function dds(){
	let dds_url="http://www.danvk.org/bridge/?deal=N:";
	for(let i=0;i<4;++i){
		let incard=["","","",""];
		for(let j=0;j<13;++j){
			incard[Math.floor(card[i][j]/13)]+=NumToAKQ(card[i][j])
		}
		for(let i=0;i<4;++i){
			dds_url+=incard[i];
			dds_url+=i===3?" ":".";
		}
	}
	console.log(dds_url);
	window.open(dds_url,'_blank');
}