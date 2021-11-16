#ifdef yarik
#include "../ft_containers/vector/Vector.hpp"
#include "../ft_containers/iterator/iterator.hpp"
#include "../ft_containers/map/RBTree.hpp"
#endif
#ifdef kirill
#include "../ft_containers/stack/stack.hpp"
#endif
#include "SampleClass.hpp"
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
# define B_CYAN "\x1b[46;1m" <<
# define B_RED  "\x1b[41;1m" <<
# define YELLOW "\x1b[33;1m" <<
# define RED    "\x1b[31;1m" <<
# define GREEN  "\x1b[32;1m" <<
# define DEFAULT << "\x1b[m"


bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void	map_constructor()
{
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}
