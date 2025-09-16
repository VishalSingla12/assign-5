# UCS301 Data Structures  
## Lab Assignment 5: Single Linked List 

---

### **Q1: Menu-driven program on Singly Linked List**
Operations:
- Insert at beginning, end, or between nodes  
- Delete from beginning, end, or specific node  
- Search for node and display position  
- Display all nodes  

**Sample Output:**
```

PS C:\Users\visha\OneDrive\Desktop\assign_5> cd "c:\Users\visha\OneDrive\Desktop\assign_5\" ; if ($?) { g++ aq1.cpp -o aq1 } ; if ($?) { .\aq1 }
menu
1. Insert at beginning
2. Insert at end
3. Insert before a value
4. Insert after a value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search node
9. Display list
0. Exit
Enter your choice: 1
Enter value to insert: 11
Inserted 11 at beginning
menu
1. Insert at beginning
2. Insert at end
3. Insert before a value
4. Insert after a value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search node
9. Display list
0. Exit
Enter your choice: 2
Enter value to insert: 12
Inserted 12 at end
menu
1. Insert at beginning
2. Insert at end
3. Insert before a value
4. Insert after a value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search node
9. Display list
0. Exit
Enter your choice: 9
List: 11 -> 12 -> NULL
menu
1. Insert at beginning
2. Insert at end
3. Insert before a value
4. Insert after a value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search node
9. Display list
0. Exit
Enter your choice: 0
Exiting program...

```

---

### **Q2: Count and Delete Occurrences of a Key**
Count frequency of a key and delete all its occurrences.  

```

**Output:**

PS C:\Users\visha\OneDrive\Desktop\assign_5> cd "c:\Users\visha\OneDrive\Desktop\assign_5\" ; if ($?) { g++ aq2.cpp -o aq2 } ; if ($?) { .\aq2 }
Creating list: 1->2->1->2->1->3->1
Original Linked List: 1->2->1->2->1->3->1

Searching for key: 1
Count: 4
Updated Linked List: 2->2->3
Enter number of elements: 5
Enter elements: 1 2 3 4 5
Your list: 1->2->3->4->5
Enter key to count and delete: 4
Count: 1
Updated Linked List: 1->2->3->5
```

---

### **Q3: Find Middle of Linked List**
Find middle node using two-pointer (slow & fast).  


```

**Output:**
PS C:\Users\visha\OneDrive\Desktop\assign_5> cd "c:\Users\visha\OneDrive\Desktop\assign_5\" ; if ($?) { g++ aq3.cpp -o aq3 } ; if ($?) { .\aq3 }
Enter number of elements: 5
Enter elements: 1 2 3 4 5
Your list: 1->2->3->4->5
Middle element: 3

```

---

### **Q4: Reverse a Linked List**
Reverse linked list iteratively or recursively.  

```

**Output:**


PS C:\Users\visha\OneDrive\Desktop\assign_5> cd "c:\Users\visha\OneDrive\Desktop\assign_5\" ; if ($?) { g++ aq4.cpp -o aq4 } ; if ($?) { .\aq4 }
Original list: 1 2 3 4 5 
Reversed list: 5 4 3 2 1


```

---

