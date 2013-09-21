#include <iostream>
#include <math.h>

using namespace std;

const int SUMS = 60 * 60 * 12;
const double SMPERIOD = 3600 / 59;	// 360 / (59/10)
const int SMN = 708;	//60*60*12/(3600/59) = 12 * 59 = 708
const double SHPERIOD = 43200 / 719;	//360 / (719/120)
const int SHN = 719;	//3600*12 / (43200/719) = 719
const double MHPERIOD = 43200 / 11;	// 360/(11/120)
const int MHN = 11;	//SUMS / MHPERIOD = 11

double min(double a, double b, double c)
{
	double m = a > b ? b : a;
	m = m > c ? c : m;
	return m;
}

double max(double a, double b, double c)
{
	double m = a > b ? a : b;
	m = m > c ? m : c;
	return m;
}

int main()
{
	freopen("in.txt", "r", stdin);

	double degree;
	double sum = 0.0;
	double sm_l[SMN], sm_r[SMN], sh_l[SHN], sh_r[SHN], mh_l[MHN], mh_r[MHN];

	while(scanf("%lf", &degree) != EOF && degree != -1)
	{
		sm_l[0] = (degree * 10) / 59.0;
		sm_r[0] = (3600 - degree * 10) / 59.0;
		for (int i = 1; i < SMN; ++i) {
			sm_l[i] = sm_l[i - 1] + 3600 / 59.0;
			sm_r[i] = sm_r[i - 1] + 3600 / 59.0;
		}

		sh_l[0] = (degree * 120) / 719.0;
		sh_r[0] = (360 - degree)*120 / 719.0;
		for (int i = 1; i < SHN; ++i) {
			sh_l[i] = sh_l[i - 1] + 360 * 120 / 719.0;
			sh_r[i] = sh_r[i - 1] + 360 * 120 / 719.0;
		}

		mh_l[0] = (degree * 120) / 11;
		mh_r[0] = (360 - degree) * 120 / 11;
		for (int i = 1; i < MHN; ++i) {
			mh_l[i] = mh_l[i - 1] + 360 * 120 / 11.0;
			mh_r[i] = mh_r[i - 1] + 360 * 120 / 11.0;
		}

		sum = 0.0;
		int ism = 0, ish = 0, imh = 0;
		double l, r;
		while(ism <= SMN && ish <= SHN && imh <= MHN)
		{
			l = max(sm_l[ism], sh_l[ish], mh_l[imh]);
			r = min(sm_r[ism], sh_r[ish], mh_r[imh]);
			if (l < r) {
				sum += r - l;
			}

			if (r == sm_r[ism]) {
				ism++;
			}
			if (r == sh_r[ish]) {
				ish++;
			}
			if (r == mh_r[imh]) {
				imh++;
			}
		}
		printf("%.3f\n", sum * 100 / SUMS);
	}

	fclose(stdin);
	return 0;
}
