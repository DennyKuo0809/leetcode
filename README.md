
### Array and String
* KMP algorithm
   * 28 Find the Index of the First Occurrence in a String
* Boyer–Moore majority vote algorithm
   * 229 Majority Element II
* Record in-place
  * 41 First Missing Positive

### Link List
* Fast slow pointer

### Graph
* Euler Path / Cycle
  * 332. Reconstruct Itinerary
* Topological Order
  * 210 Course Schedule II
* Cycle detection
 * 207 Course Schedule


### DP
* Backpack Problem (select / not select)

## C++ cheat sheet
### lambda function for comparing
```
sort(
  vec.begin(),
  vec.end(),
  [&](const A& a, const A& b) {return a > b}
);
```
### `upper_bound`, `lower_bound`
```
auto it = upper_bound(vec.begin(), vec.end(), element);
auto it = lower_bound(vec.begin(), vec.end(), element);
```

### Slice a string by a specific character
```
#include <string>
#include <vector>
#include <stream>
usingn namespace std;

std::stringstream test("this_is_a_test_string");
std::string segment;
std::vector<std::string> seglist;

while(std::getline(test, segment, '_'))
{
   seglist.push_back(segment);
}
```


