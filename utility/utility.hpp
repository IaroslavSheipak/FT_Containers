#ifndef UTILITY_HPP
#define UTILITY_HPP


namespace ft{

template<class T> struct remove_const { typedef T type; };

template<class T> struct remove_const <const T> { typedef T type; };


template <class Iterator> class iterator_traits
{
	public:
		typedef typename Iterator::difference_type	difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer			pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
};

template <class T> class iterator_traits<T*>
{
	public:
		typedef std::ptrdiff_t	difference_type;
		typedef T				value_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef	std::random_access_iterator_tag	iterator_category;
};

template <class T> class iterator_traits<const T*>
{
	public:
		typedef std::ptrdiff_t	difference_type;
		typedef const T				value_type;
		typedef const T*			pointer;
		typedef const T&			reference;
		typedef	std::random_access_iterator_tag	iterator_category;
};

template<class T1, class T2> struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	first_type	first;
	second_type	second;
	pair() : first(), second() {}
    template <class U, class V>
    pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
	pair(const pair & pr) : first(pr.first), second(pr.second) {}
    pair(const first_type &a, const second_type &b) : first(a), second(b) {}
    pair &operator=(const pair &pr) {
        first = pr.first;
        second = pr.second;
        return (*this);
    }
};

template <class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
    return !(lhs < rhs);
}

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
    return (pair<T1, T2>(x, y));
}

template<class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};

template <class T> struct is_integral				: public ft::integral_constant<T, false> {};
template <> struct is_integral<bool>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<char>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<signed char>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned char>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<wchar_t>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<char16_t>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<short>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned short>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<int>					: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned int>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<long>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long> 		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<long long>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long long>	: public ft::integral_constant<bool, true> {};

template<bool B, class T, class F>
	struct conditional {
	typedef F type;
};
 
template<class T, class F>
struct conditional<true, T, F> { typedef T type; };

template<bool B, class T = void>
	struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
{
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2,
                             Compare comp)
{
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
        if (comp(*first1, *first2)) return true;
        if (comp(*first2, *first1)) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	  while (first1!=last1) {
		      if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				        return false;
			      ++first1; ++first2;
				    }
	    return true;
}

};


#endif
