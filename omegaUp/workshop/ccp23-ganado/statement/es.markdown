# Description

There are $M$ pastures, owned by rancher $r_1, r_2, … r_M$, respectively. Given a chart showing how the herds are split up on each pasture. Please find which owner has the maximum number of animals in total, and the type of animal that has the maximum number of members across all pastures. If there's a tie for the owner, print the first owner's name (i.e. the owner that is on the highest row of the chart). If there's a tie for the type of animal, print the first type of animal (i.e. the type of animal that is the left-most in the chart).

# Input

- $1 \le M, N \le 100$
- On the first line the $N$ types of animals separated by a single space
  - Each type of animal is a single word using letters (`A-Z` and `a-z`)
  - Each word is less than 20 chars long
- $M$ lines representing the $M$ owners
  - Each line will list the name of the pasture owner and the $N$ number of animals they own for each type. Separated by a space.
    - Each owner name is a single word using lowercase letters (`A-Z` and `a-z`)
    - Each word is less than 20 chars long
    - No one owns more than 1000 animals of a given type

# Output

- In the first line, name of the pasture owner who owns the maximum number of animals in total
- In the second line, name the type of animal that has the maximum number of members across all pastures

# Example

||input
Vaca Oveja
Alicia 5 10
Benito 8 9
||output
Benito
Oveja
||description
Alicia owns 15 animals in total
Benito owns 17 animals in total
Benito owns the maximum number of animals
There are 13 members of Vaca across all pastures
There are 19 members of Oveja across all pastures
Oveja has the largest number of members
||input
Vaca Oveja Ternera Cerdo Cabra
Alicia 21 34 5 19 8
Benito 0 9 50 6 0
Carla 19 7 41 0 29
||output
Carla
Ternera
||description
Alicia owns 87 animals in total
Benito owns 65 animals in total
Carla owns 96 animals in total
Carla owns the maximum number of animals
There are 40 members of Vaca across all pastures
There are 50 members of Oveja across all pastures
There are 96 members of Ternera across all pastures
There are 25 members of Cerdo across all pastures
There are 37 members of Cabra across all pastures
Ternera has the largest number of members
||end
