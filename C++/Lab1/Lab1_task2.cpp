#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> elements = { "a", "1", "b", "2", "c", "3" };				   // исходный массив
	vector<string> letters;													   // массив букв
	vector<string> numbers;													   // массив чисел

	for (int i = 0; i < elements.size(); ++i) letters.push_back(elements[i]);  // заполнили массив буквами
	for (int i = 0; i < elements.size(); ++i) numbers.push_back(elements[i]);  // заполнили массив числами
	elements.clear();														   // очищаем исходный массив
	for (int i = 0; i < letters.size(); i+=2) cout << letters[i];					   // выводим первый массив
	cout << "\n";															   
	for (int i = 1; i < numbers.size(); i+=2) cout << numbers[i];					   // выводим второй массив

	return 0;
}
