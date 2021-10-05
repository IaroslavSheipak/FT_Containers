#ifndef STACK_HPP
#define STACK_HPP
//AAAAAA CHANGE STD TO FT LOWERRRR
#include <vector>

namespace ft{

template<class T, class Container = std::vector<T> >
	class stack{
	typedef T value_type;
	typedef std::vector<T> container_type;
	typedef std::size_t size_type;

	
	explicit stack (const container_type& ctnr = container_type()) : container(){}
	bool empty() const{
		return (container.empty());

	}
	size_type size() const{
		return (container.size());
	}
	value_type& top(){
		
		return (container.back());
	}
	const value_type& top() const{

		return (container.back());
	}
	void push (const value_type& val){
		container.push_back(val);
	}
	void pop(){
		container.pop_back();
	}

	private:
	container_type container;
};


	template <class T, class Container>
		  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container == lhs.container);
			 }
	template <class T, class Container>
		  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container != lhs.container);
			 }
	template <class T, class Container>
		  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container < lhs.container);
			 }
	template <class T, class Container>
		  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container <= lhs.container);
		  }
	template <class T, class Container>
		  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container > lhs.container);
		  }
	template <class T, class Container>
		  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return(lhs.container >= lhs.container);
			}

}
#endif
