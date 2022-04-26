/* Workshop #7 Part #1
Full name			: Yunus Gumus
Student ID number	: 150331197
Seneca email address: ygumus@myseneca.ca
Section code		: NCC
When I Start to WS  : 2022-03-14
When I finish P1	: 2022-02-17
When I finish P2	: TBD*/


#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {

	const int MAX_CONTENTDESC_CHAR = 51;

	class Container
	{
	private:
		char* c_contentDesc{};
		int c_maxCapacityOfCC;
		int c_contentVolume;

	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		Container();
		Container(const char* content, int capacity, int contentVolume = 0);
		~Container();

		int operator +=(int addValue);
		int operator -=(int deductValue);
		operator bool() const;

		void clear(int capacity, const char* contentDesc);
		std::ostream& print(std::ostream& os) const;
		std::istream& read(std::istream& is);

	};

	std::ostream& operator << (std::ostream& ostr, const Container& container);
	std::istream& operator >> (std::istream& istr, Container& container);

}
#endif // !SDDS_UTILS_H