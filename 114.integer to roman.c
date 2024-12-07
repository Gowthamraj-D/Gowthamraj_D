void romanizer(int num, int digit, char * roman);

char * intToRoman(int num) {

	char roman[20] = "";

	if(num > 999) {
		if(num / 1000 == 3) {
			strcpy(roman, "MMM");
		} else if(num / 1000 == 2) {
			strcpy(roman, "MM");
		} else {
			strcpy(roman, "M");
		}
		num -= (num/1000) * 1000;
	}
	if(num > 99) {
		romanizer(num / 100, 3, roman);
		num -= (num/100) * 100;
	}
	if(num > 9) {
		romanizer(num / 10, 2, roman);
		num -= (num/10) * 10;
	}
	if (num > 0) {
		romanizer(num, 1, roman);
	}

	register unsigned char rom_len = strlen(roman);
	char * rom_res = (char*)malloc(rom_len * sizeof(char) + 1);
	strcpy(rom_res, roman);

	return rom_res;
}

void romanizer(int num, int digit, char * roman) {
	char ones[10][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	char tens[10][5] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	char tons[10][5] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

	if(digit == 3) {
		strcat(roman, tons[num-1]);
	} else if (digit == 2) {
		strcat(roman, tens[num-1]);
	} else {
		strcat(roman, ones[num-1]);
	}
}
