#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
	


int main(){
	double income;
	cout << "Income: ";
	cin >> income;
	string prov;
	cout << "Province: ";
	cin >> prov;

	double taxDeduct = 11635 + 6000;

	if (income < taxDeduct) {
		cout << "Net Income: " << income << endl;
		return 0;
	}

	double f[4];
	double fr[5];

	f[0] = 45916;
	fr[0] = 0.15;
	f[1] = 45915;
	fr[1] = 0.205;
	f[2] = 50522;
	fr[2] = 0.26;
	f[3] = 60447;
	fr[3] = 0.29;
	fr[4] = 0.33;
	double ftax = 0;

	double fincome = income;

	for (int i=0;i<=4;i++) {
		if (fincome < f[i] || i == 4) {
			ftax += fincome*fr[i];
			break;
		} else {
			ftax += f[i]*fr[i];
			fincome -= f[i];
		}
	}

	double p[4];
	double pr[5];

	if (prov == "BC") {
		p[0] = 38898;
		pr[0] = 0.0506;
		p[1] = 38899;
		pr[1] = 0.077;
		p[2] = 11523;
		pr[2] = 0.105;
		p[3] = 19140;
		pr[3] = 0.1229;
		pr[4] = 0.147;
	} else if (prov == "ON") {
		p[0] = 42201;
		pr[0] = 0.0505;
		p[1] = 42203;
		pr[1] = 0.0915;
		p[2] = 65596;
		pr[2] = 0.1116;
		p[3] = 70000;
		pr[3] = 0.1216;
		pr[4] = 0.1316;
	}
	
	double ptax = 0;

	double pincome = income;

	for (int i=0;i<=4;i++) {
		if (pincome < p[i] || i == 4) {
			ptax += pincome*pr[i];
			break;
		} else {
			ptax += p[i]*pr[i];
			pincome -= p[i];
		}
	}

	ftax -= taxDeduct*fr[0];
	ptax -= taxDeduct*pr[0];

	double nettax = ftax+ptax;
	double netincome = income - nettax;

	cout << "Federal Tax: " << ftax << endl;
	cout << "Provincial Tax: " << ptax << endl;
	cout << "Net Tax: " << nettax << endl;

	cout << "Net Income: " << netincome << endl;

	return 0;
}
