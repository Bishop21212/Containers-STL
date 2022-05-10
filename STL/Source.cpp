//STL
#include<iostream>
#include<array>
#include<vector>

using std::cin;
using std::endl;
using std::cout;

#define tab "\t"
#define delimeter "\n---------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR
int main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	std::array<int,5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); ++i)cout << arr[i] << tab;
	cout << endl;

	std::array<int, 5>* p_arr = new std::array<int, 5>{3, 5, 8, 13, 21};
	for (int i = 0; i < p_arr->size(); ++i)cout << p_arr->operator[](i) << tab;
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };

	for (int i = 0; i < vec.size(); ++i)cout << vec[i] << tab;
	cout << endl; 

	cout << "Size:   " << vec.size() << endl;
	cout << "MaxSize:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << delimeter << endl;
	vec.push_back(55);
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	cout << "Size:   " << vec.size() << endl;
	cout << "MaxSize:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << delimeter << endl;

	//vec.shrink_to_fit();//сокращает выделенную пам€ть до фактического размера
	//vec.reserve(25);//переопредел€ем пам€ть
	vec.resize(5);//измен€ет фактический размер vector
	
	//cout << endl;

	cout << "Size:   " << vec.size() << endl;
	cout << "MaxSize:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	//cout << delimeter << endl;

	try
	{
		//throw  4;//"My Exaption";
		for (int i = 0; i < vec.capacity() * 2; ++i)/*cout << vec.at(i) << tab;*/// метод at - работает как квадратные скобки
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (const char* e)
	{
		std::cerr << e << endl;
	}
	catch (int e)
	{
		std::cerr << "Error# " << e << endl;
	}
	catch (...)//только этот блок может обработать системную ошибку деление на нуль
	{
		//EHa
		std::cerr << "Something happened" << endl;
	}
	cout << "Ќулевой элемент вектора: " << vec.front() << endl;
	cout << "ѕоследний элемент вектора: " << vec.back() << endl;

	int* p_arr = vec.data();

	vec.assign({ 1,2,4,8,16,32 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)cout << *it << tab;
	cout << endl;


	cout << "Size:   " << vec.size() << endl;
	cout << "MaxSize:" << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
#endif // STL_VECTOR

}