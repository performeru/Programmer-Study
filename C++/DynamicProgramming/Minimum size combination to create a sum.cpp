#include <iostream>
#include <vector>
#include <map>

using namespace std;
using int_vector = vector<int>;
using sum_history = map<int, shared_ptr<int_vector>>;

shared_ptr<int_vector> OptimizeSum(
	int sum,
	const int_vector& numbers,
	shared_ptr<sum_history> h
) 
{
  
	if (h->count(sum) == 1) 
  {
		return (*h)[sum];
	}
	if (sum == 0) 
  {
		return std::make_shared<int_vector>();
	}
	if (sum < 0) 
  {
		return nullptr;
	}

	int remain = 0;
	shared_ptr<int_vector> optimized = nullptr;

	for (auto e : numbers) 
  {
		remain = sum - e;
		auto ret = OptimizeSum(remain, numbers, h);

		if (ret != nullptr) 
    {
			shared_ptr<int_vector> v = make_shared<int_vector>();
			v->resize(ret->size());
			copy(ret->begin(), ret->end(), v->begin());
			v->push_back(e);
			if (optimized == nullptr || v->size() < optimized->size()) 
      {
				optimized = v;
			}
		}
	}

	(*h)[sum] = optimized;
	return (*h)[sum];
}

void Print(shared_ptr<int_vector> r) 
{
	cout << "{ ";

	if (r != nullptr)
  {
		for (auto e : *r) 
    {
			cout << e << " ";
		}
	}

	cout << "}" << endl;
}

int main() 
{
	Print(OptimizeSum(7, { 5,3,4,7 }, make_shared<sum_history>()));
	Print(OptimizeSum(7, { 1, 4 }, make_shared<sum_history>()));
	Print(OptimizeSum(900, { 7, 14 }, make_shared<sum_history>()));
	Print(OptimizeSum(1750, { 10, 50, 100, 500, 1000 }, make_shared<sum_history>()));
}
