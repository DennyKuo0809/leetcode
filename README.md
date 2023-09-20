
### Array and String
* KMP algorithm
   * 28 Find the Index of the First Occurrence in a String
* Boyer–Moore majority vote algorithm
   * 229 Majority Element II

### Link List
* Fast slow pointer

### Graph
* Euler Path / Cycle
  * 332. Reconstruct Itinerary

### DP
* Backpack Problem (select / not select)

## C++ cheat sheet
### lambda function for compare
```
sort(vec.begin(), vec.end(), [&](const A& a, const A& b) {return a > b});
```
### `upper_bound`, `lower_bound`
```
auto it = upper_bound(vec.begin(), vec.end(), element);
auto it = lower_bound(vec.begin(), vec.end(), element);
```
