#include<iostream>
using namespace std;

class LimbBuffer {
private:
  uint64_t* limbs;
  size_t capacity;
  size_t length;

public:
/*add contructors here
- constructor
- deconstructor
- copy
- copy from one buffer to another
- move
These are the Rule of 5, check if they are contructors
We must also implement the following functions:
- explicit LimbBuffer(size_t cap);
~LimbBuffer();
uint64_t* data() noexcept;
void resize(size_t new_len);
*/
};


//target signature
LimbBuffer multiply(const LimbBuffer& a, const LimbBuffer& b, MultiplicationMetrics& m);
