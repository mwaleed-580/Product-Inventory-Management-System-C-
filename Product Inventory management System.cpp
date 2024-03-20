#include <iostream>
#include <fstream>
using namespace std;
int findStringLength(char* input){
	int length = 0;
	while (input[length] != '\0')
	{
		length++;
	}
	return length;
}
char** charRowGrow(char** oldArray, int size) {
	char** newArray = new char*[size + 1];
	for (int i = 0; i < size; i++) {
		newArray[i] = oldArray[i];
	}
	newArray[size] = nullptr;
	delete[] oldArray;
	return newArray;
}
char** charRowSrink(char** oldArray, int size, int removeIndex) {
	char** newArray = new char*[size - 1];
	for (int i = 0, j = 0; i < size; i++) {
		if (i == removeIndex)
		{
			delete[] oldArray[i];
		}
		else
		{
			newArray[j] = oldArray[i];
			j++;
		}
	}
	delete[] oldArray;
	return newArray;
}
int* intGrow(int* oldArray, int size){
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = oldArray[i];
	}
	delete[] oldArray;
	return newArray;
}
int* intShrink(int* oldArray, int size, int removeIndex){
	int* newArray = new int[size - 1];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != removeIndex)
		{
			newArray[j] = oldArray[i];
			j++;
		}
	}
	delete[] oldArray;
	return newArray;
}
void sortAscending(int* array1, int* array2, int* array3, char** productNames, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (array1[i] > array1[j])
			{
				int temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				temp = array2[i];
				array2[i] = array2[j];
				array2[j] = temp;
				temp = array3[i];
				array3[i] = array3[j];
				array3[j] = temp;
				char* tempPtr = productNames[i];
				productNames[i] = productNames[j];
				productNames[j] = tempPtr;
			}
		}
	}
}
void sortDescending(int* array1, int* array2, int* array3, char** productNames, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array1[i] < array1[j]) {
				int temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				temp = array2[i];
				array2[i] = array2[j];
				array2[j] = temp;
				temp = array3[i];
				array3[i] = array3[j];
				array3[j] = temp;
				char* tempPtr = productNames[i];
				productNames[i] = productNames[j];
				productNames[j] = tempPtr;
			}
		}
	}
}
void sortAtoZ(int* array1, int* array2, int* array3, char** productNames, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (productNames[i][0] > productNames[j][0])
			{
				char* tempPtr = productNames[i];
				productNames[i] = productNames[j];
				productNames[j] = tempPtr;
				int temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				temp = array2[i];
				array2[i] = array2[j];
				array2[j] = temp;
				temp = array3[i];
				array3[i] = array3[j];
				array3[j] = temp;
			}
		}
	}
}
void sortZtoA(int* array1, int* array2, int* array3, char** productNames, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (productNames[i][0] < productNames[j][0])
			{
				char* tempPtr = productNames[i];
				productNames[i] = productNames[j];
				productNames[j] = tempPtr;
				int temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				temp = array2[i];
				array2[i] = array2[j];
				array2[j] = temp;
				temp = array3[i];
				array3[i] = array3[j];
				array3[j] = temp;
			}
		}
	}
}
void displayResults(int* ID, char** productNames, int* quantity, int* price, int size, int startIndex){
	for (int i = startIndex; i < size; i++)
	{
		if (ID[i] != -1)
		{
			cout << "ID: " << ID[i] << "\tProduct Name: ";
			if (productNames[i] != nullptr)
			{
				for (int j = 0; productNames[i][j] != '\0'; j++)
				{
					cout << productNames[i][j];
				}
			}
			cout << "\tQuantity: " << quantity[i] << "\tPrice: " << price[i] << endl;
		}
	}
}
void addNewEntry(int*& ID, char**& productNames, int*& quantity, int*& price, int& size, char mode){
	int availableIndex = -1, idInput;
	char* inputName = new char[20];
	if (mode == 'A')
	{
		for (int i = 0; i < size; i++)
		{
			if (ID[i] == -1)
			{
				availableIndex = i;
				break;
			}
		}
		if (availableIndex == -1)
		{
			ID = intGrow(ID, size);
			productNames = charRowGrow(productNames, size);
			quantity = intGrow(quantity, size);
			price = intGrow(price, size);
			size++;
			availableIndex = size - 1;
		}
		while (true)
		{
			cout << "Enter ID: ";
			cin >> idInput;
			bool is_unique = true;
			for (int i = 0; i < size; i++)
			{
				if (idInput == ID[i])
				{
					cout << "This ID already exists. Please try with a unique ID.\n";
					is_unique = false;
					break;
				}
			}
			if (is_unique)
			{
				ID[availableIndex] = idInput;
				break;
			}
		}
		cout << "Enter Product Name: ";
		cin.ignore();
		cin.getline(inputName, 20);
		int inputNameLength = findStringLength(inputName);
		productNames[availableIndex] = new char[inputNameLength + 1];
		for (int i = 0; i < inputNameLength; i++)
		{
			productNames[availableIndex][i] = inputName[i];
		}
		productNames[availableIndex][inputNameLength] = '\0';
		cout << "Enter Quantity: ";
		cin >> quantity[availableIndex];
		cout << "Enter Price: ";
		cin >> price[availableIndex];
		cout << "Record Added.\n";
	}
	else if (mode == 'B')
	{
		ifstream backup_file;
		backup_file.open("backup.txt");
		while (!backup_file.eof())
		{
			availableIndex = -1;
			for (int i = 0; i < size; i++)
			{
				if (ID[i] == -1)
				{
					availableIndex = i;
					break;
				}
			}
			if (availableIndex == -1)
			{
				ID = intGrow(ID, size);
				productNames = charRowGrow(productNames, size);
				quantity = intGrow(quantity, size);
				price = intGrow(price, size);
				size++;
				availableIndex = size - 1;
			}
			backup_file >> ID[availableIndex] >> inputName >> quantity[availableIndex] >> price[availableIndex];
			int inputNameLength = findStringLength(inputName);
			productNames[availableIndex] = new char[inputNameLength + 1];
			for (int i = 0; i < inputNameLength; i++)
			{
				productNames[availableIndex][i] = inputName[i];
			}
			productNames[availableIndex][inputNameLength] = '\0';
		}
		backup_file.close();
	}
	delete[] inputName;
}
void deleteEntry(int*& ID, char**& productNames, int*& quantity, int*& price, int& size, int removeIndex, char mode){
	if (mode == 'A')
	{
		int idInput;
		bool isPresent = false;
		cout << "Enter ID to remove: ";
		cin >> idInput;
		for (int i = 0; i < size; i++)
		{
			if (idInput == ID[i])
			{
				isPresent = true;
				removeIndex = i;
				break;
			}
		}
		if (isPresent)
		{
			ID = intShrink(ID, size, removeIndex);
			productNames = charRowSrink(productNames, size, removeIndex);
			quantity = intShrink(quantity, size, removeIndex);
			price = intShrink(price, size, removeIndex);
			size--;
			cout << "Record Deleted.\n";
		}
		else
		{
			cout << "The Product with this ID is not present.\n";
		}
	}
	else if (mode == 'B')
	{
		ID = intShrink(ID, size, removeIndex);
		productNames = charRowSrink(productNames, size, removeIndex);
		quantity = intShrink(quantity, size, removeIndex);
		price = intShrink(price, size, removeIndex);
		size--;
	}
}
void searchID(int* ID, char** productNames, int* quantity, int* price, int size){
	int idInput;
	bool isPresent = false;
	cout << "Enter ID to search: ";
	cin >> idInput;
	for (int i = 0; i < size; i++)
	{
		if (idInput == ID[i])
		{
			isPresent = true;
			int startIndex = i;
			int endSize = i + 1;
			displayResults(ID, productNames, quantity, price, endSize, startIndex);
		}
	}
	if (!isPresent)
	{
		cout << "The Product with this ID is not present.\n";
	}
}
void searchProductName(int* ID, char** productNames, int* quantity, int* price, int size) {
	char* inputName = new char[20];
	int inputNameLength = findStringLength(inputName);
	cout << "Enter product name to search: ";
	cin.ignore();
	cin.getline(inputName, 20);
	bool isFound = false;
	for (int i = 0; i < size; i++) {
		if (productNames[i] != nullptr) {
			int inputNameLength = findStringLength(inputName);
			int productNameLength = findStringLength(productNames[i]);
			if (inputNameLength == productNameLength) {
				bool isSame = true;
				for (int j = 0; j < productNameLength; j++) {
					if (inputName[j] != productNames[i][j]) {
						isSame = false;
						break;
					}
				}
				if (isSame) {
					isFound = true;
					int startIndex = i;
					int endSize = i + 1;
					displayResults(ID, productNames, quantity, price, endSize, startIndex);
					break;
				}
			}
		}
	}
	if (!isFound) {
		cout << inputName << " is not found in the records.\n";
	}
	delete[] inputName;
}
void searchRange(int* array1, int* array2, int* array3, char** productNames, int size, char mode){
	int min, max;
	bool isFound = false;
	cout << "Enter minimum range value: ";
	cin >> min;
	cout << "Enter maxmium range value: ";
	cin >> max;
	for (int i = 0; i < size; i++)
	{
		if (array1[i] >= min && array1[i] <= max)
		{
			if (mode == 'A')
			{
				int startIndex = i;
				int endSize = i + 1;
				displayResults(array2, productNames, array3, array1, endSize, startIndex);
				isFound = true;
			}
			else if (mode == 'B')
			{
				int startIndex = i;
				int endSize = i + 1;
				displayResults(array2, productNames, array1, array3, endSize, startIndex);
				isFound = true;
			}
		}
	}
	if (!isFound)
	{
		cout << "There is no Product record within this range.\n";
	}
}
void findLowStock(int* ID, char** productNames, int* quantity, int* price, int size){
	int stockThreshold;
	bool isFound = false;
	cout << "Enter minimum stock threshold: ";
	cin >> stockThreshold;
	for (int i = 0; i < size; i++)
	{
		if (quantity[i] <= stockThreshold)
		{
			int startIndex = i;
			int endSize = i + 1;
			displayResults(ID, productNames, quantity, price, endSize, startIndex);
			isFound = true;
		}
	}
	if (!isFound)
	{
		cout << "There is no Product record below this stock.\n";
	}
}
void findTotalvalue(int* ID, char** productNames, int* quantity, int* price, int size){
	int totalValue = 0;
	for (int i = 0; i < size; i++)
	{
		totalValue += quantity[i] * price[i];
	}
	cout << "Total Inventory Value: " << totalValue << endl;
}
void updateItem(int* ID, char** productNames, int* quantity, int* price, int size, char mode){
	int idInput, valueInput;
	cout << "Enter ID to select the product for update: ";
	cin >> idInput;
	bool is_found = false;
	int i = 0;
	while (i < size)
	{
		if (idInput != ID[i])
		{
			is_found = true;
			break;
		}
		i++;
	}
	i--;
	if (is_found)
	{
		cout << "Enter Value to update: ";
		cin >> valueInput;
		if (mode == 'A')
		{
			quantity[i] = valueInput;
			cout << "Value updated.\n";
			int startIndex = i;
			int endSize = i + 1;
			displayResults(ID, productNames, quantity, price, endSize, startIndex);
		}
		else if (mode == 'B')
		{
			price[i] = valueInput;
			cout << "Value updated.\n";
			int startIndex = i;
			int endSize = i + 1;
			displayResults(ID, productNames, quantity, price, endSize, startIndex);
		}
	}
	else
	{
		cout << "This Product does not exists.\n";
	}
}
void backupData(int* ID, char** productNames, int* quantity, int* price, int size){
	ofstream backup_file;
	backup_file.open("backup.txt");
	if (backup_file.is_open())
	{
		int endSize = 0;
		for (int i = 0; i < size; i++)
		{
			if (ID[i] != -1 && productNames[i] != nullptr)
			{
				endSize++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (ID[i] != -1 && productNames[i] != nullptr)
			{
				backup_file << ID[i] << " " << productNames[i] << " " << quantity[i] << " " << price[i];
				if (i != endSize - 1)
				{
					backup_file << "\n";
				}
			}
		}
		cout << "Backup created successfully.\n";
	}
	else
	{
		cerr << "Error opening the backup file.\n";
	}
	backup_file.close();
}
void restoreData(int*& ID, char**& productNames, int*& quantity, int*& price, int& size){
	ifstream backup_file;
	backup_file.open("backup.txt");
	if (backup_file.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			deleteEntry(ID, productNames, quantity, price, size, i, 'B');
		}
		addNewEntry(ID, productNames, quantity, price, size, 'B');
		cout << "Backup restored successfully.\n";
	}
	else
	{
		cerr << "Error opening the backup file.\n";
	}
	backup_file.close();
}
int main() {
	char* choice = new char[3];
	int size = 20;
	char** productNames = new char*[size];
	int* ID = new int[size];
	for (int i = 0; i < size; i++)
	{
		ID[i] = -1;
		productNames[i] = nullptr;
	}
	int* quantity = new int[size];
	int* price = new int[size];
	cout << "\n================================ Welcome to Product Inventory Management System ================================\n\n";
	cout << "1. Sort and display all the records ID wise in ascending order.\n";
	cout << "2. Sort and display all the records ID wise in descending order.\n";
	cout << "3. Sort and display all records in ascending order based on quantity.\n";
	cout << "4. Sort and display all records in descending order based on quantity.\n";
	cout << "5. Sort and display all records in ascending order based on price.\n";
	cout << "6. Sort and display all records in descending order based on price.\n";
	cout << "7. Sort and display all records in ascending order (alphabetically) based on Product name.\n";
	cout << "8. Sort and display all records in descending order (alphabetically) based on Product name.\n";
	cout << "9. Add a new entry.\n";
	cout << "10. Delete an item based on the product ID.\n";
	cout << "11. Search an item based on ID.\n";
	cout << "12. Search an item based on Product Name.\n";
	cout << "13. Search an item based on range of price.\n";
	cout << "14. Search an item based on range of quantity.\n";
	cout << "15. Display low stock items.\n";
	cout << "16. Display Total Inventory Value.\n";
	cout << "17. Update an item (quantity).\n";
	cout << "18. Update an item (price).\n";
	cout << "19. Backup the data in a file.\n";
	cout << "20. Delete the existing data and restore from the backup file.\n";
	cout << "Enter E or e to exit the system.\n";
	while (true) {
		cout << "Enter your choice from the menu: ";
		cin >> choice;
		if (choice[0] == '1' && choice[1] == '\0') {
			sortAscending(ID, quantity, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '2' && choice[1] == '\0') {
			sortDescending(ID, quantity, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '3' && choice[1] == '\0') {
			sortAscending(quantity, ID, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '4' && choice[1] == '\0') {
			sortDescending(quantity, ID, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '5' && choice[1] == '\0') {
			sortAscending(price, ID, quantity, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '6' && choice[1] == '\0') {
			sortDescending(price, ID, quantity, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '7' && choice[1] == '\0') {
			sortAtoZ(ID, quantity, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '8' && choice[1] == '\0') {
			sortZtoA(ID, quantity, price, productNames, size);
			displayResults(ID, productNames, quantity, price, size, 0);
		}
		else if (choice[0] == '9' && choice[1] == '\0') {
			addNewEntry(ID, productNames, quantity, price, size, 'A');
		}
		else if (choice[0] == '1' && choice[1] == '0' && choice[2] == '\0') {
			deleteEntry(ID, productNames, quantity, price, size, 0, 'A');
		}
		else if (choice[0] == '1' && choice[1] == '1' && choice[2] == '\0') {
			searchID(ID, productNames, quantity, price, size);
		}
		else if (choice[0] == '1' && choice[1] == '2' && choice[2] == '\0') {
			searchProductName(ID, productNames, quantity, price, size);
		}
		else if (choice[0] == '1' && choice[1] == '3' && choice[2] == '\0') {
			searchRange(price, ID, quantity, productNames, size, 'A');
		}
		else if (choice[0] == '1' && choice[1] == '4' && choice[2] == '\0') {
			searchRange(quantity, ID, price, productNames, size, 'B');
		}
		else if (choice[0] == '1' && choice[1] == '5' && choice[2] == '\0') {
			findLowStock(ID, productNames, quantity, price, size);
		}
		else if (choice[0] == '1' && choice[1] == '6' && choice[2] == '\0') {
			findTotalvalue(ID, productNames, quantity, price, size);
		}
		else if (choice[0] == '1' && choice[1] == '7' && choice[2] == '\0') {
			updateItem(ID, productNames, quantity, price, size, 'A');
		}
		else if (choice[0] == '1' && choice[1] == '8' && choice[2] == '\0') {
			updateItem(ID, productNames, quantity, price, size, 'B');
		}
		else if (choice[0] == '1' && choice[1] == '9' && choice[2] == '\0') {
			backupData(ID, productNames, quantity, price, size);
		}
		else if (choice[0] == '2' && choice[1] == '0' && choice[2] == '\0') {
			restoreData(ID, productNames, quantity, price, size);
		}
		else if ((choice[0] == 'E' || choice[0] == 'e') && choice[1] == '\0') {
			cout << "Exiting the system...\n";
			break;
		}
		else {
			cout << "Please enter a valid option\n";
		}
	}
	for (int i = 0; i < size; i++)
	{
		delete[] productNames[i];
	}
	delete[] productNames;
	delete[] ID;
	delete[] quantity;
	delete[] price;
	delete[] choice;
	return 0;
}