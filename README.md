
### Array and String
* KMP algorithm
   * 28 Find the Index of the First Occurrence in a String
* Boyer–Moore majority vote algorithm
   * 229 Majority Element II
* Record in-place
  * 41 First Missing Positive
* Two Pointers
  * 42 Trapping Rain Water

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

### lambda comparing function for the priority queue
```
auto comp = [&](ListNode* a, ListNode* b){return (a->val) > (b->val);};
priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
```
priority queue template
* `ListNode*`: Type of elements
* `vector<ListNode*>`: Type of container
* `decltype(comp)`: Type of comparing function. Use `decltype` to know the type of comparing function.

priority queue constructor
* `pq(comp)`: comp, the comparing function as the parameter of the constructor of the priority queue.

### constructor in structures
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


