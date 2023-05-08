# Beverages
Dilbert has just finished college and decided to go out with friends. Dilbert has some strange habits and thus he decided to celebrate this important moment of his life drinking a lot. He will start drinking beverages with low alcohol content, like beer, and then will move to a beverage that contains more alcohol, like wine, until there are no more available beverages. Once Dilbert starts to drink wine he will not drink beer again, so the alcohol content of the beverages never decreases with the time.

You should help Dilbert by indicating an order in which he can drink the beverages in the way he wishes

# Input
Each test case starts with `1 <= N <= 100`, the number of available beverages. Then will follow `N` lines, informing the name of each beverage, a name has less than 51 characters and has no white spaces. Then there is another line with an integer `0<=M<=200` and `M` lines in the form `B1 B2` will follow, indicating that beverage `B2` has more alcohol that beverage `B1`, so Dilbert should drink beverage `B1` before he starts drinking beverage  `B2`. Be sure that this relation is transitive, so if there is also a relation  `B2 B3` you should drink `B1` before you can drink `B3`. There is a blank line after each test case. In the case there is no relation between two beverages Dilbert should start drinking the one that appears first in the input. The input is terminated by end of file (EOF).

# Output
For each test case you must print the message: `Case #C: Dilbert should drink beverages in this order: B1 B2 . . . BN .`, where  `C` is the number of the test case, starting from 1, and `B1 B2 . . . BN` is a list of the beverages such that the alcohol content of beverage `B[i+1]`​​  is not less than the alcohol content of beverage `B[i−1]`​​ . After each test case you must print a blank line.

# Sample Test
```
3
vodka
wine
beer
2
wine vodka
beer wine

5
wine
beer
rum
apple-juice
cachaca
6
beer cachaca
apple-juice beer
apple-juice rum
beer rum
beer wine
wine cachaca

10
cachaca
rum
apple-juice
tequila
whiskey
wine
vodka
beer
martini
gin
11
beer whiskey
apple-juice gin
rum cachaca
vodka tequila
apple-juice martini
rum gin
wine whiskey
apple-juice beer
beer rum
wine vodka
beer tequila

Output:
Case #1: Dilbert should drink beverages in this order: beer wine vodka.

Case #2: Dilbert should drink beverages in this order: apple-juice beer wine rum cachaca.

Case #3: Dilbert should drink beverages in this order: apple-juice wine vodka beer rum cachaca tequila whiskey martini gin.
```
