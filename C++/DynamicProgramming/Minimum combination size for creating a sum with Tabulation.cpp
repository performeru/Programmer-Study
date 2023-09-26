#include <iostream>
#include <vector>

using namespace std;
using int_vector = vector<int>; 

shared_ptr<int_vector> OptimizeAccumulate(int sum, const int_vector& numbers) 
{
	vector<shared_ptr<int_vector>> table(sum + 1, nullptr); 
	
	table[0] = make_shared<int_vector>(0);

	for (int i = 0; i <= sum; ++i) 
  {
		if (table[i] != nullptr) 
    {
			for (auto e : numbers)
      {
				if (i + e <= sum)
        {
					if (table[i + e] == nullptr || (table[i + e]->size() - 1 > table[i]->size()))
          {
						table[i + e] = make_shared<int_vector>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}
	return table[sum];
}

int main() 
{
	auto ret = OptimizeAccumulate(7, { 2, 3, 5 });

	cout << "{ ";
	if (ret != nullptr) 
  {
		for (size_t i = 0; i < ret->size(); ++i) 
    {
			cout << (*ret)[i];
			if (i != ret->size() - 1)
      {
				cout << ", ";
			}
		}
	}
	cout << " }" << endl;
}
