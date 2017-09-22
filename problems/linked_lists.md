# Linked list problems

## Read-only Problems

### Find an element in a list
Just iterate through the list looking for the element:
```python
node_type find(node_type head, value_type value):
1   node = head
2   while (node != NULL):
3       if node.val == value:
4           return node
5       node = node.next
6   return NULL
```

### Find the length of a list
Iterate through the entire list and count the number of nodes:
```python
int find(node_type head):
1   node = head
2   count = 0
3   while (node != NULL):
4       count = count + 1
5       node = node.next
6   return count
```

### Find the `k`-th node in the list
Advance `k` nodes in the list:
```python
node_type find_kth(node_type head, int k):
1   node = head
2   count = 0
3   while (node != NULL and count < k):
4       count = count + 1
5       node = node.next
6   return node
```

### Find the middle node of a list
Use `slow` and `fast` iterators such that the `fast` iterator moves at twice the speed of the `slow` iterator:
```python
node_type find_mid(node_type head):
1   slow = fast = head
2   while (fast != NULL and fast.next != NULL):
3       slow = node.next
4       fast = fast.next.next
5   return slow
```

### Find the `k`-th last node from the list
Use `leader` and `follower` iterators such that 'leader' iterator is `k` steps ahead of the `follower` iterator:
```python
node_type find_kth_last(node_type head, int k):
 1  leader = head
 2  count = 0
 3  while (leader != NULL and count < k):
 4      count = count + 1
 5      leader = leader.next
 6  follower = head
 7  while (leader != NULL):
 8      leader = leader.next
 9      follower = follower.next
10  return follower
```

### Determine if a list has a cycle

#### Variant: Find the intersecting node

### Determine if two lists intersect

#### Variant: What if there is a cycle?

## Write/Modify Problems

General tips
* Use a terminal/sentinel node for all the problems where the original list head may not be the new list head

### Insert/delete an element into/from a list

### Remove the `k`-th node from the list

### Remove the middle node from a list

### Remove the `k`-th last node from the list

### Remove multiple elements from a list

### Reverse a list

#### Variant: Reverse a sublist

### Determine if a list is palindromic

### Uniquify the successively repeating elements in a list
**_Note that if the list is sorted, it uniquifies the list_**

### Remove duplicate items from a list

### Rotate a list (by `0 < k < n`, `n` is the length of the list, nodes)

#### Variant: `0 < k`

### Splice a list in another list

#### Variant: Splice part of a list in another list

### Merge two sorted lists

### Interleave two lists 

### Split a list into two lists -- one with odd numbered nodes and the other with the rest of the nodes

### Partition a list

## Copy Problems

### Deep clone a list

### Increment arbitrary length number

### Add two arbitrary length numbers




