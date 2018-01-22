// Exercise 15.20, page 762
//
// Write code to test your answers to the previous two exercises.
//
// Exercise 15.5
//
// Given the classes from page 612 and page 613, and assuming each
// object has the type specified in the comments, determine which of
// these assignments are legal. Explain why those that are illegal
// aren’t
//
// Base *p = &d1; d1 has type Pub_Derv
// p = &d2; d2 has type Priv Derv
// p = &d3; d3 has type Prot_Derv
// p = &dd1; dd1 has type Der_from_Public
// p = &dd2; dd2 has type Der_from_Private
// p = &dd3; dd3 has type Der_from_Protected

class Base {
};

class Pub_Derv : public Base {
};

class Priv_Derv : private Base {
};

class Prot_Derv : protected Base {
};

class Derived_from_Public : public Pub_Derv {
};

class Derived_from_Private : public Priv_Derv {
};

class Derived_from_Protected : public Prot_Derv {
};


Pub_Derv d1;
Pub_Derv d2;
Pub_Derv d3;
Derived_from_Public dd1;
Derived_from_Private dd2;
Derived_from_Protected dd3;

int main(int argc, char *argv[argc])
{
  Base *p = &d1;
  p = &d2;
  p = &d3;
  p = &dd1;
  // p = &dd2; // Cannot do this as the Base class part of the object is private
  // p = &dd3; // Cannot do this because this is user code, not subclass code
  
  return 0;
}

