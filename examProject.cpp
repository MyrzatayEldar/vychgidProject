#include<cmath>
#include<iostream>
using namespace std;

int main()
{

	double	Hhh = 0.3, ddxx = 0.01, ddtt = 0.01;
	double XX[50], MUu[50][50],
		MUu1[50][50], MU2[50][50],
		MU[50][50];
	int NN = 30, i, j;


	for (int i = 0; i < NN + 1; i++) {
		XX[i] = i * Hhh;
	}
	//shekaralyq sharttar
	for (int j = 0; j < NN + 1; j++) {
		for (int i = 0; i < NN + 1; i++) {
			if (XX[i] >= 0 and XX[i] <= 1)
				MU[i][0] = 0.75;
			if (XX[i] >= 1 and XX[i] <= 2)
				MU[i][0] = 1;
			if (XX[i] >= 2 and XX[i] <= 3)
				MU[i][0] = 0.5;
		}
	}
	for (int j = 1; j < NN + 1; j++) {
		for (i = 1; i < NN + 1; i++)
		{
			MUu1[i + 1][j + 1 / 2] = (1 / 2) * (MU[i][j + 1] + MU[i][j]) - (1 / 3) * (ddtt / ddxx) * (((MU[i][j + 1]) * (MU[i][j + 1])) / 2 - 0.5 * ((MU[i][j]) * (MU[i][j])) / 2);
			for (j = 1; j < NN; j++)
			{
				MU2[i + 1][j] = MU[i][j] - (2 / 3) * (ddtt / ddxx) * (0.5 * ((MUu1[i][j + 1 / 2]) * (MUu1[i][j + 1 / 2]) / 2) - 0.5 * ((MUu1[i][j - 1 / 2]) * (MUu1[i][j - 1 / 2])) / 2);
			}
			for (j = 1; j < NN; j++)
			{
				MUu[i][j] = MU[i][j];
			}
			for (j = 1; j < NN; j++)
			{
				MUu[i][j] = MU[i][j] - (1 / 24) * (ddtt / ddxx) * (-(2) * ((MU[i][j + 2]) * (MU[i][j + 2]) / 2) + 7 * ((MU[i][j + 1]) * (MU[i][j + 1]) / 2) - 7 * ((MU[i][j - 1]) * (MU[i][j - 1])) + 2 * ((MU[i][j - 2]) * (MU[i][j - 2]))) - (3 / 8) * (ddtt / ddxx) * (0.5 * ((MU2[i + 1][j + 1]) * (MU2[i + 1][j + 1])) - 0.5 * ((MU2[i + 1][j - 1]) * (MU2[i + 1][j - 1]))) - (1 / 24) * (MU[i][j + 2] - 4 * MU[i][j + 1] + 6 * MU[i][j] - 4 * MU[i][j - 1] + MU[i][j - 2]);
			}
			for (j = 1; j < NN; j++) {
				MU[i][j] = MUu[i][j];
			}
		}
	}

}


