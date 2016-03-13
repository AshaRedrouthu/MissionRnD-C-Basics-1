int valid(int d, int m, int y){

	int d1;
	if (m < 1 ||  m > 12)
		return -1;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		d1 = 30;
	else if (m == 2) {
		if (y % 4)
			d1 = 28;
		else
			d1 = 29;
	}
	else
		d1 = 31;
	return d <= d1 ? 1:-1;
}





int length(char *str) {
	int i = 0;
	while (*(str + i) != '\0')
		i++;
	return i;
}

int isOlder(char *dob1, char *dob2) {

	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, i = 0;

	if (length(dob1) != 10 && length(dob2) != 10)
		return -1;
	while (*(dob1 + i) != '-' && i < 2) {

		d1 = (d1 * 10) + (*(dob1 + i) - '0');
		d2 = (d2 * 10) + (*(dob2 + i) - '0');
		i++;
	}
	i++;
	while (*(dob1 + i) != '-' && i < 5) {

		m1 = (m1 * 10) + (*(dob1 + i) - '0');
		m2 = (m2 * 10) + (*(dob2 + i) - '0');
		i++;
	}
	i++;
	while (*(dob1 + i) != '\0' && i <= 9) {

		y1 = (y1 * 10) + (*(dob1 + i) - '0');
		y2 = (y2 * 10) + (*(dob2 + i) - '0');
		i++;
	}

	if (valid(d1, m1, y1) == -1 || valid(d2, m2, y2) == -1) {
		return -1;
	}


		if (y1 < y2)
			return 1;
		else if (y1 > y2)
			return 2;
		else if (y1 == y2) {

			if (m1 < m2)
				return 1;
			else if (m1 > m2)
				return 2;
			else if (m1 == m2) {

				if (d1 < d2)
					return 1;
				else if (d1 > d2)
					return 2;
				else
					return 0;
			}


		}
	
	

	return 0;
}




