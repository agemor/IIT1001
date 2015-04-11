#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 문제 A
void problemA();
int *genBagNum();
void findMissingNum(int *nums);

// 문제 B
void problemB();
vector<int> readNumbers();
void quickSort(vector<int>& numbers, int left, int right);

// 문제 C
void problemC();

// 문제 D
void problemD();
double calculateSeries(int x, int limit);
double factorial(int n);

// 문제 E
void problemE();
int strcnt(char *str, char c);
void strrepl(char *str, char c, char n);

// 문제 F
void problemF();

// 문제 G, H
void problemGH();
string cipherText(string message, int shift);
string decodeText(string message, int shift);

/*
 * 고급프로그래밍(IIT1001) 과제 2
 *
 * Written by 김현준
 */
int main(void) {
	problemGH();
    return 0;

}

// ********************************* 문제 A *********************************

/*
 * 요약: 1,2,...,100로 구성된 배열에서 랜덤으로 하나를 제외하고, 논리식을 사용하지 않고 제외된 수를 찾아라.
 */
void problemA() {
	int *bagNum = genBagNum();
	findMissingNum(bagNum);
}

/*
* 1부터 100까지의 수를 포함하고 있는 수열을 생성한다.
* 단, 임의의 한 수를 제외하고 99개의 원소가 있는 배열을 반환한다.
*/
int *genBagNum() {

	cout << "Generatiog a bag of number..." << endl;

	static int bag[99];
	int steppingIndex = rand() % 99;

	cout << "Number to be excluded: " << steppingIndex + 1 << endl;

	for (int i = 0; i < 99; i++) {
		bag[i] = i + 1 + (i >= steppingIndex ? 1 : 0);		
	}

	return bag;
}

/*
 * 조건식을 사용하지 않고 빠진 수를 찾는다.
 * 여기서는 수열의 합을 이용한 방법을 사용하였다.
 */
void findMissingNum(int *nums) {

	cout << "Finding the missing number..." << endl;

	int sum = 0;
	for (int i = 0; i < 99; i++) {
		sum += nums[i];
	}

	cout << "It is " << 5050 - sum << endl;
}	

// ********************************* 문제 B *********************************

/*
 * 문제 B
 * 요약: 임의의 수열을 입력받아 겹치는 숫자들을 내림차순으로 출력
 */
void problemB() {

	vector<int> input;

	cout << "Enter a set of input numbers: ";
	input = readNumbers();

	quickSort(input, 0, input.size() - 1);

	cout << "Duplicated numbers are: ";

	int previousNumber = -100;
	for (int i = 0; i < input.size() - 1; i++) {
		if (input[i] == input[i + 1] && input[i] != previousNumber) {
			cout << input[i++] << ' ';
		}
		previousNumber = input[i];
	}

	cout << endl;
}

/*
 * 콘솔에서 공백 문자를 기준으로 수열을 읽어온다.
 */
vector<int> readNumbers() {

	string input;
	vector<int> output;

	getline(cin, input);
	istringstream iss(input);

	int number;
	while (iss >> number) {
		output.push_back(number);
	}

	return output;
}

/*
 * 재귀적으로 수열을 정렬한다.
 * (QuickSort 알고리즘 구현)
 */
void quickSort(vector<int>& numbers, int left, int right) {

	if (left < right) {

		int pivotIndex = right;
		int pivotValue = numbers[pivotIndex];
		int storeIndex = left;

		for (int i = left; i < right; i++) {
			if (numbers[i] < pivotValue) {
				swap(numbers[i], numbers[storeIndex++]);
			}
		}

		swap(numbers[pivotIndex], numbers[storeIndex]);

		quickSort(numbers, left, storeIndex - 1);
		quickSort(numbers, storeIndex + 1, right);

	}
}

// ********************************* 문제 C *********************************

void problemC() {

	// 학생들의 등급 개수를 저장할 배열
	int grades[5] = { 0, 0, 0, 0, 0 };
	char gradeLabels[5] = { 'A', 'B', 'C', 'D', 'F' };

	for (int i = 0; i < 1000; i++) {

		int score = rand() % 50 + 51;

		// 91 ~ 100: A
		if (score > 90) {
			grades[0]++;
		}

		// 81 ~ 90: B
		else if (score > 80) {
			grades[1]++;
		} 

		// 71 ~ 80: C
		else if (score > 70) {
			grades[2]++;
		}

		// 61 ~ 70: D
		else if (score > 60) {
			grades[3]++;
		}

		// 51 ~ 60: F
		else {
			grades[4]++;
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << gradeLabels[i] << ": " << grades[i] << endl;
	}

}

// ********************************* 문제 D *********************************

void problemD() {
	double sum = 0;
	for (int i = 1; i <= 100; i++) {
        sum += abs(calculateSeries(i, 5) - std::exp(i));
	}
	cout << "Average difference is: " << sum / 100 << endl;
}

/*
 * 시리즈 계산
 */
double calculateSeries(int x, int limit) {
	double sum = 0;
	double term = 1;
	for (int i = 0; i < limit; i++) {
		sum += term;
		term = term * x / (i + 1);
	}
	return sum;
}


// ********************************* 문제 E *********************************

void problemE() {
    char input[] = "The quick brown fox jumps over the lazy dog";

    strrepl(input, 'o', 'a');
    cout << input << endl;
    cout << strcnt(input, 'a') << endl;
}

/*
 * 문자열에서 갯수 세기
 */
int strcnt(char *str, char c) {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == c) {
            count++;
        }
    }
    return count;
}

/*
 * 문자열 변경
 */
void strrepl(char *str, char c, char n) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == c) {
            str[i] = n;
        }
    }

}


// ********************************* 문제 F *********************************

class Matrix {
public:
    
    Matrix(int seed);
    
    Matrix operator + (const Matrix &operand);
    Matrix operator - (const Matrix &operand);
    Matrix operator * (const Matrix &operand);
    Matrix operator / (const Matrix &operand);
    bool operator == (const Matrix &operand);
    
    friend ostream &operator << (ostream &out, Matrix &matrix);
    
    int numbers[3][3];
};

/*
 * 행렬을 랜덤한 값으로 초기화한다.
 * 단 seed값이 0일 경우 영행렬로 초기화한다.
 */
Matrix :: Matrix(int seed) {
    srand(seed);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            numbers[i][j] = (seed == 0 ? 0 : rand() % 100);
        }
    }
}

/*
 * 행렬의 덧셈 정의
 */
Matrix Matrix :: operator + (const Matrix &operand) {
    Matrix result(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.numbers[i][j] = numbers[i][j] + operand.numbers[i][j];
        }
    }
    return result;
}

/*
 * 행렬의 뺄셈 정의
 */
Matrix Matrix :: operator - (const Matrix &operand) {
    Matrix result(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.numbers[i][j] = numbers[i][j] - operand.numbers[i][j];
        }
    }
    return result;
}

/*
 * 행렬의 곱셈 정의
 */
Matrix Matrix :: operator * (const Matrix &operand) {
    Matrix result(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result.numbers[i][j] += numbers[i][k] * operand.numbers[k][j];
            }
        }
    }
    return result;
}

/*
 * 행렬의 나눗셈 정의
 */
Matrix Matrix :: operator / (const Matrix &operand) {
    Matrix result(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.numbers[i][j] = numbers[i][j] / operand.numbers[i][j];
        }
    }
    return result;
}

/*
 * 행렬의 항등 정의
 */
bool Matrix :: operator == (const Matrix &operand) {
    bool equal = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(numbers[i][j] != operand.numbers[i][j]){
                equal = false;
            }
        }
    }
    return equal;
}

/*
 * 스트림을 사용하여 행렬을 콘솔에 출력하는 함수 정의
 */
ostream &operator << (ostream &out, Matrix &matrix) {
    
    for (int i = 0; i < 9; i++) {
        out << matrix.numbers[(int)(i / 3)][i % 3] << ' ';
        if(((i + 1) % 3) == 0) out << endl;
    }
    
    return out;
}

void problemF() {
    Matrix left(1);
    Matrix right(2);
    Matrix result(0);
    Matrix addition = left + right;
    Matrix substraction = left - right;
    Matrix multiplication = left * right;
    Matrix division = left / right;
    bool equality = left == right;
    cout << "Matrix A: " << endl;
    cout << left << endl;
    cout << "Matrix B: " << endl;
    cout << right << endl;
    cout << "A + B" << endl;
    cout << addition << endl;
    cout << "A - B" << endl;
    cout << substraction << endl;
    cout << "A * B" << endl;
    cout << multiplication << endl;
    cout << "A / B" << endl;
    cout << division << endl;
    cout << "A == B" << endl;
    cout << equality << endl;
}


// ********************************* 문제 F, G *********************************

void problemGH() {
    string message = "My name is Kim HyunJun. I am very handsome";
    string encoded = cipherText(message, 1);
    string decoded = decodeText(encoded, 1);
    cout << "Original message: " << message << endl;
    cout << "Ciphered text: " << encoded << endl;
    cout << "Decoded text: " << decoded << endl;
}

string cipherText(string message, int shift) {
    char encodedText[message.length()];
    for (int i = 0; i < message.length(); i++) {
        encodedText[i] = int(message.at(i)) + shift;
    }
    return string(encodedText);
}

string decodeText(string message, int shift) {
    char decodedText[message.length()];
    for (int i = 0; i < message.length(); i++) {
        decodedText[i] = int(message.at(i)) - shift;
    }
    return string(decodedText);
}
