#include <stdio.h>
#include "memwrap.h"

void expect(const char *s, int got, int exp) {
	if(got != exp) {
		printf("%s FAILED exp %d got %d\n", s, exp, got);
	} else {
		printf("%s Passed exp %d got %d\n", s, exp, got);
	}
}

int main() {
	void *p1, *p2, *p3, *p4;

	p4 = apparate(40000);
	p3 = apparate(3000);
	p2 = apparate(200);
	p1 = apparate(10);
	expect("1: BLK CHECK", totalBlocks(), 4);
	expect("2: SIZ CHECK", totalBytes(), 43210);


	reducto(p1);
	expect("3: BLK CHECK", totalBlocks(), 3);
	expect("4: SIZ CHECK", totalBytes(), 43200);

	reducto(p2);
	expect("5: BLK CHECK", totalBlocks(), 2);
	expect("6: SIZ CHECK", totalBytes(), 43000);

	reducto(p3);
	expect("7: BLK CHECK", totalBlocks(), 1);
	expect("8: SIZ CHECK", totalBytes(), 40000);
	expect("9: DIS CHECK", reducto((void *)0x1abcdef), 0);

	reducto(p4);
	expect("10: BLK CHECK", totalBlocks(), 0);
	expect("11: SIZ CHECK", totalBytes(), 0);

	p4 = apparate(80000);
	p3 = apparate(7000);
	p2 = apparate(600);
	p1 = apparate(50);
	expect("12: BLK CHECK", totalBlocks(), 4);
	expect("13: SIZ CHECK", totalBytes(), 87650);

	reductoMaximo();
	expect("14: BLK CHECK", totalBlocks(), 0);
	expect("15: SIZ CHECK", totalBytes(), 0);

	//add more tests
}
