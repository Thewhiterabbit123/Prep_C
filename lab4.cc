/*Автор, Название, Издательство, Год, Количество страниц. Создать массив объектов. Вывести:
а) список книг заданного автора;
б) список книг, выпущенных заданным издательством;
в) список книг, выпущенных после заданного года.*/

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Book {
	public:
		Book(): author(nullptr), name(nullptr), publishing(nullptr), year(0), pages(0) {};
		Book(const Book& rhs);
		~Book();

		const char* get_author()     const;
		const char* get_name()       const;
		const char* get_publishing() const;
		const int   get_year()       const;
		const int   get_pages()      const;

		void set_author(char* author);
		void set_name(char* name);
		void set_publishing(char* publishing);
		void set_year(int year);
		void set_pages(int pages);

		void show_author();
		void show_name();
		void show_publishing();
		void show_year();
		void show_pages();

	private:
		char* author;
		char* name;
		char* publishing;
		int   year;
		int   pages;
};

void SHOW(Book& story) {
	story.show_author();
	story.show_name();
	story.show_publishing();
	story.show_pages();
	story.show_year();
	cout << '\n';
}

Book::Book(const Book& rhs) {	
	if(rhs.author) {
		size_t len = strlen(rhs.author) + 1;
		this->author = new char[len];
		memcpy(this->author, rhs.author, len);
	}
	if(rhs.name) {
		size_t len = strlen(rhs.name) + 1;
		this->name = new char[len];
		memcpy(this->name, rhs.name, len);
	}
	if(rhs.publishing) {
		size_t len = strlen(rhs.publishing) + 1;
		this->publishing = new char[len];
		memcpy(this->publishing, rhs.publishing, len);
	}
	if (rhs.pages){
		this->pages = pages;
	}
	this->year = 2017;
}

Book::~Book() {
	delete[] author; 
	delete[] name;
	delete[] publishing;
}

const char* Book::get_name() const {
	return this->name;
}
const char* Book::get_author() const {
	return this->author;
}
const char* Book::get_publishing() const {
	return this->publishing;
}
const int   Book::get_year() const {
	return this->year;
}
const int   Book::get_pages() const {
	return this->pages;
}

void Book::set_author(char* author) {
	size_t len = strlen(author) + 1;
	this->author = new char[len];
	memcpy(this->author, author, len);
}
void Book::set_name(char* name) {
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	memcpy(this->name, name, len);
}
void Book::set_publishing(char* publishing) {
	size_t len = strlen(publishing) + 1;
	this->publishing = new char[len];
	memcpy(this->publishing, publishing, len);
}
void Book::set_year(int year) {
	this->year = year;
}
void Book::set_pages(int pages) {
	this->pages = pages;
}

void Book::show_author() {
	cout.width(10);
	cout << this->author << ' ';
}
void Book::show_name() {
	cout.width(25);
	cout << this->name << ' ';
}
void Book::show_publishing() {
	cout.width(10);
	cout << this->publishing << ' ';
}
void Book::show_pages() {
	cout.width(10);
	cout << this->pages << ' ';
}
void Book::show_year() {
	cout.width(10);
	cout << this->year << ' ';
}

int main(int argc, char const *argv[])
{
	std::cout << "1: program name, 2: author, 3: publishing, 4: year\n";

	if(argc > 5 ) {
		cerr << "too many arguments\n";
		return 1;
	}
	ifstream file(argv[1]);
	if(!file.is_open()) {
		cerr << "file can't be open\n";
		return 1;
	}
	
	int n = 0; 
	file >> n;

	Book *library = new Book[n];

	for (int i = 0; i < n; ++i) {
		char *author = new char[64];
		file.width(63);
		file >> author;
		library[i].set_author(author);
		delete [] author;
		
		char *name = new char[64];
		file.width(63);
		file >> name;
		library[i].set_name(name);
		delete [] name;

		char *publishing = new char[64];
		file.width(63);
		file >> publishing;
		library[i].set_publishing(publishing);
		delete [] publishing;

		int pages;
		file >> pages;
		library[i].set_pages(pages);

		int year;
		file >> year;
		library[i].set_year(year);
	}

	file.close();

	for (int i = 0; i < n; ++i) {
		if (argv[2]) {
			if (!strcmp(argv[2], library[i].get_author())) {
				cout << argv[2] << ":\n";
				SHOW(library[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (argv[3]) {
			if (!strcmp(argv[3], library[i].get_publishing())) {
				cout << argv[3] << ":\n";
				SHOW(library[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (argv[4]) {
			if (stoi(argv[4]) < library[i].get_year()) {
				cout << argv[4] <<":\n";
				SHOW(library[i]);
			}
		}
	}
	delete [] library;
}
//обязательно явно присваивать значения
//расширять динамически-выделять новую память, копировать и удалять старую
//в разных файлах
