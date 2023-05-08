# Answer the boss!
Eloy is a hard worker man, however, he is constantly bullied by his superiors, molested by this, one day he was wondering in what "rank" you are, so you can bully the people with lower ranks, also to discover who can really bully Eloy!.

Now, given the number of employees and the number of relations between them, Eloy need you to output the "rank" which employee is in, being 1 the "boss" (not bullied by anybody) and the employee who are in these ranks

# Input Format
There will be an integer `T` denoting the test cases, then, `T` test cases will follow, each test case starts with two integers `N` and `R`, the number of employees and the number of relations between them, the next `R` lines consists in two integers `R1` and `R2`, meaning that "employee R1 is lower than employee R2's rank".

Constraints 1 <= N <= 1000; 1 <= R <= 10000

# Output Format
You will output for each test case the string "Scenario #i:" where `i` is the test case you are analyzing, after that, you will print `N` lines, for each line you will output the rank of the employee and the employee itself, if there is the same rank for several employees, then output them lexicographically ordered (the first is the lower).

# Sample test
```
2
5 6
2 0
2 4
1 4
1 2
3 2
4 0
5 4
1 0
2 0
3 2
4 2

Scenario #1:
1 0
2 4
3 2
4 1
4 3
Scenario #2:
1 0
2 1
2 2
3 3
3 4
```
