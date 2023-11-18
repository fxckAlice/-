#pragma once
#include <string>
#include <math.h>

class CodesOFHamming
{
public:
	bool powOfTwo(double parameter) {
		do {
			if (parameter == 1)return true;
			parameter /= 2;
		} while (parameter >= 1);
		return false;
	}


	std::string toBinary(int number) {
		int checker = 0;
		std::string answer = "";
		do {
			checker++;
		} while (pow(2, checker) <= number);
		for (int i = 0; i <= checker - 1;) {
			checker--;
			if (number >= pow(2, checker))
			{
				answer += "1";
				number -= pow(2, checker);
			}
			else answer += "0";

		}
		return answer;
	}

	std::string stageOfBinary(string parameter, int stage) {
		if (parameter.length() > stage) {
			return parameter;
		}
		else if (parameter.length() == stage) {
			return parameter;
		}
		else {
			string temp = parameter;
			parameter = "";
			for (int i = 0; i < (stage - temp.length()); i++) {
				parameter += "0";
			}
			parameter += temp;
			return parameter;
		}
	}

	std::string coding(std::string input) {
		std::string binaryOutput;

		int inputLenghth = (int)(input.length());
		int verificationCodes = (int)(log2((inputLenghth + 1.0) + log2(inputLenghth + 1.0)) + 1);
		int lengthOfCode = verificationCodes + inputLenghth;

		int* verificationCodesArray = new int[verificationCodes];
		char *binaryCodes = new char[lengthOfCode];

		//for(){}


		int check = 0;
		for (int i = 0; i < lengthOfCode; i++)
		{
			if (!powOfTwo(i + 1)) {
				binaryCodes[i] = input[check];
				check++;
			}
		}
		int pos = 0;
		for (int i = lengthOfCode - 1; i >= 0; i--) {
			if (powOfTwo(i + 1)) {
				for (int o = 1; o <= lengthOfCode; o++) {
					if (!powOfTwo(o) && stageOfBinary(toBinary(o), verificationCodes)[pos] == '1') {
						verificationCodesArray[pos]++;
					}
				}
				if (verificationCodesArray[pos] % 2 == 1)binaryCodes[i] = '1';
				else binaryCodes[i] = '0';
				pos++;
			}
		}
		for (int i = 0; i < lengthOfCode; i++) {
			binaryOutput[i] = binaryCodes[i];
		}
		delete[] binaryCodes;
		return binaryOutput;
	}
protected:
};

